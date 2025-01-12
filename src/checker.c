/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 13:43:14 by kben-tou          #+#    #+#             */
/*   Updated: 2025/01/12 22:21:57 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void execute(t_stack **a, t_stack **b, char *command)
{
    if (!(*b || *a || command))
        ft_exit();
    if (ft_strncmp(command, "ra\n", ft_strlen(command)) == 0)
        ra(a);
    else if (ft_strncmp(command, "rra\n", ft_strlen(command)) == 0)
        rra(a);
    else if (ft_strncmp(command, "rb\n", ft_strlen(command)) == 0)
        rb(b);
    else if (ft_strncmp(command, "sa\n", ft_strlen(command)) == 0)
        sa(a);
    else if (ft_strncmp(command, "sb\n", ft_strlen(command)) == 0)
        sb(b);
    else if (ft_strncmp(command, "rrb\n", ft_strlen(command)) == 0)
        rrb(b);
    else if (ft_strncmp(command, "rr\n", ft_strlen(command)) == 0)
        rr(b, a);
    else if (ft_strncmp(command, "rrr\n", ft_strlen(command)) == 0)
        rrr(b, a);
    else if (ft_strncmp(command, "pa\n", ft_strlen(command)) == 0)
        pa(a, b);
    else if (ft_strncmp(command, "pb\n", ft_strlen(command)) == 0)
        pb(a, b);
    else
        ft_exit();
}

int main(int ac, char **av)
{
    t_stack *a;
    t_stack *b;
    char *line;
    int i;

    i = 0;
    if (ac < 2)
        return (0);
    av = check_input(av, ac);
    fill_stack(&a, av, ac);
    while (i++ >= 0)
    {
        line = get_next_line(0);
        if (!line)
            break ;
        execute(&a, &b, line);
        free(line);
    }
    if (is_stack_sorted(&a))
        write(1,"KO\n",3);
    else
        write(1,"OK\n",3);
    ft_free_stack(&a);
    ft_free_stack(&b);
    return (0);
} 
