/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arnduran <arnduran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 22:33:28 by arnduran          #+#    #+#             */
/*   Updated: 2023/10/05 22:03:23 by arnduran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_word(char const *s, char c)
{
	size_t	i;
	size_t	word;

	i = 0;
	word = 0;
	if (ft_strlen(s) == 0)
		return (0);
	while (s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			word++;
			while (s[i] == c)
				i++;
			if (!(s[i]))
				i--;
		}
		i++;
	}
	if (s[i - 1] == c)
		return (word);
	return (word + 1);
}

static char	*ft_get_next_word(char const *s, char c, size_t *j)
{
	char	*word;
	size_t	jcopy;
	size_t	i;

	i = 0;
	while (s[*j] == c)
		(*j)++;
	jcopy = *j;
	while (s[jcopy] && s[jcopy] != c)
		jcopy++;
	word = (char *)malloc(sizeof(char) * (jcopy - *j + 1));
	if (!word)
		return (NULL);
	while (*j < jcopy)
	{
		word[i] = s[*j];
		i++;
		(*j)++;
	}
	word[i] = '\0';
	return (word);
}

/*
static void	ft_freetab(char **tab, int i)
{
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
}
*/

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	j;
	size_t	word;

	i = 0;
	j = 0;
	if (!(s))
		return (NULL);
	word = ft_count_word(s, c);
	tab = (char **)malloc(sizeof(char *) * (word + 1));
	if (!tab)
		return (NULL);
	while (i < word)
	{
		tab[i] = ft_get_next_word(s, c, &j);
		i++;
	}
	tab[word] = NULL;
	return (tab);
}

/*
if (!(word = (char *)malloc(sizeof(char) * (jcopy - *j + 1))))
		return (NULL);
		ligne 55
		if (!(tab = (char **)malloc(sizeof(char *) * (word + 1))))
		return (NULL);
		ligne 90
		if (!tab[i] = ft_get_next_word(s, c, &j))
		{
			ft_freetab(tab, i);
			return (NULL);
		}
		ligne 95
*/
