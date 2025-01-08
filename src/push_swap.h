/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 12:36:32 by kben-tou          #+#    #+#             */
/*   Updated: 2025/01/08 10:48:51 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <libc.h>
#include "../ft_printf/ft_printf.h"
#include "../libft/libft.h"

typedef struct s_stack
{
    int top;
    int value;
    struct s_stack *next;
    struct s_stack *prev;

} t_stack;

void sa(t_stack **a);
void sb(t_stack **b);
void ss(t_stack **a, t_stack **b);
void pb(t_stack **a, t_stack **b);
void pa(t_stack **a, t_stack **b);
void ra(t_stack **a);
void rb(t_stack **a);
void rr(t_stack **b, t_stack **a);
void rra(t_stack **a);
void rrb(t_stack **b);
void rrr(t_stack **b, t_stack **a);

t_stack *get_last_node(t_stack *list);
char **check_input(char **inputs, int input_number);
void ft_exit();
void ft_free(char **content);
void ft_free_stack(t_stack **head);
long long_ft_atoi(const char *str);
int  is_stack_sorted(t_stack **a);
void sort_stack_a(t_stack **a, t_stack **b);
int stack_size(t_stack *a);
int *get_lis(t_stack **stack, int stack_len, int *lis_size);
t_stack *get_smallest_node(t_stack *a);
int turn_around(int stack_len, int index);


#endif