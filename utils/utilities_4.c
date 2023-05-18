/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 13:37:53 by victofer          #+#    #+#             */
/*   Updated: 2023/05/18 10:13:29 by victofer         ###   ########.fr       */
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
		if (array[i][0] == '<')
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

/* 
 * is_there_env_var (utils/utilities_4.c)
 * ----------------------------
 *	Returns 1 if an env var is found in the string. 
 *
 *	PARAMS:
 *	-> str: string. 
 *
 * 	RETURN
 *	-> 1 if an env var is found in the string.
 *	-> 0 if not.
 */
int	is_there_env_var(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == '#')
			return (1);
	return (0);
}

char	*ft_splitnt(char **array, int len)
{
	char	*new_line;
	int		i;
	int		j;
	int		x;

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