/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 12:36:32 by kben-tou          #+#    #+#             */
/*   Updated: 2025/01/03 21:11:15 by kben-tou         ###   ########.fr       */
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
void rra(t_stack **a);
void rrb(t_stack **b);
void rrr(t_stack **b, t_stack **a);

t_stack *get_last_node(t_stack *list);
void check_input(char **inputs, int input_number);
void ft_exit();



#endif