/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokim2 <dokim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:26:02 by dokim2            #+#    #+#             */
/*   Updated: 2022/05/16 18:11:01 by dokim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*ret;

	if (!lst)
		return (lst);
	ret = lst;
	while (ret != 0)
	{
		if (ret->next == 0)
			break ;
		ret = ret->next;
	}
	return (ret);
}
