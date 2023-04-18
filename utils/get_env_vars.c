/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_vars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:14:36 by victofer          #+#    #+#             */
/*   Updated: 2023/04/18 12:20:09 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/minishell.h"

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

char	*replace_env_by_value(char	*str, int pos, char *tmp)
{
	char	*res;
	int		i;
	int		j;
	int		aux;
	char	*env;

	i = 0;
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
	while (env[i])
		res[j++] = env[i++];
	while (str[aux] != '\0')
		res[j++] = str[aux++];
	res[j] = '\0';
	return (res);
}

char	*fill_temporal_env_var(char *tmp, char *str, int aux, int i)
{
	while (str[aux] != ' ' && str[aux] != '\0')
		tmp[i++] = str[aux++];
	tmp[i] = '\0';
	return (tmp);
}

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
	res = replace_env_by_value(str, posi, tmp);
	free(tmp);
	return (res);
}

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
	return (res);
}
