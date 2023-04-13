/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:09:26 by victofer          #+#    #+#             */
/*   Updated: 2023/04/13 12:18:38 by victofer         ###   ########.fr       */
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

char	*get_cmd(char *str)
{
	int		i;
	int		end;
	char	*res;

	i = 0;
	while (str[i] != ' ' && str[i] != '\0')
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

	j = 0;
	i = 0;
	i = skip_whitespaces(str, i);
	while (str[i] != ' ' && str[i] != '\0')
		i++;
	i++;
	start = i;
	while (str[++i])
		if (str[i] == ' ' && str[i + 1] != '-')
			break ;
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
	return (res);
}
