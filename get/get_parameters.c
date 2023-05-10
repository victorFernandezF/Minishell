/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_parameters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:10:24 by victofer          #+#    #+#             */
/*   Updated: 2023/05/10 13:08:02 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	skip_cmd_and_flags(char	*str)
{
	int	i;

	i = 0;
	if (are_there_char(str, '-'))
	{
		i = ft_strlen(str);
		while (str[i] != '-')
			i--;
		i = skip_characters(str, i);
		return (i);
	}
	i = skip_characters(str, i);
	return (i);
}

char	*get_temp_char(char *str)
{
	int		i;
	int		j;
	int		len;
	char	*res;

	i = 0;
	i = skip_cmd_and_flags(str);
	printf("%i\n", i);
	len = strlen_startin_in(str, i);
	res = malloc((len + 1) * sizeof(char));
	j = 0;
	while (str[++i])
	{
		if (str[i] == '>' && str[i + 1] == ' ')
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

char	*fill_res(char **temp_arr, int len)
{
	int		j;
	int		x;
	int		i;
	char	*res;

	res = malloc(len * sizeof(char));
	i = -1;
	x = 0;
	while (temp_arr[++i] != NULL)
	{
		if (temp_arr[i][0] == '>')
			continue ;
		j = 0;
		while (temp_arr[i][j])
			res[x++] = temp_arr[i][j++];
		res[x++] = ' ';
	}
	res[x] = '\0';
	return (res);
}

int	get_len(char **arr)
{
	int	i;
	int	j;
	int	len;

	i = -1;
	len = 0;
	while (arr[++i] != NULL)
	{
		if (arr[i][0] == '>')
			continue ;
		j = -1;
		len++;
		while (arr[i][++j])
			len++;
	}
	return (len);
}

char	*del_outputs(char *str)
{
	char	*temp;
	char	**temp_arr;
	char	*res;
	int		len;
	int		i;

	temp = get_temp_char(str);
	temp_arr = ft_split_2(temp);
	len = get_len(temp_arr);
	i = -1;
	res = fill_res(temp_arr, len);
	free(temp);
	free_array(temp_arr);
	return (res);
}
