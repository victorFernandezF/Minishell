/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:03:13 by victofer          #+#    #+#             */
/*   Updated: 2023/05/18 10:13:14 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
char	*get_env_var_when_is_first_char(char *str)
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
	if (env == NULL)
		env = "";
	cmd = malloc((1 + ft_strlen(env)) * sizeof(char));
	if (!cmd)
		return (NULL);
	j = -1;
	while (env[++j])
		cmd[j] = env[j];
	cmd[j] = '\0';
	return (cmd);
}

static int	get_total_len(char **array)
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

static char	*get_env_var_when_is_not_first_char(char *str)
{
	char	*tmp;
	char	*env;
	char	*final;

	tmp = get_temporal_redirection(str);
	env = transforming(tmp);
	if (env == NULL)
		print_error_file(tmp, "ambiguous redirect");
	final = fill_string_redirection(str, env);
	printf("aaa %s\n", final);
	free(str);
	str = final;
	free(tmp);
	return (final);
}

char	*spand_all_env_vasr(char *str)
{
	int		i;
	int		len;
	char	*new_line;
	char	**array;
	char	*temp;

	i = -1;
	array = ft_split_2(str);
	i = -1;
	while (array[++i])
	{
		if (is_there_env_var(array[i]))
		{
			if (!is_env_var(array[i][0]))
				temp = get_env_var_when_is_not_first_char(array[i]);
			else
				temp = get_env_var_when_is_first_char(array[i]);
			array[i] = temp;
		}
	}
	len = get_total_len(array);
	new_line = ft_splitnt(array, len);
	free_array(array);
	return (new_line);
}
