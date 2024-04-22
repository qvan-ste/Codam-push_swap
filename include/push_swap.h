/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: qvan-ste <qvan-ste@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/18 14:38:37 by qvan-ste      #+#    #+#                 */
/*   Updated: 2024/04/17 11:48:43 by qvan-ste      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/includes/libft.h"

typedef struct s_listdoub
{
	int					val;
	struct s_listdoub	*prev;
	struct s_listdoub	*next;
}	t_listdoub;

typedef struct s_move
{
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	pa;
	int	pb;
	int	total_cost;
}	t_move;

t_listdoub	*init_stack_a(char *argv[]);
t_move		*init_move(int a_size, int b_size, int ra_cost, int rb_cost);
t_listdoub	*ft_lstdoubnew(int val);
t_listdoub	*ft_lstdoublast(t_listdoub *lst);
t_move		*calculate_move_toa(t_listdoub *a, t_listdoub *b,
				int a_size, int b_size);
t_move		*calculate_move_tob(t_listdoub *a, t_listdoub *b,
				int a_size, int b_size);
int			calculate_ra(int value, t_listdoub *a);
int			calculate_rb(int value, t_listdoub *b);
void		ft_lstdoubadd_front(t_listdoub **lst, t_listdoub *new);
void		ft_lstdoubadd_back(t_listdoub **lst, t_listdoub *new);
int			ft_lstdoubsize(t_listdoub *lst);
void		make_move(t_listdoub **a, t_listdoub **b, t_move *move);
void		free_lstdoub(t_listdoub *head);
void		push_a(t_listdoub **a, t_listdoub **b);
void		push_b(t_listdoub **a, t_listdoub **b);
void		swap_a(t_listdoub **head);
void		swap_b(t_listdoub **head);
void		rotate_a(t_listdoub **a);
void		rotate_b(t_listdoub **b);
void		rotate_rotate(t_listdoub **a, t_listdoub **b);
void		reverse_rotate_a(t_listdoub	**a);
void		reverse_rotate_b(t_listdoub	**b);
void		reverse_rotate_rotate(t_listdoub **a, t_listdoub **b);
int			*init_tmp_arr(t_listdoub *lst, int size);
int			stack_max(t_listdoub *b);
int			stack_min(t_listdoub *b);
int			check_prev_val(int val, t_listdoub *b);
int			check_next_val(int val, t_listdoub *b);
int			sort_stack(t_listdoub **a, t_listdoub **b);
int			sort_three(t_listdoub **a);
int			sort_mult(t_listdoub **a, t_listdoub **b);
int			push_sort_a(t_listdoub **a, t_listdoub **b);
int			push_sort_b(t_listdoub **a, t_listdoub **b);
int			error(void);
int			check_num(char *argv[]);
int			check_dup(t_listdoub *head);
void		combine_rotate(t_move *move);
void		combine_reverse_rotate(t_move *move);
void		check_reverse(t_move *move, int a_size, int b_size);
void		print_stacks(t_listdoub *a, t_listdoub *b);

#endif