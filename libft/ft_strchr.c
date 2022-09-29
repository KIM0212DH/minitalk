/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokim2 <dokim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:18:14 by dokim2            #+#    #+#             */
/*   Updated: 2022/04/01 14:36:57 by dokim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	temp;
	int		i;

	temp = (unsigned char) c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == temp)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == temp)
		return ((char *)&s[i]);
	return (0);
}
