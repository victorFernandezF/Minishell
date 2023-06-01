/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_minishell.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 09:54:46 by victofer          #+#    #+#             */
/*   Updated: 2023/06/01 12:33:16 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Writes the elements that are inside the quotes.
 * 
 * @param str String.
 * @param start Position in wich each word starts.
 * @return A string with the things that were inside the quotes.
 */
static char	*quot_manager_with_quotes(char *str, int start)
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
	word = malloc((i + 3) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	start += 1;
	word[i] = 34;
	i++;
	while (str[start] && str[start] != 34)
		word[i++] = str[start++];
	word[i] = 34;
	word[i + 1] = '\0';
	return (word);
}

/**
 * @brief Writes the elements that are inside the quotes.
 * 
 * @param str String.
 * @param start Position in wich each word starts.
 * @return A string with the things that were inside the quotes.
 */
static char	*quot_manager(char *str, int start, int quot)
{
	int		i;
	int		aux;
	char	*word;

	if (quot == 1)
	{
		word = quot_manager_with_quotes(str, start);
		return (word);
	}
	i = 0;
	aux = start + 1;
	while (str[aux] && str[aux] != 34)
	{
		i++;
		aux++;
	}
	word = malloc((i + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	start += 1;
	while (str[start] && str[start] != 34)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

/**
 * @brief Writes each word.
 * 
 * @param str String.
 * @param start Position in which each word starts.
 * @return String with the word ready to be stored in array.
 */
static char	*write_word_minishell(char *str, int start)
{
	int		i;
	int		j;
	int		len;
	char	*word;

	i = start;
	len = 0;
	while (str[i] != '\0' && !is_space_minishel(str[i]))
	{
		i++;
		len++;
	}
	word = (char *)malloc(sizeof(char) * (len));
	if (!word)
		return (NULL);
	j = 0;
	i = start;
	while (str[i] != '\0' && !is_space_minishel(str[i]))
		word[j++] = str[i++];
	word[j] = '\0';
	return (word);
}

/**
 * @brief Auxiliary function to help ft_split_minishell to fill
 * the array with the each word.
 * 
 * @param split Array to be filled (malloc in split function). 
 * @param str String to be splitted.
 * @param nb_words Nomber of words in str (things inside quotes count as one).
 * @return Array given in arg but filled with the words of str. 
 */
static char	**fill_split_array(char **split, char *str, int nb_words, int quot)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (++i < nb_words)
	{
		j = skip_whitespaces(str, j);
		if (str[j] != '\0' && str[j] != 34)
		{
			j = skip_whitespaces(str, j);
				split[i] = write_word_minishell(str, j);
			j = skip_characters(str, j);
		}
		else
		{
			j = skip_whitespaces(str, j);
			split[i] = quot_manager(str, j, quot);
			j = get_next_char(str, j);
			j++;
		}
	}
	split[i] = NULL;
	return (split);
}

/**
 * @brief An special version of ft_split that manages double
 * quotes. If double quotes are found the words inside them won't
 * be splitted and will be stored in the array all together.
 * 
 * @param str String to be splitted.
 * @param quot Flag if 1 the part inside quotes are stored in the array
 * 	including the quootes. If 0 the part inside the quotes are strored
 * 	without the quotes.
 * @return Array with the parts of the string separated by spaces but having in
 * 	mind that the parts that are inside the quotes are considered as one element.
 */
char	**ft_split_minishell(char *str, int quot)
{
	int		nb_words;
	char	**split;

	nb_words = count_words_minishell(str);
	split = (char **)malloc((nb_words + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	split = fill_split_array(split, str, nb_words, quot);
	return (split);
}
