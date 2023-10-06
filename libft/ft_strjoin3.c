/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*  ft_strjoin3.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: arnduran <marvin@42.fr>					+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2020/01/18 22:33:39 by arnduran		  #+#	#+#			 */
/*   Updated: 2020/01/18 22:34:48 by arnduran		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin3(const char *s1, const char *s2, const char *s3)
{	
	char	*s;
	size_t	n1;
	size_t	n2;
	size_t	n3;

	n1 = ft_strlen(s1);
	n2 = ft_strlen(s2);
	n3 = ft_strlen(s3);
	s = malloc(n1 + n2 + n3 + 1);
	if (!s)
		return (NULL);
	ft_memcpy(s, s1, n1);
	ft_memcpy(s + n1, s2, n2);
	ft_memcpy(s + n1 + n2, s3, n3);
	s[n1 + n2 + n3] = '\0';
	return (s);
}

// code legacy(moins fonctionnel) : 

// char *ft_strjoin3(const char *s1, const char *s2, const char *s3) {
//	 return (ft_strcat(ft_strcat(ft_strcat(ft_calloc(1, ft_strlen(s1) +
//	 ft_strlen(s2) + ft_strlen(s3)), s1), s2), s3));
// }