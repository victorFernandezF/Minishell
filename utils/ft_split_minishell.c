/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_minishell.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 09:54:46 by victofer          #+#    #+#             */
/*   Updated: 2023/05/25 11:23:24 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	count_words_minishell(char *str)
{
	int	cont;
	int	quot;

	cont = 0;
	quot = 0;
	while (*str)
	{
		while (*str && is_space_minishel(*str))
			str++;
		if (*str == 34)
		{
			cont++;
			str++;
			while (*str && *str != 34)
				str++;
			str++;
		}
		else if (*str && !is_space_minishel(*str))
		{
			cont++;
			while (*str && !is_space_minishel(*str))
				str++;
		}
	}
	return (cont);
}

static char	*quot_manager(char *str, int start)
{
	int		i;
	int		aux;
	char	*word;

	i = 0;
	aux = start + 1;
	while (str[aux] && str[aux] != 34)
	{
		i++;
		aux++;
	}
	word = malloc(i * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	start += 1;
	while (str[start] && str[start] != 34)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	*write_word_minishell(char *str, int start)
{
	int		i;
	int		len;
	int		j;
	char	*word;

	i = start;
	len = 0;
	while (str[i] && !is_space_minishel(str[i]))
	{
		i++;
		len++;
	}
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	j = 0;
	i = start;
	while (str[i] && !is_space_minishel(str[i]))
		word[j++] = str[i++];
	word[i] = '\0';
	return (word);
}

char	**fill_split_array(char **split, char *str, int nb_words)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (++i < nb_words)
	{
		j = skip_whitespaces(str, j);
		if (str[j] == 34 && !is_there_open_quotes(str, j))
		{
			split[i] = quot_manager(str, j);
			j = skip_everything_til_quotes(str, j + 1);
		}
		else
		{	
			j = skip_whitespaces(str, j);
			split[i] = write_word_minishell(str, j);
			j = skip_characters(str, j);
		}
	}
	split[i] = NULL;
	return (split);
}

char	**ft_split_minishell(char *str)
{
	int		i;
	int		j;
	int		nb_words;
	char	**split;

	i = -1;
	j = 0;
	nb_words = count_words_minishell(str);
	split = (char **)malloc((nb_words + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	split = fill_split_array(split, str, nb_words);
	return (split);
}
