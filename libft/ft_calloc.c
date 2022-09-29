/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokim2 <dokim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:41:10 by dokim2            #+#    #+#             */
/*   Updated: 2022/04/04 17:52:36 by dokim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;

	if ((count != 0 && (count * size / count != size))
		|| (size != 0 && (count * size / size != count)))
		return (0);
	ret = (char *)malloc(count * size);
	if (!ret)
		return (0);
	ft_memset(ret, 0, (count * size));
	return (ret);
}
