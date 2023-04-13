/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:09:26 by victofer          #+#    #+#             */
/*   Updated: 2023/04/13 19:11:29 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../src/minishell.h"

/* 
 * get_nb_cmd
 * ----------------------------
 *	Counts the number of commands depending on the pipes.
 *
 *	PARAMS:
 *	-> str: string given by user.
 *
 * 	RETURN
 *	-> An integer with the number of commands found.
 */
int	get_nb_cmd(char *str)
{
	int	i;
	int	cmd;

	i = -1;
	cmd = 1;
	while (str[++i])
		if (str[i] == '|')
			cmd++;
	return (cmd);
}

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
		return (NULL);
	i = -1;
	while (++i < end)
		res[i] = str[i];
	res[i] = '\0';
	return (res);
}

/* 
 * get_flags
 * ----------------------------
 *	Splits the flags of the command from the given string
 *
 *	PARAMS:
 *	-> str: string given by user.
 *
 * 	RETURN
 *	-> A string with the flags name.
 */
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
		return (NULL);
	while (start < i)
		res[j++] = str[start++];
	res[j] = '\0';
	return (res);
}

/* 
 * get_output
 * ----------------------------
 *	Splits the flags of the command from the given string
 *
 *	PARAMS:
 *	-> str: string given by user.
 *
 * 	RETURN
 *	-> A string with the flags name.
 */
char	**get_output(char *str, t_cmd *cmd)
{
	int		nb_output;
	int		*output_pos;
	char	**output;
	int		i;
	int		j;
	char	*tmp;

	output_pos = get_nb_output(str);
	nb_output = output_pos[0];
	cmd->nb_outputs = output_pos[0];
	output = malloc((nb_output + 1) * sizeof(char **));
	i = -1;
	j = 1;
	while (++i < nb_output)
	{
		tmp = get_output_from_pos(str, output_pos[j]);
		output[i] = tmp;
		tmp = NULL;
		j++;
	}
	output[i] = NULL;
	printf("inside the loop -> %s\n", tmp);
	free(tmp);
	free(output_pos);
	return (output);
}

/* 
 * get_part_from_string
 * ----------------------------
 *	Splits each part of the commans from the given string
 *
 *	PARAMS:
 *	-> str: string given by user.
 *	-> part: an int representing wich part to return. (1: cmd, 2: flags ... )
 *
 * 	RETURN
 *	-> A string with the command part.
 */
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
