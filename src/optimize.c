/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   optimize.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/10 19:15:32 by qvan-ste      #+#    #+#                 */
/*   Updated: 2024/04/10 19:18:27 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	combine_rotate(t_move *move)
{
	if (move -> ra >= 1 && move -> rb >= 1)
	{
		if (move -> ra >= move -> rb)
		{
			move -> rr = move -> rb;
			move -> ra = move -> ra - move -> rb;
			move -> rb = 0;
		}
		else
		{
			move -> rr = move -> ra;
			move -> rb = move -> rb - move -> ra;
			move -> ra = 0;
		}
	}
}

void	combine_reverse_rotate(t_move *move)
{
	if (move -> rra >= 1 && move -> rrb >= 1)
	{
		if (move -> rra >= move -> rrb)
		{
			move -> rrr = move -> rrb;
			move -> rra = move -> rra - move -> rrb;
			move -> rrb = 0;
		}
		else
		{
			move -> rrr = move -> rra;
			move -> rrb = move -> rrb - move -> rra;
			move -> rra = 0;
		}
	}
}

void	check_reverse(t_move *move, int a_size, int b_size)
{
	if (move -> ra > a_size / 2)
	{
		move -> rra = a_size - move ->ra;
		move -> ra = 0;
	}
	if (move -> rb > b_size / 2)
	{
		move -> rrb = b_size - move -> rb;
		move -> rb = 0;
	}
}
