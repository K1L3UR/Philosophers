/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnduran <arnduran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 21:18:42 by arnduran          #+#    #+#             */
/*   Updated: 2023/10/08 17:19:53 by arnduran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_error(int er)
{
	if (er == 1)
	{
		printf("Error Args\n");
		return (0);
	}
	return (0);
}

void	*routine(t_philo *ptr_ph)
{
	//faire manger thinking dodo ?
}