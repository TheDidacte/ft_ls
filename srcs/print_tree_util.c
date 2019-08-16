#include <sys/types.h>
#include <grp.h>
#include <pwd.h>

#include "ft_ls.h"
#include "ft_ls_util.h"
#include "../libft/includes/libft.h"

size_t	get_intmax(int a, size_t b)
{
	size_t	c;

	c = 1;
	while (a >= 10)
	{
		a /= 10;
		c++;
	}
	if (c > b)
		return (c);
	return (b);
}

size_t	get_max_len(t_tree_list *p)
{
	size_t		max;
	size_t		cur;

	max = 0;
	while(p)
	{
		cur = g_flags.lonely ? ft_strlen(p->tree->path)
			: ft_strlen(ft_strrchr(p->tree->path, '/') + 1);
		if (cur > max)
			max = cur;
		p = p->next;
	}
	return (max);
}

size_t	get_strmax(char *a, size_t b)
{
	size_t len;

	len = ft_strlen(a);
	if (len > b)
		return (len);
	return (b);
}

void	collect_usr_grp(t_linfo *info, t_tree *t)
{
	struct passwd	*pw;
	struct group	*grg;
		
	pw = getpwuid(t->stat->st_uid);
	grg = getgrgid(t->stat->st_gid);

	if (g_flags.numerical || !pw)
		info->max_usr = get_intmax(t->stat->st_uid, info->max_usr);
	else
		info->max_usr = get_strmax(pw->pw_name, info->max_usr);
	if (!g_flags.omit_group)
	{
		if (g_flags.numerical || !grg)
			info->max_grp = get_intmax(t->stat->st_gid, info->max_grp);
		else
			info->max_grp = get_strmax(grg->gr_name, info->max_grp);
	}
}

void	collect_info(t_linfo *info, t_tree_list *p)
{
	bzero(info, sizeof(t_linfo));

	if (g_flags.human)
		info->max_size = 6;
	while (p)
	{
		info->b_c += p->tree->stat->st_blocks;
		info->max_links = get_intmax(p->tree->stat->st_nlink,info->max_links);
		collect_usr_grp(info, p->tree);
		info->total += p->tree->stat->st_blocks;
		if (!g_flags.human)
			info->max_size = get_intmax(p->tree->stat->st_size,info->max_size);
		if ((get_type(&p->tree->stat) == 5 || get_type(&p->tree->stat) == 6)
			&& info->max_size < 8)
			info->max_size = 8; 
		p = p->next;
	}
	info->max_links += 1;
	info->max_size += 1;
	info->max_usr += 1;
	info->max_grp += 1;

}
