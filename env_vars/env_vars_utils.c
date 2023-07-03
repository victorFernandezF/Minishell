/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_vars_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 12:53:01 by victofer          #+#    #+#             */
/*   Updated: 2023/06/27 18:24:40 by victofer         ###   ########.fr       */
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

static char	**take_only_the_good_ones(char **array)
{
	int		i;
	int		j;
	int		len;
	char	**res;

	i = -1;
	len = 0;
	j = 0;
	while (array[++i])
		if (array[i][0] != '$')
			len++;
	if (len == 0)
		return (array);
	res = malloc((len + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	i = -1;
	while (array[++i])
		if (array[i][0] != '$')
			res[j++] = ft_copy_str(array[i]);
	res[j] = NULL;
	free_array(array);
	return (res);
}

char	*more_than_one_env_vars(char *str, t_env *envar)
{
	char	**env;
	char	**temp;
	int		i;
	char	*tmp;
	char	*final;

	i = -1;
	env = ft_split(str, '$');
	while (env[++i] != NULL)
	{
		tmp = ft_strjoin("$", env[i]);
		free(env[i]);
		env[i] = convert_env_var_in_its_value(tmp, envar);
	}
	temp = take_only_the_good_ones(env);
	i = get_total_length_of_words_in_array(temp);
	tmp = ft_splitnt(temp, i);
	final = delete_spaces(tmp);
	free_array(temp);
	free(tmp);
	free(str);
	return (final);
}

int	env_var_counter(char *str)
{
	int	i;
	int	res;

	i = -1;
	res = 0;
	while(str[++i])
		if (is_env_var(str[i]))
			res++;
	return (res);
}

char	*redi_string(int len, char *env_complete, char *env, int flag)
{
	char	*result;
	int		i;
	int		j;

	i = -1;
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	env_complete = replace_simple_quotes_by_double_quotes(env_complete);
	while (!is_env_var(env_complete[++i]))
		result[i] = env_complete[i];
	while (env[++j])
		result[i++] = env[j];
	if (flag == 1)
		result[i++] = 34;
	result[i] = '\0';
	return (result);
}