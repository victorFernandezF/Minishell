/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_vars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:14:36 by victofer          #+#    #+#             */
/*   Updated: 2023/04/25 09:53:51 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
/* 
 * get_nb_env
 * ----------------------------
 *	Return the number of enviroment variables ($HOME ...) in the line  
 *
 *	PARAMS:
 *	-> str: A string whith the whole commad (ex: echo -n "hello" > out)
 */
static int	get_nb_env(char *str)
{
	int	i;
	int	nb_env;

	i = -1;
	nb_env = 0;
	while (str[++i])
		if (is_env_var(str[i]))
			nb_env++;
	return (nb_env);
}

/* 
 * replace_env_by_value
 * ----------------------------
 *	Replaces the enviroment variable found in the str by.
 *	its value (ex: "echo -n $USER" will become "echo -n victofer" ). 
 *
 *	PARAMS:
 *	-> tmp: A string with the name of the env var.
 *	-> pos: The position where the env var starts.
 *	-> str: A string whith the whole commad (ex: echo -n "hello" > out)
 *
 * 	RETURN
 *	-> A string with en vars replaced.
 */
char	*replace_env_by_value(char	*str, int pos, char *tmp, int i)
{
	char	*res;
	int		j;
	int		aux;
	char	*env;

	aux = pos;
	env = getenv(tmp);
	while (str[aux] != ' ' && str[aux] != '\0')
	{
		i++;
		aux++;
	}
	res = malloc((i + pos + ft_strlen(env)) * sizeof(char));
	i = 0;
	j = 0;
	while (!is_env_var(str[i]) && str[i])
		res[j++] = str[i++];
	i = 0;
	while (env[i])
		res[j++] = env[i++];
	while (str[aux] != '\0')
		res[j++] = str[aux++];
	res[j] = '\0';
	return (res);
}

static char	*fill_temporal_env_var(char *tmp, char *str, int aux, int i)
{
	while (str[aux] != ' ' && str[aux] != '\0')
		tmp[i++] = str[aux++];
	tmp[i] = '\0';
	return (tmp);
}

/* 
 * transformation
 * ----------------------------
 *	gets the name of the env var and calls
 *	the function to replace it by its value. 
 *
 *	PARAMS:
 *	-> str: A string whith the commad line.
 *
 * 	RETURN
 *	-> str: A string.
 */
char	*transformation(char *str)
{
	int		i;
	int		aux;
	char	*tmp;
	char	*res;
	int		posi;

	i = 0;
	while (str[++i] != '#')
		posi = i;
	posi++;
	aux = posi;
	while (str[aux] != ' ' && str[aux] != '\0')
	{
		aux++;
		i++;
	}
	i++;
	tmp = malloc(i * sizeof(char));
	aux = posi + 1;
	tmp = fill_temporal_env_var(tmp, str, aux, 0);
	res = replace_env_by_value(str, posi, tmp, 0);
	free(tmp);
	return (res);
}

/* 
 * transform_env_var
 * ----------------------------
 *	get the number of enviroment variables and replaces them
  *	by its value. (calling each functions) 
 *
 *	PARAMS:
 *	-> str: A string whith the commad line.
 *
 * 	RETURN
 *	-> str: A string.
 */
char	*transform_env_var(char *str)
{
	int		nb_env;
	char	*res;
	int		i;

	i = -1;
	res = str;
	nb_env = get_nb_env(str);
	while (++i < nb_env)
		res = transformation(res);
	free(str);
	return (res);
}
