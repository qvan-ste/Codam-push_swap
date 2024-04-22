/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calculate.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/10 17:52:25 by qvan-ste      #+#    #+#                 */
/*   Updated: 2024/04/17 11:06:20 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	calculate_ra(int value, t_listdoub *stack)
{
	int	rotations;
	int	max;
	int	next;

	rotations = 0;
	max = stack_max(stack);
	next = check_next_val(value, stack);
	while (stack)
	{
		if (value > max)
		{
			while (stack -> val != stack_min(stack))
			{
				rotations++;
				stack = stack -> next;
			}
			return (rotations);
		}
		if (stack -> val == next)
			break ;
		rotations++;
		stack = stack -> next;
	}
	return (rotations);
}

int	calculate_rb(int value, t_listdoub *stack)
{
	int	rotations;
	int	min;

	rotations = 0;
	min = stack_min(stack);
	while (stack)
	{
		if (value < min)
		{
			while (stack -> val != stack_max(stack))
			{
				rotations++;
				stack = stack -> next;
			}
			return (rotations);
		}
		if (stack -> val == check_prev_val(value, stack))
			break ;
		rotations++;
		stack = stack -> next;
	}
	return (rotations);
}

t_move	*calculate_move_tob(t_listdoub *a, t_listdoub *b,
		int a_size, int b_size)
{
	t_move	*move;
	t_move	*optimal_move;
	int		ra_cost;

	ra_cost = 0;
	optimal_move = init_move(a_size, b_size,
			ra_cost, calculate_rb(a -> val, b));
	if (!optimal_move)
		return (NULL);
	while (a)
	{
		move = init_move(a_size, b_size, ra_cost, calculate_rb(a -> val, b));
		if (!move)
			return (NULL);
		if (move -> total_cost < optimal_move -> total_cost)
		{
			free(optimal_move);
			optimal_move = move;
		}
		else
			free(move);
		ra_cost++;
		a = a -> next;
	}
	return (optimal_move);
}

t_move	*calculate_move_toa(t_listdoub *a, t_listdoub *b,
		int a_size, int b_size)
{
	t_move	*move;
	t_move	*optimal_move;
	int		rb_cost;

	rb_cost = 0;
	optimal_move = init_move(a_size, b_size,
			calculate_ra(b -> val, a), rb_cost);
	if (!optimal_move)
		return (NULL);
	while (b)
	{
		move = init_move(a_size, b_size, calculate_ra(b -> val, a), rb_cost);
		if (!move)
			return (NULL);
		if (move -> total_cost < optimal_move -> total_cost)
		{
			free(optimal_move);
			optimal_move = move;
		}
		if (optimal_move != move)
			free(move);
		rb_cost++;
		b = b -> next;
	}
	return (optimal_move);
}
