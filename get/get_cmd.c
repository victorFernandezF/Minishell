/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:12:47 by victofer          #+#    #+#             */
/*   Updated: 2023/05/11 13:18:00 by victofer         ###   ########.fr       */
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
char	*replace_spaces_after_redirect(char *str)
{
	int		i;
	int		j;
	int		len;
	char	*res;

	i = 0;
	len = strlen_starting_in(str, i);
	res = malloc((len + 1) * sizeof(char));
	j = 0;
	i = -1;
	while (str[++i])
	{
		if ((str[i] == '>' && str[i + 1] == ' ')
			|| (str[i] == '<' && str[i + 1] == ' '))
		{
			res[j] = str[i];
			res[j + 1] = '_';
			j += 2;
			i += 2;
		}
		res[j++] = str[i];
	}
	res[j] = '\0';
	return (res);
}

/* 
 * get_nb_cmd (get/get_cmd.c)
 * ----------------------------
 *	Counts the number of commands depending on the pipes.
 *
 *	PARAMS:
 *	-> str: string given by user.
 *
 * 	RETURN
 *	-> An integer with the number of commands found.
 */
int	get_nb_cmd(char *str)
{
	int	i;
	int	cmd;

	i = -1;
	cmd = 1;
	while (str[++i])
		if (is_pipe(str[i]))
			cmd++;
	return (cmd);
}

/* 
 * fill_string_cmd (get/get_cmd.c)
 * ----------------------------
 *	Auxiliar function to help get_cmd.
 *
 *	PARAMS:
 *	-> array: array of strings.
 *	-> position: index of element of the array.
 *
 * 	RETURN
 *	-> A String.
 */
static char	*fill_string_cmd(char **array, int position)
{
	int		i;
	int		len;
	char	*res;

	i = -1;
	len = ft_strlen(array[position]);
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	while (array[position][++i])
		res[i] = array[position][i];
	res[i] = '\0';
	return (res);
}

/* 
 * get_cmd (get/get_cmd.c)
 * ----------------------------
 *	Splits the name of the command from the given string
 *
 *	PARAMS:
 *	-> str: string given by user.
 *
 * 	RETURN
 *	-> A string with the command name.
 */
char	*get_cmd(char *str)
{
	int		i;
	int		len;
	char	*res;
	char	*tmp;
	char	**array;

	i = -1;
	len = 0;
	tmp = replace_spaces_after_redirect(str);
	array = ft_split_2(tmp);
	while (array[++i] != NULL)
	{
		if (array[i][0] == '>')
			continue ;
		len = ft_strlen(array[i]);
		break ;
	}
	res = fill_string_cmd(array, i);
	res = check_env_cmd(res);
	free(tmp);
	free_array(array);
	return (res);
}

/* 
 * check_env_cmd (get/get_cmd.c)
 * ----------------------------
 *	If an enviroment var is found in cmd name, this
 *	function converts it in its value. 
 *	(ex: $USER becomes 'victofer' 
 *
 *	PARAMS:
 *	-> str: the string that contains the cmd name.
 *
 * 	RETURN
 *	-> If a envirmoent var if found, returns a string 
 *		with the env vars transformed.
 *	-> If there are no env vars, returns the given string.
 */
char	*check_env_cmd(char *str)
{
	char	*tmp;
	char	*env;
	char	*cmd;
	int		i;
	int		j;

	i = -1;
	if (is_env_var(str[0]))
	{
		tmp = str;
		free(str);
		env = transforming(tmp);
		cmd = malloc((1 + ft_strlen(env)) * sizeof(char));
		j = -1;
		while (env[++j])
			cmd[j] = env[j];
		cmd[j] = '\0';
		return (cmd);
	}
	return (str);
}
