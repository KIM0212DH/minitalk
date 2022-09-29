/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokim2 <dokim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 10:57:11 by dokim2            #+#    #+#             */
/*   Updated: 2022/08/13 01:11:01 by dokim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *args, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, args);
	count = 0;
	while (*args != '\0')
	{
		if (*args == '%')
		{
			if (check_type(*(++args)))
				type_op(*args, &count, &ap);
			else
			{
				if (*args != '\0')
					count = count + write(1, args, 1);
				else
					args--;
			}
		}
		else
			count = count + write(1, args, 1);
		args++;
	}
	va_end(ap);
	return (count);
}
