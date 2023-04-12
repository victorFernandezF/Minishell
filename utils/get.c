/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:09:26 by victofer          #+#    #+#             */
/*   Updated: 2023/04/12 12:10:10 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/minishell.h"

int	get_nb_cmd(char *str, int cmd)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] == '|')
			cmd++;
	return (cmd);
}

char	*get_output(char *str)
{
	int		i;
	int		j;
	int		output;
	int		start;
	char	*res;

	i = -1;
	j = 0;
	output = 0;
	while (str[++i])
		if (str[i] == '>')
			output = i;
	if (output == 0)
		return (NULL);
	output += 2;
	start = output;
	while (str[output] != ' ')
		output++;
	res = malloc((output - start + 1) * sizeof(char));
	if (!res)
		exit(0);
	while (start < output)
		res[j++] = str[start++];
	res[j] = '\0';
	return (res);
}

char	*get_cmd(char *str)
{
	int		i;
	int		end;
	char	*res;

	i = 0;
	while (str[i] != ' ')
			i++;
	end = i;
	res = malloc(i * sizeof(char));
	if (!res)
		exit(0);
	i = -1;
	while (++i < end)
		res[i] = str[i];
	res[i] = '\0';
	return (res);
}

char	*get_flags(char *str)
{
	int		i;
	int		start;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	while (str[i] == ' ')
			i++;
	while (str[i] != ' ')
		i++;
	while (str[i] == ' ')
		i++;
	start = i;
	while (str[i] != '>' && str[i] != '<')
		i++;
	res = malloc(((i - start) + 1) * sizeof(char));
	if (!res)
		exit(0);
	while (start < i)
		res[j++] = str[start++];
	res[j] = '\0';
	return (res);
}

char	*get_part_from_str(char *str, int part)
{
	char	*res;

	res = NULL;
	if (part == 1)
		res = get_cmd(str);
	if (part == 2)
		res = get_flags(str);
	if (part == 3)
		res = get_output(str);
	return (res);
}
