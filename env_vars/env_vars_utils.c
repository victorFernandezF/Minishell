/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_vars_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 12:53:01 by victofer          #+#    #+#             */
/*   Updated: 2023/06/23 12:53:20 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*delete_spaces(char *str)
{
	int		nb;
	int		i;
	int		j;
	char	*nosp;

	i = -1;
	j = 0;
	nb = 0;
	while (str[++i])
		if (str[i] == ' ')
			nb++;
	nosp = malloc((ft_strlen(str) - nb) * sizeof(char));
	if (!nosp)
		return (NULL);
	i = -1;
	while (str[++i])
		if (str[i] != ' ')
			nosp[j++] = str[i];
	return (nosp);
}

char	*more_than_one_env_vars(char *str, t_env *envar)
{
	char	**env;
	int		i;
	char	*tmp;
	int		len;
	char	*final;

	i = -1;
	env = ft_split(str, '$');
	while (env[++i] != NULL)
	{
		tmp = ft_strjoin("$", env[i]);
		free(env[i]);
		env[i] = convert_env_var_in_its_value(tmp, envar);
	}
	len = get_total_length_of_words_in_array(env);
	tmp = ft_splitnt(env, len);
	final = delete_spaces(tmp);
	free_array(env);
	free(tmp);
	free(str);
	return (final);
}
