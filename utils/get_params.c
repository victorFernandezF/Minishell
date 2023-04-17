/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:08:41 by victofer          #+#    #+#             */
/*   Updated: 2023/04/17 13:04:50 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/minishell.h"

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
char	*get_params(char *str)
{
	int		i;
	int		j;
	int		last_flag;
	char	*param;

	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] == '-')
		{
			while (str[i] != ' ' && str[i] != '\0')
				i++;
			last_flag = i;
		}
	}
	while (str[i] != ' ' && str[i] != '\0')
		i++;
	last_flag++;
	param = malloc((i - last_flag) * sizeof(char));
	while (!is_token(str[i]) && !is_redirect(str[last_flag]))
		param[j++] = str[last_flag++];
	param[i] = '\0';
	return (param);
}

/* char	*transform_env_var(char *str)
{
	char	*tmp;
	int		i;
	int		j;
	int		end;
	int		start;

	i = -1;
	while (str[++i] != '\0')
	{
		printf("si %c %i\n", str[i], is_env_var(str[i]));
		if (is_env_var(str[i]))
		{
			start = i;
			while (str[i] != ' ' && str[i] != '\0')
				i++;
			end = i;
		}
	}
	tmp = malloc((end - start) * sizeof(char));
	start++;
	j = 0;
	while (str[start] != ' ' && str[start] != '\0')
		tmp[j++] = str[start++];
	tmp[j] = '\0';
	res = join_vars(str, res, tmp)exit(0);
	return (NULL);

} */
