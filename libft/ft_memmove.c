/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokim2 <dokim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:47:59 by dokim2            #+#    #+#             */
/*   Updated: 2022/03/24 11:13:37 by dokim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*t_dst;
	unsigned char	*t_src;
	size_t			i;

	if (dst == 0 && src == 0)
		return (0);
	t_dst = (unsigned char *)dst;
	t_src = (unsigned char *)src;
	i = 0;
	while (i < len)
	{
		if (t_src > t_dst)
		{
			t_dst[i] = t_src[i];
			i++;
		}
		else
		{
			t_dst[len - 1 - i] = t_src[len - 1 - i];
			i++;
		}
	}
	return (t_dst);
}
