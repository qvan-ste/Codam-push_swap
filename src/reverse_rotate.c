/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   reverse_rotate.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/18 19:58:51 by qvan-ste      #+#    #+#                 */
/*   Updated: 2024/04/10 17:51:15 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	reverse_rotate_a(t_listdoub	**a)
{
	t_listdoub	*tmp;

	tmp = ft_lstdoublast(*a);
	ft_lstdoublast(*a)-> prev -> next = NULL;
	tmp -> next = *a;
	tmp -> prev = NULL;
	(*a)-> prev = tmp;
	*a = tmp;
	ft_printf("rra\n");
}

void	reverse_rotate_b(t_listdoub	**b)
{
	t_listdoub	*tmp;

	tmp = ft_lstdoublast(*b);
	ft_lstdoublast(*b)-> prev -> next = NULL;
	tmp -> next = *b;
	tmp -> prev = NULL;
	(*b)-> prev = tmp;
	*b = tmp;
	ft_printf("rrb\n");
}

void	reverse_rotate_rotate(t_listdoub **a, t_listdoub **b)
{
	t_listdoub	*tmp;

	tmp = ft_lstdoublast(*a);
	ft_lstdoublast(*a)-> prev -> next = NULL;
	tmp -> next = *a;
	tmp -> prev = NULL;
	(*a)-> prev = tmp;
	*a = tmp;
	tmp = ft_lstdoublast(*b);
	ft_lstdoublast(*b)-> prev -> next = NULL;
	tmp -> next = *b;
	tmp -> prev = NULL;
	(*b)-> prev = tmp;
	*b = tmp;
	ft_printf("rrr\n");
}
