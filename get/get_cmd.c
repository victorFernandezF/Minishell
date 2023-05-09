/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:12:47 by victofer          #+#    #+#             */
/*   Updated: 2023/05/09 10:39:50 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/* 
 * get_nb_cmd
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
 * get_cmd
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
	int		end;
	char	*res;

	i = 0;
	i = skip_characters(str, i);
	end = i;
	res = malloc(i * sizeof(char));
	if (!res)
		return (NULL);
	i = -1;
	while (++i < end)
		res[i] = str[i];
	res[i] = '\0';
	res = check_env_cmd(res);
	return (res);
}

/* 
 * check_env_cmd
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
	if (str[0] == '#')
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
