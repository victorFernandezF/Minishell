/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 18:03:13 by victofer          #+#    #+#             */
/*   Updated: 2023/05/17 19:18:59 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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

static char	*fill_new_line_with_array_values(char **array, int len)
{
	char	*new_line;
	int		i;
	int		j;
	int		x;

	i = -1;
	x = 0;
	new_line = malloc(len * sizeof(char));
	if (!new_line)
		return (NULL);
	while (array[++i])
	{
		j = -1;
		while (array[i][++j])
			new_line[x++] = array[i][j];
		if (array[i + 1])
			new_line[x++] = ' ';
	}
	new_line[x] = '\0';
	return (new_line);
}

static char	*not_first_env_var(char	*str)
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
				temp = not_first_env_var(array[i]);
			else
				temp = get_env_cmd(array[i]);
			array[i] = temp;
		}
	}
	len = get_total_len(array);
	new_line = fill_new_line_with_array_values(array, len);
	free_array(array);
	return (new_line);
}
