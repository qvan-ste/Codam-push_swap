/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   moves.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/03 16:56:28 by qvan-ste      #+#    #+#                 */
/*   Updated: 2024/04/15 21:01:09 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_move	*init_move(int a_size, int b_size, int ra_cost, int rb_cost)
{
	t_move	*move;

	move = malloc(sizeof(t_move));
	if (!move)
		return (NULL);
	ft_bzero(move, sizeof(t_move));
	move -> ra = ra_cost;
	move -> rb = rb_cost;
	check_reverse(move, a_size, b_size);
	combine_rotate(move);
	combine_reverse_rotate(move);
	move -> total_cost = move -> ra + move -> rb + move -> rra
		+ move -> rrb + move -> rr + move -> rrr;
	return (move);
}

void	make_move(t_listdoub **a, t_listdoub **b, t_move *move)
{
	int	i;

	i = 0;
	while (i++ < move -> rr)
		rotate_rotate(a, b);
	i = 0;
	while (i++ < move -> ra)
		rotate_a(a);
	i = 0;
	while (i++ < move -> rb)
		rotate_b(b);
	i = 0;
	while (i++ < move -> rra)
		reverse_rotate_a(a);
	i = 0;
	while (i++ < move -> rrb)
		reverse_rotate_b(b);
	i = 0;
	while (i++ < move -> rrr)
		reverse_rotate_rotate(a, b);
	if (move -> pa)
		push_a(a, b);
	else if (move -> pb)
		push_b(a, b);
}
