/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnduran <arnduran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 22:31:55 by arnduran          #+#    #+#             */
/*   Updated: 2023/10/03 20:04:21 by arnduran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <errno.h>

int	ft_atoi(const char *str)
{
	int		negatif;
	long	nb;
	long	max;

	negatif = 1;
	nb = 0;
	max = INT_MAX;
	while (*str == ' ' || (*str >= 8 && *str <= 13))
		str++;
	if (*str == '-')
		negatif = -1;
	if (negatif == -1)
		max++;
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str))
	{
		nb = nb * 10 + *str - '0';
		if (nb > max)
			errno = ERANGE;
		str++;
	}
	return (nb * negatif);
}
