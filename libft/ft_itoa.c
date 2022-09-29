/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokim2 <dokim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:55:14 by dokim2            #+#    #+#             */
/*   Updated: 2022/03/30 14:04:12 by dokim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_digits(int n)
{
	size_t	ret;
	long	num;

	num = (long) n;
	ret = 0;
	if (num <= 0)
	{
		ret++;
		num = -num;
	}
	while (num > 0)
	{
		ret++;
		num = num / 10;
	}
	return (ret);
}

char	*ft_itoa(int n)
{
	char	*ret;
	size_t	len;
	long	num;

	num = (long) n;
	len = get_digits(n);
	ret = (char *) malloc (sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	ret[len--] = '\0';
	if (num < 0)
	{
		ret[0] = '-';
		num = -num;
	}
	if (num == 0)
		ret[0] = '0';
	while (num > 0)
	{
		ret[len--] = num % 10 + '0';
		num = num / 10;
	}
	return (ret);
}
