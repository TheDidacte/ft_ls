
#include "ft_ls.h"
#include "ft_ls_util.h"

void	loop_and_print(t_b_tree *t)
{
	b_tree	*res;
	if (t->left)
		loop_and_print(t->left);
	if (t->is_dir)
	{
		res = create_b_tree(path);
		print_tree_aux(res);
		loop_and_print(res);
	}
	if (t->right)
		loop_and_print(t->left);
}

void	loop_and_print_start(int ac, char **av)
{
	t_tree		*res;
	int			i;
	t_tree_list *p;

	i = -1;
	if (!(res = (t_tree *)malloc(sizeof(t_tree))))
		exit(1);
	res->path = "main";
	res->children = 0;
	if (ac == 0)
		add_child(res, create_b_tree("."));
	while (++i < ac)
	{
		if (is_arg_valid(av[i]))
			add_child(res, create_b_tree(av[i]));
	}
	handle_lonely_files(res);
	p = res->children;
	while (p)
	{
		print_tree_aux(p->tree);
		p = p->next;
	}
	p = res->children;
	while (p)
	{
		if (p->b_tree)
			loop_and_print(p->tree);
		p = p->next;
	}
	return ;
}