/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokim2 <dokim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 12:03:41 by dokim2            #+#    #+#             */
/*   Updated: 2022/05/16 18:23:52 by dokim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strndup(const char *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = NULL;
	if (n == 0)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (n + 1));
	if (str == 0)
		return (NULL);
	else
		ft_memset(str, 0, n);
	while (i < n)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	**ft_freeall(char **list)
{
	size_t	j;

	j = 0;
	while (list[j])
	{
		free(list[j]);
		j++;
	}
	free(list);
	return (NULL);
}

static size_t	ft_wordcount(char const *s, char c)
{
	size_t	word_count;
	size_t	i;

	i = 0;
	word_count = 0;
	while (s[i] != '\0')
	{
		if ((i == 0 && s[i] != c)
			|| (s[i] == c && s[i + 1] != '\0' && s[i + 1] != c))
			word_count++;
		i++;
	}
	return (word_count);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	size_t	i;
	size_t	k;
	size_t	save;

	i = 0;
	k = 0;
	if (s == 0)
		return (0);
	ret = (char **)malloc(sizeof(char *) * (ft_wordcount(s, c) + 1));
	if (!ret)
		return (NULL);
	while (i < ft_wordcount(s, c) && s[k] != '\0')
	{
		while (s[k] == c)
			k++;
		save = k;
		while (s[k] != c && s[k] != '\0')
			k++;
		ret[i] = ft_strndup(&s[save], k - save);
		if (ret[i++] == 0)
			return (ft_freeall(ret));
	}
	ret[i] = 0;
	return (ret);
}
