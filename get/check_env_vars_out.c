/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty(just in case).c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:14:36 by victofer          #+#    #+#             */
/*   Updated: 2023/05/08 19:06:22 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*transforming_out(char *str)
{
	int		i;
	int		j;
	char	*temp;
	char	*env;

	i = 1;
	j = 0;
	temp = malloc(ft_strlen(str) * sizeof(char));
	while (str[++i])
		temp[j++] = str[i];
	temp[j] = '\0';
	env = getenv(temp);
	free(temp);
	return (env);
}

static char	*check_double_output(char *output)
{
	char	*tmp;
	char	*env;
	char	*out;
	int		i;
	int		j;

	tmp = output;
	free(output);
	j = 0;
	i = 1;
	env = transforming_out(tmp);
	out = malloc((2 + ft_strlen(env)) * sizeof(char));
	out[0] = '>';
	while (env[j])
		out[i++] = env[j++];
	out[i] = '\0';
	output = out;
	return (output);
}

char	**check_env_output(char **output)
{
	char	*tmp;
	char	*env;
	char	*out;
	int		i;
	int		j;

	i = -1;
	while (output[++i])
	{
		printf("%s\n", output[i]);
		if (output[i][0] == '>' && output[i][1] == '#')
			output[i] = check_double_output(output[i]);
		if (output[i][0] != '>' && output[i][0] == '#')
		{
			printf("JELOU MAI FREN\n");
			tmp = output[i];
			free(output[i]);
			env = transforming(tmp);
			out = malloc((1 + ft_strlen(env)) * sizeof(char));
			j = -1;
			while (env[++j])
				out[j] = env[j];
			out[j] = '\0';
			output[i] = out;
		}
	}
	return (output);
}