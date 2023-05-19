/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_output.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 11:38:25 by victofer          #+#    #+#             */
/*   Updated: 2023/05/19 13:47:33 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Returns an array of ints with the fds of each output
 *	found in command line.
 * 
 * @param cmd_line Command line
 * @param cmd Struct.
 * @return Array of ints with the fds of each output
 *	found in command line.
 */
int	*get_output(char *cmd_line, t_cmd *cmd)
{
	int		*outputs_fd;
	int		*out_pos;
	char	**output;
	int		i;

	output = malloc((cmd->nb_outputs + 1) * sizeof(char **));
	if (!output)
		return (NULL);
	out_pos = get_output_char_positions(cmd_line, cmd);
	i = -1;
	while (++i < cmd->nb_outputs)
		output[i] = get_output_from_position(cmd_line, out_pos[i]);
	output[i] = NULL;
	outputs_fd = output_to_fd_converter(output, cmd->nb_outputs);
	free(out_pos);
	free_array(output);
	return (outputs_fd);
}

/**
 * @brief Returns a sting with the output filename depending on each
 *	character '>' position in the command line.
 * 
 * @param cmd_line the command line given by user.
 * @param Position where input starts.
 * @return A string with the input filename. 
 */
char	*get_output_from_position(char *cmd_line, int position)
{
	int		i;
	int		aux;

	i = 0;
	aux = position + 1;
	while (cmd_line[++position])
		i++;
	out = malloc((i + 1) * sizeof(char));
	i = 0;
	if (cmd_line[aux] == '>')
	{
		aux ++;
		out[0] = '>';
		i++;
	}
	aux = skip_whitespaces(cmd_line, aux);
	while (cmd_line[aux] != ' ' && cmd_line[aux] != '\0')
	{
		out[i] = cmd_line[aux];
		aux++;
		i++;
	}
	out[i] = '\0';
	return (out);
}

/**
 * @brief Transforms each output filename into a file descriptor (in read mode).
 *	If the file does not exist, prints a message.
 * 
 * @param input An array of strings with every output filenames.
 * @param nb_inputs The number of output filenames found in command line.
 * @return An array with the files descriptor (fd's) of each output file. 
 */
int	*input_filename_to_fd_converter(char **output, int nb_outputs)
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
	while (++i < nb_output)
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
