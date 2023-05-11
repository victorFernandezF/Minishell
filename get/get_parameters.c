/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_parameters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:10:24 by victofer          #+#    #+#             */
/*   Updated: 2023/05/11 19:11:33 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/* 
 * get_temp_param_and_output_string (get/get_parameters.c)
 * ----------------------------
 *	Create a new string with everithing except cmd name and flags
 *	and the redirection characters are followed by '_'
 *	(ex: line 'echo -n hello > out world' will become 'hello >_out world')
 *
 *	PARAMS:
 *	-> str: the command line.
 *
 * 	RETURN
 *	-> A string that contains everithing except cmd name and flags
 *	and the redirection characters are followed by '_'.
 */
char	*get_temp_param_and_output_string(char *str)
{
	int		i;
	int		j;
	int		len;
	char	*res;
	char	*tmp;

	i = 0;
	j = 0;
	tmp = delete_outputs_from_line(str);
	i = skip_cmd_and_flags(tmp);
	len = strlen_starting_in(str, i);
	res = malloc((len + 1) * sizeof(char));
	while (tmp[++i])
		res[j++] = tmp[i];
	res[j] = '\0';
	free(tmp);
	return (res);
}

/* 
 * fill_param_string (get/get_parameters.c)
 * ----------------------------
 *	Auxiliar function that fills the arra containing the
 *	parameters found separated by spaces.  
 *
 *	PARAMS:
 *	-> array: An array of strings with all elements in command
 *	line except cmd name and flags.
 *
 * 	RETURN
 *	-> A string that contains only the parameters found in command line.
 */
static char	*fill_param_string(char **array, int len)
{
	int		i;
	int		j;
	int		x;
	char	*res;

	res = malloc(len * sizeof(char));
	i = -1;
	x = 0;
	while (array[++i] != NULL)
	{
		if (array[i][0] == '>' || array[i][0] == '<')
			continue ;
		j = 0;
		while (array[i][j])
			res[x++] = array[i][j++];
		res[x++] = ' ';
	}
	res[x] = '\0';
	return (res);
}

/* 
 * get_params_len (get/get_parameters.c)
 * ----------------------------
 *	Calculates the length that must be allocated for 
 *	the future string with all parameters.  
 *
 *	PARAMS:
 *	-> array: An array of strings with all elements in command
 *	line except cmd name and flags.
 *
 * 	RETURN
 *	-> The size of the future string mast be.
 */
int	get_params_len(char **array)
{
	int	i;
	int	j;
	int	len;

	i = -1;
	len = 0;
	while (array[++i] != NULL)
	{
		if (array[i][0] == '>')
			continue ;
		j = -1;
		len++;
		while (array[i][++j])
			len++;
	}
	return (len);
}

/* 
 * get_params_when_output_found (get/get_parameters.c)
 * ----------------------------
 *	Returns a string with every parameters found.
 *	(ex: echo -n hello > output world -> hello world).
 *
 *	PARAMS:
 *	-> str: command line.
 *
 * 	RETURN
 *	-> A string with every parameters found separated by spaces.
 */
char	*get_params_when_output_found(char *str)
{
	char	*temp;
	char	**temp_arr;
	char	*res;
	int		len;
	int		i;

	temp = get_temp_param_and_output_string(str);
	temp_arr = ft_split_2(temp);
	len = get_params_len(temp_arr);
	i = -1;
	res = fill_param_string(temp_arr, len);
	free(temp);
	free_array(temp_arr);
	return (res);
}
