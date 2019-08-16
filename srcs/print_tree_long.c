#include "ft_ls.h"
#include "ft_ls_util.h"
#include "../libft/includes/libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <grp.h>
#include <pwd.h>
#include <time.h>
#include <stdlib.h>
#include <sys/xattr.h>
#include <sys/acl.h>

void	print_linkname(t_tree *t)
{
	char	*ln;

	if(!(ln = malloc(t->stat->st_size + 1)))
		exit(1);
	readlink(t->path, ln, t->stat->st_size + 1);
	ln[t->stat->st_size] = 0;
	ft_printf_m(" -> %s", ln);
	free(ln);
}

char	get_type_char(t_tree *t)
{
	if (S_ISDIR(t->stat->st_mode))
		return 'd';
	else if (S_ISCHR(t->stat->st_mode))
		return 'c';
	else if (S_ISFIFO(t->stat->st_mode))
		return 'p';
	else if (S_ISLNK(t->stat->st_mode))
		return 'l';
	else if (S_ISSOCK(t->stat->st_mode))
		return 's';
	return '-';
}

void	print_permissions(t_tree *t)
{
	const char	perm[] = "rwxrwxrwx";
	int			i;
	acl_t		acl;

	ft_printf_m("%c", get_type_char(t));
	i = 0;
	while (i < 9)
	{
		if (i == 2 && (t->stat->st_mode & S_ISUID))
			ft_printf_m("%c", (t->stat->st_mode & (1 << (8 - i))) ? 's' : 'S');
		else if (i == 5 && (t->stat->st_mode & S_ISGID))
			ft_printf_m("%c", (t->stat->st_mode & (1 << (8 - i))) ? 's' : 'S');
		else if (i == 8 && (t->stat->st_mode & S_ISVTX))
			ft_printf_m("%c", (t->stat->st_mode & (1 << (8 - i))) ? 't' : 'T');
		else
			ft_printf_m("%c", (t->stat->st_mode & (1 << (8 - i))) ? perm[i] : '-');
		i++;
	}
	acl = acl_get_link_np(t->path, ACL_TYPE_EXTENDED);
	if (listxattr(t->path, 0, 0, XATTR_NOFOLLOW) > 0)
		ft_printf_m("@");
	else if (acl)
	{
		ft_printf_m("+");
		acl_free(acl);
	}
	else
		ft_printf_m(" ");
}

void	print_usr_grp(t_tree *t, size_t max_usr, size_t max_grp)
{
	struct passwd	*pw;
	struct group	*grg;

	pw = getpwuid(t->stat->st_uid);
	grg = getgrgid(t->stat->st_gid);
	if (g_flags.numerical || !pw)
		ft_printf_m(" %i%b", t->stat->st_uid, max_usr - get_intmax(t->stat->st_uid, 0));
	else
		ft_printf_m(" %s%b", pw->pw_name, max_usr - ft_strlen(pw->pw_name));
	if (!g_flags.omit_group)
	{
		if  (g_flags.numerical || !pw)
			ft_printf_m(" %i%b", t->stat->st_gid
					, max_grp - get_intmax(t->stat->st_gid, 0));
		else
			ft_printf_m(" %s%b", grg->gr_name, max_grp - ft_strlen(grg->gr_name));
	}
}

void	print_filesize(t_tree *t, size_t max)
{
	const char factor[] = "BKMG";
	int		pot;
	double	size;

	if (get_type(&t->stat) == 5 || get_type(&t->stat) == 6)
	{
		ft_printf("%*s%4i,%4i", max - 9,"",t->stat->st_rdev >> 24, t->stat->st_rdev % 4194304);
		return ;
	}
	pot = 0;
	size = (double)t->stat->st_size;
	if (g_flags.human)
	{
		while (size >= 1000.0)
		{
			size /= 1000.0;
			pot++;
		}
		if (size>= 10.0)
			ft_printf_m("%b%i%c", 5 - get_intmax(size, 0), (int)size,factor[pot]);
		else
			ft_printf_m(" %2i.%i%c",(int)size,((((int)(size * 10)) / 10.0) - (int)size) / 10, factor[pot]);
	}
	else
	{
		ft_printf_m("%b%i", max - get_intmax(t->stat->st_size, 0), t->stat->st_size);
	}
}

void	print_date(t_tree *t)
{
	time_t	*tim;
	time_t	now;

	if (g_flags.time == MOD)
		tim = &t->stat->st_mtimespec.tv_sec;
	else if (g_flags.time == ACCESS)
		tim = &t->stat->st_atimespec.tv_sec;
	else if (g_flags.time == CREATE)
		tim = &t->stat->st_birthtimespec.tv_sec;
	now = time(NULL);
	if (g_flags.complete_time)
		ft_printf_m(" %C%s", 20, ctime(tim) + 4);
	else if (now - 15552000 > *tim || now + 15552000 < *tim)
		ft_printf_m(" %C%s  %C%s", 6, ctime(tim) + 4, 4, ctime(tim) + 20);
	else
		ft_printf_m(" %C%s", 12, ctime(tim) + 4);
}

void	print_xattr(t_tree *t)
{
	int			size;
	char		*buf;
	size_t		s_v;
	int			count;

	if (g_flags.extended && (size = listxattr(t->path, 0, 0, XATTR_NOFOLLOW)) > 0)
	{
		count = 0;
		buf = malloc(sizeof(char *) * size);
		listxattr(t->path, buf, size, XATTR_NOFOLLOW);
		while (count < size)
		{
			s_v = getxattr(t->path, buf, 0, 0, 0, XATTR_NOFOLLOW);
			ft_printf_m("\t%s\t%b%i \n", buf, 4 - get_intmax(s_v, 0), s_v);
			count += ft_strlen(buf) + 1;
			buf += ft_strlen(buf) + 1;

		}
	}
}

void	print_tree_long(t_tree *t, t_tree_list *p)
{
	t_linfo		info;

	collect_info(&info, p);
	if (!g_flags.lonely)
		ft_printf_m("total %i\n", info.total);
	while (p)
	{
		print_permissions(p->tree);
		ft_printf_m("%b%i",info.max_links - get_intmax(p->tree->stat->st_nlink, 0), p->tree->stat->st_nlink);
		print_usr_grp(p->tree, info.max_usr, info.max_grp);
		print_filesize(p->tree, info.max_size);
		print_date(p->tree);
		ft_printf_m(" ");
		print_name(p->tree, 0);
		if (S_ISLNK(p->tree->stat->st_mode))
			print_linkname(p->tree);
		ft_printf_m("\n");
		print_xattr(p->tree);
		p = p->next;
	}

}
