/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/18 14:35:16 by qvan-ste      #+#    #+#                 */
/*   Updated: 2024/04/17 15:34:53 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_lstdoub(t_listdoub *head)
{
	t_listdoub	*tmp;

	while (head)
	{
		tmp = head -> next;
		free(head);
		head = tmp;
	}
}

int	already_sorted(t_listdoub *head)
{
	while (head -> next)
	{
		if (head -> val > head -> next -> val)
			return (0);
		head = head -> next;
	}
	return (1);
}

t_listdoub	*init_stack_a(char *argv[])
{
	int			i;
	t_listdoub	*head;
	t_listdoub	*node;

	i = 2;
	head = ft_lstdoubnew(ft_atoi(argv[1]));
	if (!head)
		return (NULL);
	while (argv[i])
	{
		node = ft_lstdoubnew(ft_atoi(argv[i]));
		ft_lstdoubadd_back(&head, node);
		i++;
	}
	if (check_dup(head))
	{
		free_lstdoub(head);
		return (NULL);
	}
	if (already_sorted(head))
	{
		free_lstdoub(head);
		exit (0);
	}
	return (head);
}

int	main(int argc, char *argv[])
{
	t_listdoub	*a;
	t_listdoub	*b;
	int			err;

	if (argc == 1)
		return (1);
	if (check_num(argv))
		return (error());
	if (argc == 2)
	{
		if (ft_strlen(argv[1]) == 0)
			return (error());
		return (0);
	}
	a = init_stack_a(argv);
	if (!a)
		return (error());
	b = NULL;
	err = sort_stack(&a, &b);
	free_lstdoub(a);
	free_lstdoub(b);
	if (err)
		return (error());
	return (0);
}
