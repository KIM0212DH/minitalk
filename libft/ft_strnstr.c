/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokim2 <dokim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 13:46:17 by dokim2            #+#    #+#             */
/*   Updated: 2022/03/24 12:00:06 by dokim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char	*haystack, const char	*needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return ((char *) haystack);
	while (haystack[i] != '\0' && j < len)
	{
		j = 0;
		while (needle[j] != '\0' && i + j < len)
		{
			if (haystack[i + j] == needle[j])
				j++;
			else
				break ;
			if (needle[j] == '\0')
				return ((char *)(&haystack[i]));
		}
		i++;
	}
	return (0);
}
