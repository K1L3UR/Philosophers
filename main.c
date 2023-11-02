/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnduran <arnduran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:16:14 by arnduran          #+#    #+#             */
/*   Updated: 2023/11/02 18:30:41 by arnduran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <pthread.h>

int	main(int argc, char **argv)
{
	if (argc <= 4 || argc > 6)
		return (0);
	parsing(argc, argv);
	return (0);
}
