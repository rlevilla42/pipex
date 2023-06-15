/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlevilla <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:28:27 by rlevilla          #+#    #+#             */
/*   Updated: 2022/11/16 16:29:13 by rlevilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int	ft_strlen(char *str);
int	ft_putstr(char *str);
int	ft_intsize(int n);
int	ft_hexasize(unsigned long long n);
int	ft_printf_char(char c);
int	ft_printf_s(char *str);
int	ft_printf_int(int n);
int	ft_printf_u(unsigned int n);
int	ft_printf_x(unsigned long long int n, char *base);
int	ft_printf_majx(unsigned long long int n, char *base);
int	ft_printf_p(unsigned long long int n, char *base);
int	ft_printf(const char *format, ...);

#endif
