/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokim2 <dokim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 18:05:43 by dokim2            #+#    #+#             */
/*   Updated: 2022/05/16 18:13:09 by dokim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*cur;
	t_list	*new;

	ret = 0;
	if (!lst || !f)
		return (0);
	ret = ft_lstnew(f(lst->content));
	if (!ret)
		return (0);
	cur = ret;
	lst = lst->next;
	while (lst != 0)
	{
		new = ft_lstnew(f(lst->content));
		if (!new)
		{
			ft_lstclear(&ret, del);
			return ((void *)(0));
		}
		cur->next = new;
		cur = new;
		lst = lst->next;
	}
	return (ret);
}
