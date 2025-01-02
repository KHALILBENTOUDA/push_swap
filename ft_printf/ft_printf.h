/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 13:03:31 by kben-tou          #+#    #+#             */
/*   Updated: 2024/11/19 09:41:51 by kben-tou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_printf_char(char c, int *char_counter);
int		ft_printf_str(char *str, int *char_counter);
int		ft_printf_number(int n, int *char_counter);
int		ft_printf_unsigned(unsigned int nb, int *char_counter);
int		ft_printf_pointer(void *p, int *char_counter);
int		ft_print_hex(unsigned long num, int *char_counter, int isupper);

#endif
