/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 10:49:00 by victofer          #+#    #+#             */
/*   Updated: 2023/06/06 18:35:34 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Replaces every simple quote (ascii: 39) found in string
 *  by double quotes (ascii 34) which are managed by ft_split_minishell
 *  in future functions
 * 
 * @param str String.
 * @return The given string with quotes replaced. 
 */
char	*replace_simple_quotes_by_double_quotes(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == 39)
			str[i] = 34;
	return (str);
}

/**
 * @brief Checks if a specific word inside an array is between
 *  simple quotes.
 * 
 * @param array Array
 * @param pos Postition of the word in the array
 * @return 1 if it is inside simple quotes. 0 if not.
 */
int	is_inside_simple_quotes(char **array, int pos)
{
	int	i;
	int	nb_q;

	i = -1;
	nb_q = 0;
	while (++i < pos)
		if (are_there_char(array[i], 39))
			nb_q++;
	if (nb_q % 2 == 0)
		return (0);
	return (1);
}

/**
 * @brief Checks if a simple word is inside simple quotes.
 * 
 * @param str Word to be checked
 * @return 1 if it is between quotes. 0 if not.
 */
int	check_simple_quotes(char *str)
{
	int	len;
	int	begin;
	int	end;
	int	res;

	len = ft_strlen(str) -1;
	begin = 0;
	end = 0;
	res = 0;
	if (str[0] == 39)
		begin = 1;
	if (str[len] == 39)
		end = 1;
	if (begin == 1 && end == 1)
		res = 1;
	return (res);
}

char	*find_env_from_srruct(t_env *envar, char *name)
{
	int		i;
	int		len;
	t_env	*vari;
	t_env	*tmp;

	vari = envar;
	len = 0;
	while (vari)
	{
		i = 0;
		if (are_str_equals(vari->var, name))
		{
			if (vari->vals[i + 1] == NULL)
				return (vari->vals[0]);
			while (vari->vals[i])
			{
				len += ft_strlen(vari->vals[i]) - 1;
				i++;
			}
			return (vari->vals[0]);
		}
		tmp = vari->next;
		vari = tmp;
	}
	return (NULL);
}

/**
 * @brief Calculates the necesary amount of chars to create a
 *	null terminated string with the elements of an array separated by spaces.
 * 
 * @param array Array of strings with the words that will be
 *	joined in the string.
 * @return The length of the future string with every element from the array
 */
int	get_total_length_of_words_in_array(char **array)
{
	int	i;
	int	j;
	int	len;

	i = -1;
	len = 0;
	while (array[++i])
	{
		j = -1;
		while (array[i][++j])
			len++;
	}
	len += i;
	return (len);
}