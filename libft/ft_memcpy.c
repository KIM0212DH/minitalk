/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokim2 <dokim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 13:48:35 by dokim2            #+#    #+#             */
/*   Updated: 2022/03/31 14:47:26 by dokim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void	*dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*t_dst;
	unsigned char	*s_dst;

	t_dst = (unsigned char *) dst;
	s_dst = (unsigned char *) src;
	i = 0;
	if (dst == src)
		return (dst);
	while (i < n)
	{
		t_dst[i] = s_dst[i];
		i++;
	}
	return (dst);
}
