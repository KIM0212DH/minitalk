/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokim2 <dokim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 17:20:46 by dokim2            #+#    #+#             */
/*   Updated: 2022/05/16 18:13:36 by dokim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		ret;
	t_list	*temp;

	ret = 0;
	temp = lst;
	while (temp != 0)
	{
		temp = temp->next;
		ret++;
	}
	return (ret);
}
