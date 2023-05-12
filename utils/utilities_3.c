/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:08:29 by victofer          #+#    #+#             */
/*   Updated: 2023/05/12 10:39:50 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/* 
 * fill_string (utils/utilities_3.c)
 * ----------------------------
 *	Auxiliar function to help 'delete_outputs_from_line'
 *	filling a string.
 *
 *	PARAMS:
 *	-> array: an array with every element except outputs.
 *	-> len: Length of the future string.
 *
 * 	RETURN
 *	-> A string.
 */
static char	*fill_string(char **array, int len)
{
	int		j;
	int		i;
	int		x;
	char	*res;

	x = 0;
	res = malloc(len * sizeof(char));
	if (!res)
		return (NULL);
	i = -1;
	while (array[++i])
	{
		j = -1;
		if (array[i][0] == '>')
			continue ;
		while (array[i][++j])
			res[x++] = array[i][j];
		res[x++] = ' ';
	}
	res[x - 1] = '\0';
	return (res);
}

/* 
 * delete_outputs_from_line (utils/utilities_3.c)
 * ----------------------------
 *	Returns a string with everything except outputs 
 *
 *	PARAMS:
 *	-> str: command line. 
 *
 * 	RETURN
 *	-> A string.
 */
char	*delete_outputs_from_line(char *str)
{
	int		i;
	int		len;
	char	*tmp;
	char	**array;
	char	*res;

	i = -1;
	len = 0;
	tmp = replace_spaces_after_redirect(str);
	array = ft_split_2(tmp);
	while (array[++i])
	{
		if (array[i][0] == '>')
			continue ;
		len += ft_strlen(array[i]);
		len += 1;
	}
	res = fill_string(array, len);
	free(tmp);
	free_array(array);
	return (res);
}

/* 
 * delete_outputs_from_line (utils/utilities_3.c)
 * ----------------------------
 *	Returns a string with everything except outputs 
 *
 *	PARAMS:
 *	-> str: command line. 
 *
 * 	RETURN
 *	-> A string.
 */
char	*delete_inputs_from_line(char *str)
{
	int		i;
	int		len;
	char	*tmp;
	char	**array;
	char	*res;

	i = -1;
	len = 0;
	tmp = replace_spaces_after_redirect(str);
	array = ft_split_2(tmp);
	while (array[++i])
	{
		if (array[i][0] == '<')
			continue ;
		len += ft_strlen(array[i]);
		len += 1;
	}
	res = fill_string(array, len);
	free(tmp);
	free_array(array);
	return (res);
}

int	get_position_of_last_char_found(char *str, char c)
{
	int	i;

	i = ft_strlen(str);
	while (str[--i])
		if (str[i] == c)
			return (i);
	return (0);
}
