/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/03 16:04:23 by qvan-ste      #+#    #+#                 */
/*   Updated: 2024/04/15 21:00:17 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	sort_stack(t_listdoub **a, t_listdoub **b)
{
	if (ft_lstdoubsize(*a) == 2)
	{
		if ((*a)-> val > (*a)-> next -> val)
			swap_a(a);
		return (0);
	}
	if (ft_lstdoubsize(*a) == 3)
		return (sort_three(a));
	else
		return (sort_mult(a, b));
}

int	sort_three(t_listdoub **a)
{
	int	*arr;

	arr = init_tmp_arr(*a, 3);
	if (!arr)
		return (1);
	if (arr[0] > arr[1] && arr[1] < arr[2] && arr[2] > arr[0])
		swap_a(a);
	else if (arr[0] > arr[1] && arr[1] > arr[2] && arr[2] < arr[0])
	{
		swap_a(a);
		reverse_rotate_a(a);
	}
	else if (arr[0] > arr[1] && arr[1] < arr[2] && arr[2] < arr[0])
		rotate_a(a);
	else if (arr[0] < arr[1] && arr[1] > arr[2] && arr[2] > arr[0])
	{
		swap_a(a);
		rotate_a(a);
	}
	else if (arr[0] < arr[1] && arr[1] > arr[2] && arr[2] < arr[0])
		reverse_rotate_a(a);
	free(arr);
	return (0);
}

int	push_sort_a(t_listdoub **a, t_listdoub **b)
{
	t_move	*move;
	int		a_size;
	int		b_size;

	a_size = ft_lstdoubsize(*a);
	b_size = ft_lstdoubsize(*b);
	move = calculate_move_toa(*a, *b, a_size, b_size);
	if (!move)
		return (1);
	move -> pa = 1;
	make_move(a, b, move);
	free(move);
	return (0);
}

int	push_sort_b(t_listdoub **a, t_listdoub **b)
{
	t_move	*move;
	int		a_size;
	int		b_size;

	a_size = ft_lstdoubsize(*a);
	b_size = ft_lstdoubsize(*b);
	move = calculate_move_tob(*a, *b, a_size, b_size);
	if (!move)
		return (1);
	move -> pb = 1;
	make_move(a, b, move);
	free(move);
	return (0);
}

int	sort_mult(t_listdoub **a, t_listdoub **b)
{
	int	err;

	err = 0;
	push_b(a, b);
	if (ft_lstdoubsize(*a) > 4)
		push_b(a, b);
	while (ft_lstdoubsize(*a) > 3)
	{
		err = push_sort_b(a, b);
		if (err)
			return (1);
	}
	sort_three(a);
	while (*b)
	{
		err = push_sort_a(a, b);
		if (err)
			return (1);
	}
	while ((*a)-> val != stack_min(*a))
		rotate_a(a);
	return (0);
}
