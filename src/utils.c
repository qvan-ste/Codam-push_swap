/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/18 19:13:25 by qvan-ste      #+#    #+#                 */
/*   Updated: 2024/04/15 21:00:26 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// void	print_stacks(t_listdoub *a, t_listdoub *b)
// {
// 	while (a || b)
// 	{
// 		if (a)
// 		{
// 			ft_printf("%i\t", a -> val);
// 			a = a -> next;
// 		}
// 		else
// 			ft_printf(" \t");
// 		if (b)
// 		{
// 			ft_printf("%i", b -> val);
// 			b = b -> next;
// 		}
// 		ft_printf("\n");
// 	}
// 	ft_printf("-\t-\na\tb\n\n");
// }

int	*init_tmp_arr(t_listdoub *lst, int size)
{
	int	i;
	int	*arr;

	i = 0;
	arr = malloc (size * sizeof(int));
	if (!arr)
		return (NULL);
	while (i < size)
	{
		arr[i] = lst -> val;
		lst = lst -> next;
		i++;
	}
	return (arr);
}

int	stack_max(t_listdoub *b)
{
	int	tmp;

	tmp = b -> val;
	while (b)
	{
		if (b -> val > tmp)
			tmp = b -> val;
		b = b -> next;
	}
	return (tmp);
}

int	stack_min(t_listdoub *b)
{
	int	tmp;

	tmp = b -> val;
	while (b)
	{
		if (b -> val < tmp)
			tmp = b -> val;
		b = b -> next;
	}
	return (tmp);
}

int	check_prev_val(int val, t_listdoub *b)
{
	int	prev_val;

	prev_val = stack_min(b);
	while (b)
	{
		if (b -> val < val && b -> val > prev_val)
			prev_val = b -> val;
		b = b -> next;
	}
	return (prev_val);
}

int	check_next_val(int val, t_listdoub *b)
{
	int	next_val;

	next_val = stack_max(b);
	while (b)
	{
		if (b -> val > val && b -> val < next_val)
			next_val = b -> val;
		b = b -> next;
	}
	return (next_val);
}
