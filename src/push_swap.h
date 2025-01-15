/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 12:36:32 by kben-tou          #+#    #+#             */
/*   Updated: 2025/01/15 15:57:14 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

void	sa(t_stack **a, int checker);
void	sb(t_stack **b, int checker);
void	ss(t_stack **a, t_stack **b, int checker);
void	pb(t_stack **a, t_stack **b, int checker);
void	pa(t_stack **a, t_stack **b, int checker);
void	ra(t_stack **a, int checker);
void	rb(t_stack **a, int checker);
void	rr(t_stack **b, t_stack **a, int checker);
void	rra(t_stack **a, int checker);
void	rrb(t_stack **b, int checker);
void	rrr(t_stack **b, t_stack **a, int checker);
t_stack	*get_last_node(t_stack *list);
char	**check_input(char **inputs);
void	ft_exit(void);
void	ft_free(char **content);
void	ft_free_stack(t_stack **head);
long	long_ft_atoi(const char *str);
int		is_stack_sorted(t_stack **a);
void	sort_stack_a(t_stack **a, t_stack **b);
int		stack_size(t_stack *a);
int		*get_lis(t_stack *iter, int stack_len, int *lis_size);
t_stack	*get_smallest_node(t_stack *a);
int		turn_around(int stack_len, int index);
int		is_in_lis(int *lis, int lis_size, int nb);
int		get_min_index(int array[], int size);
int		get_index_node(t_stack *stack, int node_value);
void	to_array(int stack_len, t_stack *iter, int *temp_array);
void	sort_three(t_stack **a);
int		bigest_item(t_stack *a);
t_stack	*add_new_node(int content);
void	sort_four_five(t_stack **a, t_stack **b, int size_s);
void	fill_stack(t_stack **a, char **content);
char	*ft_strjoin_new(char *s1, char *s2);
char	*get_next_line(int fd);
int		next_number(t_stack *list, int nb_b, int size_a);
void	ft_rotate_b(t_stack **b, int nb_index, int nb_b);
void	ft_rotate_a(t_stack **a, int next_index, int next_nb);
void	check_s(char *str);

#endif
