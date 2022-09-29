/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dokim2 <dokim2@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 20:17:09 by dokim2            #+#    #+#             */
/*   Updated: 2022/09/29 18:19:29 by dokim2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <signal.h>
# define MAX_PID    99998
# define MIN_PID    101

typedef struct s_info
{
	int	count;
	int	letter;
	int	sig_count;
	int	c_pid;
}	t_info;

#endif
