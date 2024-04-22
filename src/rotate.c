/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/25 13:45:28 by qvan-ste      #+#    #+#                 */
/*   Updated: 2024/04/10 17:49:26 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate_a(t_listdoub **a)
{
	t_listdoub	*tmp;

	tmp = *a;
	*a = (*a)-> next;
	(*a)-> prev = NULL;
	tmp -> prev = ft_lstdoublast(*a);
	ft_lstdoublast(*a)-> next = tmp;
	tmp -> next = NULL;
	ft_printf("ra\n");
}

void	rotate_b(t_listdoub **b)
{
	t_listdoub	*tmp;

	tmp = *b;
	*b = (*b)-> next;
	(*b)-> prev = NULL;
	tmp -> prev = ft_lstdoublast(*b);
	ft_lstdoublast(*b)-> next = tmp;
	tmp -> next = NULL;
	ft_printf("rb\n");
}

void	rotate_rotate(t_listdoub **a, t_listdoub **b)
{
	t_listdoub	*tmp;

	tmp = *a;
	*a = (*a)-> next;
	(*a)-> prev = NULL;
	tmp -> prev = ft_lstdoublast(*a);
	ft_lstdoublast(*a)-> next = tmp;
	tmp -> next = NULL;
	tmp = *b;
	*b = (*b)-> next;
	(*b)-> prev = NULL;
	tmp -> prev = ft_lstdoublast(*b);
	ft_lstdoublast(*b)-> next = tmp;
	tmp -> next = NULL;
	ft_printf("rr\n");
}
