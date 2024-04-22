/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   double_linked.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/18 16:20:04 by qvan-ste      #+#    #+#                 */
/*   Updated: 2024/04/10 17:38:15 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_listdoub	*ft_lstdoubnew(int val)
{
	t_listdoub	*new;

	new = malloc(sizeof(t_listdoub));
	if (!new)
		return (NULL);
	new -> val = val;
	new -> prev = NULL;
	new -> next = NULL;
	return (new);
}

t_listdoub	*ft_lstdoublast(t_listdoub *lst)
{
	while (lst -> next)
		lst = lst -> next;
	return (lst);
}

void	ft_lstdoubadd_back(t_listdoub **lst, t_listdoub *new)
{
	t_listdoub	*last;

	last = ft_lstdoublast(*lst);
	last -> next = new;
	new -> prev = last;
}

void	ft_lstdoubadd_front(t_listdoub **lst, t_listdoub *new)
{
	new -> next = *lst;
	if (new -> next)
		new -> next -> prev = new;
	*lst = new;
}

int	ft_lstdoubsize(t_listdoub *lst)
{
	int	n;

	n = 0;
	while (lst)
	{
		lst = lst -> next;
		n++;
	}
	return (n);
}
