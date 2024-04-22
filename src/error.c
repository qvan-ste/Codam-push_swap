/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/04/15 14:22:34 by qvan-ste      #+#    #+#                 */
/*   Updated: 2024/04/17 12:28:18 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <limits.h>

int	error(void)
{
	ft_printf_fd(2, "Error\n");
	return (1);
}

int	check_num(char *argv[])
{
	int			i;
	int			j;
	long long	num;

	i = 1;
	j = 0;
	while (argv[i])
	{
		if ((argv[i][0] == '-' || argv[i][0] == '+') && ft_strlen(argv[i]) > 1)
			j++;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (1);
			j++;
		}
		num = ft_atoll(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (1);
		i++;
		j = 0;
	}
	return (0);
}

int	check_dup(t_listdoub *head)
{
	int			head_val;
	t_listdoub	*tmp_head;

	while (head)
	{
		head_val = head -> val;
		tmp_head = head -> next;
		while (tmp_head)
		{
			if (tmp_head -> val == head_val)
				return (1);
			tmp_head = tmp_head -> next;
		}
		head = head -> next;
	}
	return (0);
}
