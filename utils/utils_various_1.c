/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_various_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 13:37:53 by victofer          #+#    #+#             */
/*   Updated: 2023/07/07 12:58:25 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Get the position of the next given character in the string.
 * 
 * @param str String where char will be searched.
 * @param pos Position in the string of the char to be found. 
 * @return [Int] The position of the next character that is equal to
 *  the given one. 
 */
int	get_next_char(char *str, int pos)
{
	char	c;

	c = str[pos];
	while (str[++pos])
		if (str[pos] == c)
			return (pos);
	return (-1);
}

/**
 * @brief It's the oposite of ft_split. (ft_splitn't xd)
 *	It take an array of strings and the length of the array
 *	and returns a null terminated string with every elements of
 *	the array separated by spaces.
 * 
 * @param array Array to convert to string.
 * @param len Length of the array.
 * @param is_len if is 0 this function calculates the length of the 
 * string. if is 1, this function gets the length from 'len' param. 
 * @return [char *] A null terminated string with every elements of
 *	the array separated by spaces.
 */
char	*ft_splitnt(char **array, int len, int is_len)
{
	int		i;
	int		j;
	int		x;
	char	*new_line;

	if (is_len == 0)
		len = get_total_length_of_words_in_array(array);
	i = -1;
	x = 0;
	new_line = malloc(len * sizeof(char));
	if (!new_line)
		return (NULL);
	while (array[++i])
	{
		j = -1;
		while (array[i][++j])
			new_line[x++] = array[i][j];
		if (array[i + 1])
			new_line[x++] = ' ';
	}
	new_line[x] = '\0';
	return (new_line);
}

/**
 * @brief Get the length of a string but starting in an specific
 * position instead of since the begining as ft_strlen doues.
 * 
 * @param str String.
 * @param start position since where start counting chars.
 * @return [Int] The length of the portion of string.
 */
int	strlen_starting_in(char *str, int start)
{
	int	len;

	len = 0;
	while (str[start])
	{
		len++;
		start++;
	}
	return (len);
}
