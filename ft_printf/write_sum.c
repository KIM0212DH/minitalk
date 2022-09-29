/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_sum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokim2 <dokim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 16:08:25 by dokim2            #+#    #+#             */
/*   Updated: 2022/08/14 23:03:39 by dokim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printfstr(int *count, char *vastr)
{
	if (vastr == NULL)
	{
		*count = *count + write(1, "(null)", 6);
		return ;
	}
	while (*vastr != '\0')
	{
		write(1, vastr, 1);
		*count = *count + 1;
		vastr++;
	}
}

void	ft_printfnbr_i(int *count, int vanum)
{
	long long	tmp;

	tmp = vanum;
	if (tmp < 0)
	{
		*count = *count + write(1, "-", 1);
		tmp = -tmp;
	}
	if (tmp >= 10)
	{
		ft_printfnbr_i(count, tmp / 10);
		*count = *count + write(1, &"0123456789"[tmp % 10], 1);
	}
	else
		*count = *count + write(1, &"0123456789"[tmp % 10], 1);
}

int	ft_printfnbr_u(int *count, unsigned int vauint)
{
	if (vauint >= 10)
	{
		ft_printfnbr_u(count, vauint / 10);
		*count = *count + write(1, &"0123456789"[vauint % 10], 1);
	}
	else
		*count = *count + write(1, &"0123456789"[vauint % 10], 1);
	return (*count);
}

void	ft_printf_x(char arg, int *count, unsigned int vauint)
{
	if (arg == 'x')
	{
		if (vauint >= 16)
		{
			ft_printf_x(arg, count, vauint / 16);
			*count = *count + write(1, &"0123456789abcdef"[vauint % 16], 1);
		}
		else
			*count = *count + write(1, &"0123456789abcdef"[vauint % 16], 1);
	}
	else
	{
		if (vauint >= 16)
		{
			ft_printf_x(arg, count, vauint / 16);
			*count = *count + write(1, &"0123456789ABCDEF"[vauint % 16], 1);
		}
		else
			*count = *count + write(1, &"0123456789ABCDEF"[vauint % 16], 1);
	}
}

void	ft_printf_p(int *count, unsigned long long vauint)
{
	if (vauint >= 16)
	{
		ft_printf_p(count, vauint / 16);
		*count = *count + write(1, &"0123456789abcdef"[vauint % 16], 1);
	}
	else
		*count = *count + write(1, &"0123456789abcdef"[vauint % 16], 1);
}
