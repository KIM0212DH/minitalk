/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokim2 <dokim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 22:42:27 by dokim2            #+#    #+#             */
/*   Updated: 2022/03/24 23:01:48 by dokim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	count;

	if (!s1 || !s2)
		return (0);
	count = ft_strlen(s1) + ft_strlen(s2);
	ret = (char *) malloc (sizeof(char) * (count + 1));
	if (!ret)
		return (0);
	ft_strlcpy(ret, s1, ft_strlen(s1) + 1);
	ft_strlcat(ret + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (ret);
}
