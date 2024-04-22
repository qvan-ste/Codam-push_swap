/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/18 19:12:24 by qvan-ste      #+#    #+#                 */
/*   Updated: 2024/04/15 20:59:44 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_a(t_listdoub **a, t_listdoub **b)
{
	t_listdoub	*tmp;

	if (!(*b))
		return ;
	tmp = (*b)-> next;
	ft_lstdoubadd_front(a, *b);
	*b = tmp;
	if (*b)
		(*b)-> prev = NULL;
	ft_printf("pa\n");
}

void	push_b(t_listdoub **a, t_listdoub **b)
{
	t_listdoub	*tmp;

	if (!(*a))
		return ;
	tmp = (*a)-> next;
	ft_lstdoubadd_front(b, *a);
	*a = tmp;
	if (*a)
		(*a)-> prev = NULL;
	ft_printf("pb\n");
}

void	swap_a(t_listdoub **head)
{
	int	tmp;

	if (!head || !(*head)-> next)
		return ;
	tmp = (*head)-> val;
	(*head)-> val = (*head)-> next -> val;
	(*head)-> next -> val = tmp;
	ft_printf("sa\n");
}

void	swap_b(t_listdoub **head)
{
	int	tmp;

	if (!head || !(*head)-> next)
		return ;
	tmp = (*head)-> val;
	(*head)-> val = (*head)-> next -> val;
	(*head)-> next -> val = tmp;
	ft_printf("sb\n");
}
