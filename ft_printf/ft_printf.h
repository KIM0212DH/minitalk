/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokim2 <dokim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:18:00 by dokim2            #+#    #+#             */
/*   Updated: 2022/08/14 22:37:39 by dokim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define    FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *input, ...);
int		check_type(char n_arg);
void	type_op(char arg, int *count, va_list *ap);
void	ft_printfchar(int *count, unsigned char vachar);
void	ft_printfstr(int *count, char *vastr);
void	ft_printfnbr_i(int *count, int vanum);
int		ft_printfnbr_u(int *count, unsigned int vauint);
void	ft_printf_x(char arg, int *count, unsigned int vauint);
void	ft_printf_p(int *count, unsigned long long vauint);

#endif
