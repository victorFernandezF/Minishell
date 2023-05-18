/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_output.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 11:38:25 by victofer          #+#    #+#             */
/*   Updated: 2023/05/18 12:22:16 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/* 
 * get_output (get/get_output.c)
 * ----------------------------
 *	Returns an array of ints with the fds of each output
 *	found in command line.
 *
 *	PARAMS:
 *	-> str: string given by user.
 *	-> cmd: struct.
 *
 * 	RETURN
 *	-> An arrray of ints with the fds of the ouput files.
 */
int	*get_output(char *str, t_cmd *cmd)
{
	int		*outputs_fd;
	int		*output_pos;
	char	**output;
	int		i;

	output = malloc((cmd->nb_outputs + 1) * sizeof(char **));
	if (!output)
		return (NULL);
	output_pos = get_output_char_positions(str, cmd);
	i = -1;
	while (++i < cmd->nb_outputs)
		output[i] = get_output_from_position(output[i], str, output_pos[i]);
	output[i] = NULL;
	outputs_fd = output_to_fd_converter(output, cmd->nb_outputs);
	free(output_pos);
	free_array(output);
	return (outputs_fd);
}

/* 
 * get_output_from_position (get/get_output.c)
 * ----------------------------
 *	Returns a sting with the output filename depending on each
 *	character '>' position in the command line. 
 *
 *	PARAMS:
 *	-> str: the command line given by user.
 *	-> cmd: Struct.
 *
 * 	RETURN
 *	-> A string with the output filename (rady to convert to fd).
 */
char	*get_output_from_position(char *out, char *str, int pos)
{
	int		i;
	int		aux;

	i = 0;
	aux = pos + 1;
	while (str[++pos])
		i++;
	out = malloc((i + 1) * sizeof(char));
	i = 0;
	if (str[aux] == '>')
	{
		aux ++;
		out[0] = '>';
		i++;
	}
	aux = skip_whitespaces(str, aux);
	while (str[aux] != ' ' && str[aux] != '\0')
	{
		out[i] = str[aux];
		aux++;
		i++;
	}
	out[i] = '\0';
	return (out);
}

/* 
 * output_to_fd_converter (get/get_output.c)
 * ----------------------------
 *	Converts each output filename into fd's.
 *	Creates the files in mode append or trunk depending
 *	on the redirections used '>' or '>>'
 *
 *	PARAMS:
 *	-> output: array with outputs filenames. 
 *	-> nb: Number of files to be openned.
 *
 * 	RETURN
 *	-> An Array of ints with the fd's ready to work..
 */
int	*output_to_fd_converter(char **output, int nb)
{
	int		i;
	int		j;
	int		*res;
	char	*out;

	i = -1;
	j = 0;
	res = malloc((nb + 1) * sizeof(int));
	if (!res)
		return (NULL);
	while (++i < nb)
	{
		if (output[i][0] == '>')
		{
			out = ft_strtrim(output[i], ">");
			free(output[i]);
			output[i] = out;
			res[i] = open(output[i], O_CREAT | O_RDWR | O_APPEND, 0644);
		}
		else
			res[i] = open(output[i], O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (res[i] == -1)
			print_error_file(output[i], "No such file or directory");
	}
	return (res);
}

/*
 * get_nb_output (get/get_output.c)
 * ----------------------------
 *	Counts the number of outputs found in command line. 
 *
 *	PARAMS:
 *	-> str: The command line.
 *
 * 	RETURN
 *	-> The number of outputs found in the given line.
 *
 */
int	get_nb_outputs(char *str)
{
	int	i;
	int	nb;

	i = -1;
	nb = 0;
	if (are_there_char(str, '>'))
		while (str[++i])
			if (str[i] == '>' && str[i + 1] != '>')
				nb++;
	return (nb);
}

/*
 * get_output_char_positions (get/get_output.c)
 * ----------------------------
 *	Returns an array of ints with the positions of each '>' chars. 
 *
 *	PARAMS:
 *	-> str: The command line.
 *	-> cmd: struct.
 *
 * 	RETURN
 *	-> An array of ints with the positions of each '>' chars.
 *
 */
int	*get_output_char_positions(char *str, t_cmd *cmd)
{
	int	*output_pos;
	int	pos;
	int	i;

	output_pos = malloc((cmd->nb_outputs + 1) * sizeof(int));
	if (!output_pos)
		return (NULL);
	i = -1;
	pos = 0;
	while (str[++i])
	{
		if (str[i] == '>' && str[i - 1] != '>')
			output_pos[pos++] = i;
	}
	return (output_pos);
}
