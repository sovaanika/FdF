/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbear <bbear@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 15:39:18 by bbear             #+#    #+#             */
/*   Updated: 2019/02/14 16:03:10 by bbear            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordcount(char const *s, char c)
{
	size_t	word;

	word = 0;
	while (*s)
	{
		if (*s != c)
		{
			while (*s != c && *s)
				s++;
			word++;
		}
		while (*s == c && *s)
			s++;
	}
	return (word);
}

static size_t	ft_wordlen(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (*s && *s == c)
		s++;
	while (*s && *s != c)
	{
		len++;
		s++;
	}
	return (len);
}

static char		**ft_cleanall(char **new, size_t i)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		free(new[j]);
		j++;
	}
	new = NULL;
	return (new);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**new;
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	new = (char **)malloc((ft_wordcount(s, c) + 1) * sizeof(char *));
	if (new == NULL)
		return (NULL);
	while (i < ft_wordcount(s, c) + i)
	{
		while (*s == c && *s)
			s++;
		while (*s && *s != c && new)
		{
			new[i] = ft_strsub(s, 0, ft_wordlen(s, c));
			if (new[i] == NULL)
				new = ft_cleanall(new, i);
			s += ft_wordlen(s, c);
		}
		i++;
	}
	new[i] = NULL;
	return (new);
}
