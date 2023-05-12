/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:12:47 by victofer          #+#    #+#             */
/*   Updated: 2023/05/12 11:33:08 by victofer         ###   ########.fr       */
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
 *	-> The number of commands found.
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
	int		j;
	int		len;
	char	*cmd_name;
	char	*env;

	i = -1;
	j = 0;
	i = skip_whitespaces(str, 0);
	len = skip_characters(str, i);
	cmd_name = malloc((len + 1) * sizeof(char));
	if (!cmd_name)
		return (NULL);
	while (str[i] != ' ' && str[i] != '\0')
		cmd_name[j++] = str[i++];
	cmd_name[j] = '\0';
	if (is_env_var(cmd_name[0]))
	{
		env = get_env_cmd(cmd_name);
		return (env);
	}
	return (cmd_name);
}

/* 
 * get_env_cmd (get/get_cmd.c)
 * ----------------------------
 *	This function converts the enviroment var in
 *	cmd name in its value. (ex: $USER becomes 'victofer'). 
 *
 *	PARAMS:
 *	-> str: the string that contains the cmd name.
 *
 * 	RETURN
 *	-> Returns a string with the env vars transformed.
 */
char	*get_env_cmd(char *str)
{
	char	*tmp;
	char	*env;
	char	*cmd;
	int		i;
	int		j;

	i = -1;
	tmp = str;
	free(str);
	env = transforming(tmp);
	printf("%s\n", env);
	cmd = malloc((1 + ft_strlen(env)) * sizeof(char));
	j = -1;
	while (env[++j])
		cmd[j] = env[j];
	cmd[j] = '\0';
	return (cmd);
}
