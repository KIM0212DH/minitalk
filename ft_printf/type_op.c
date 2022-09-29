/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokim2 <dokim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 15:47:50 by dokim2            #+#    #+#             */
/*   Updated: 2022/08/14 23:01:54 by dokim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	type_op(char arg, int *count, va_list *ap)
{
	char				vachar;
	unsigned long long	vaullong;

	if (arg == 'c')
	{
		vachar = (unsigned char) va_arg(*ap, int);
		*count = *count + write(1, &vachar, 1);
	}
	else if (arg == 's')
		ft_printfstr(count, (char *) va_arg(*ap, char *));
	else if (arg == 'i' || arg == 'd')
		ft_printfnbr_i(count, va_arg(*ap, int));
	else if (arg == 'u')
		ft_printfnbr_u(count, (unsigned int) va_arg(*ap, int));
	else if (arg == 'x' || arg == 'X')
		ft_printf_x(arg, count, (unsigned int) va_arg(*ap, int));
	else if (arg == 'p')
	{
		vaullong = (unsigned long long) va_arg(*ap, unsigned long long);
		*count = *count + write(1, "0x", 2);
		ft_printf_p(count, vaullong);
	}
}
