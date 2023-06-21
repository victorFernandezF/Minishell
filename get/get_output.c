/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_output.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 11:38:25 by victofer          #+#    #+#             */
/*   Updated: 2023/06/21 10:44:49 by victofer         ###   ########.fr       */
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
int	get_output(char *cmd_line, t_cmd *cmd)
{
	int		i;
	char	**out;
	int		*out_pos;
	int		*outputs_fd;
	int		last_output;

	i = -1;
	if (!search_char_in_str(cmd_line, '>'))
		return (0);
	out = malloc((cmd->nb_outputs + 1) * sizeof(char **));
	if (!out)
		return (0);
	out_pos = get_output_char_positions(cmd_line, cmd);
	while (++i < cmd->nb_outputs)
		out[i] = get_output_from_pos(cmd, cmd_line, out_pos[i], out_pos[i] + 1);
	out[i] = NULL;
	if (cmd->error == 1)
		return (free_redirection(out_pos, NULL, out), 0);
	outputs_fd = output_filename_to_fd_converter(out, cmd->nb_outputs);
	last_output = outputs_fd[cmd->nb_outputs - 1];
	i = -1;
	while (++i < cmd->nb_outputs)
		close(outputs_fd[i]);
	free_redirection(out_pos, outputs_fd, out);
	return (last_output);
}

/**
 * @brief Returns a sting with the output filename depending on each
 *	character '>' position in the command line.
 * 
 * @param cmd_line the command line given by user.
 * @param Position where input starts.
 * @return A string with the input filename. 
 */
char	*get_output_from_pos(t_cmd *cmd, char *cmd_line, int position, int aux)
{
	int		i;
	char	*out;

	i = strlen_starting_in(cmd_line, position);
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
	if (env_var_detector(out))
		print_error_file_ambiguous(out, cmd);
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
int	*output_filename_to_fd_converter(char **output, int nb_outputs)
{
	int		i;
	int		*res;
	char	*out;

	i = -1;
	res = malloc((nb_outputs + 1) * sizeof(int));
	if (!res)
		return (NULL);
	while (++i < nb_outputs)
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

/**
 * @brief Counts the number of outputs found in command line.
 * 
 * @param cmd_line 
 * @return The number of outputs found.
 */
int	get_nb_outputs(char *cmd_line)
{
	int	i;
	int	nb;

	i = -1;
	nb = 0;
	if (search_char_in_str(cmd_line, '>'))
		while (cmd_line[++i])
			if (cmd_line[i] == '>' && cmd_line[i + 1] != '>')
				if (!is_between_double_quotes(cmd_line, i))
					nb++;
	return (nb);
}

/**
 * @brief Returns an array of ints with the positions
 *  of each '>' chars found in the command line.
 * 
 * @param cmd_line Command line.
 * @param cmd Struct
 * @return An array of ints with the positions of each '>' chars.
 */
int	*get_output_char_positions(char *cmd_line, t_cmd *cmd)
{
	int	i;
	int	pos;
	int	*output_pos;

	i = -1;
	pos = 0;
	output_pos = malloc((cmd->nb_outputs + 1) * sizeof(int));
	if (!output_pos)
		return (NULL);
	while (cmd_line[++i])
	{
		if ((!is_between_double_quotes(cmd_line, i))
			&& (cmd_line[i] == '>' && cmd_line[i - 1] != '>'))
			output_pos[pos++] = i;
	}
	return (output_pos);
}
