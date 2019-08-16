

#include "ft_ls.h"
#include <stdlib.h>

void	free_tree(t_tree *t)
{
	t_tree_list	*p;
	p = t->children;
	while (p)
	{
		if (p->tree)
			free_tree(p->tree);
		p = p->next;
	}
	if (t)
		free(t);
}
