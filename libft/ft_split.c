/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alopez-v <alopez-v@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 16:45:52 by alopez-v          #+#    #+#             */
/*   Updated: 2025/01/22 09:59:51 by alopez-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	get_split_len(const char *s, const char c)
{
	size_t	num_words;
	char	in_word;
	char	*iter;

	num_words = 0;
	in_word = 0;
	iter = (char *)s;
	while (*iter != '\0')
	{
		if (!in_word && *iter != c)
			in_word = 1;
		else if (in_word && *iter == c)
		{
			in_word = 0;
			++num_words;
		}
		++iter;
	}
	if (in_word)
		++num_words;
	return (num_words);
}

static void	free_split(char ***split, const size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		if ((*split)[i])
		{
			free((*split)[i]);
			(*split)[i] = NULL;
		}
		++i;
	}
	free(*split);
	*split = NULL;
}

static char	try_add_split(const char *start, const char *end, char ***split,
		size_t *word_count)
{
	(*split)[*word_count] = ft_substr(start, 0, end - start);
	if (!(*split)[*word_count])
	{
		free_split(split, *word_count);
		return (0);
	}
	return (1);
}

static char	try_fill_split(const char *s, const char c, char ***split,
		const size_t split_len)
{
	size_t	word_count;
	char	*iter;
	char	*start;

	word_count = 0;
	iter = (char *)s;
	start = NULL;
	while (*iter != '\0')
	{
		if (!start && *iter != c)
			start = iter;
		else if (start && *iter == c)
		{
			if (!try_add_split(start, iter, split, &word_count))
				return (0);
			++word_count;
			start = NULL;
		}
		++iter;
	}
	if (start && !try_add_split(start, iter, split, &word_count))
		return (0);
	(*split)[split_len] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	size_t	split_len;
	char	**split;

	split_len = get_split_len(s, c);
	split = malloc(sizeof(char *) * (split_len + 1));
	if (!split || !try_fill_split(s, c, &split, split_len))
		return (NULL);
	return (split);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char **split;

// 	split = ft_split("h e l l o", ' ');
// 	return (0);
// }