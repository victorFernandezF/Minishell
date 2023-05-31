/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_minishell.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 09:54:46 by victofer          #+#    #+#             */
/*   Updated: 2023/05/31 11:21:03 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Counts thenumber of words that are in the string.
 * 	Things inside double quotes count as one.
 * 
 * @param str String to be splitted.
 * @return thhe nomber of elements that the final array will have.
 */
static int	count_words_minishell(char *str)
{
	int	cont;

	cont = 0;
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

/**
 * @brief Writes the elements that are inside the quotes.
 * 
 * @param str String.
 * @param start Position in wich each word starts.
 * @return A string with the things that were inside the quotes.
 */
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
	int		len;
	int		j;
	char	*word;

	i = start;
	len = 0;
	while (str[i] != '\0' && !is_space_minishel(str[i]))
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

/**
 * @brief Auxiliary function to help ft_split_minishell to fill
 * the array with the each word.
 * 
 * @param split Array to be filled (malloc in split function). 
 * @param str String to be splitted.
 * @param nb_words Nomber of words in str (things inside quotes count as one).
 * @return Array given in arg but filled with the words of str. 
 */
static char	**fill_split_array(char **split, char *str, int nb_words)
{
	int	i;
	int	j;

	i = -1;
	j = 0;

	while (++i < nb_words)
	{
		j = skip_whitespaces(str, j);
		if (str[j] != 34)
		{	
			j = skip_whitespaces(str, j);
			split[i] = write_word_minishell(str, j);
			j = skip_characters(str, j);
		}
		else
		{
			j = skip_whitespaces(str, j);
			split[i] = quot_manager(str, j);
			j = get_next_char(str, j);
			j++;
		}
	}
	split[i] = NULL;
	return (split);
}

/**
 * @brief An special version of ft_split that manages double
 *  quotes. If double quotes are found the words inside them won't
 * be splitted and will be stored in the array all together.
 * 
 * @param str String to be splitted.
 * @return An array with eacha word (or words) splitted by spaces.
 */
char	**ft_split_minishell(char *str)
{
	int		nb_words;
	char	**split;

	nb_words = count_words_minishell(str);
	split = (char **)malloc((nb_words + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	split = fill_split_array(split, str, nb_words);
	return (split);
}
