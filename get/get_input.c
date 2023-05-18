/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 12:12:27 by victofer          #+#    #+#             */
/*   Updated: 2023/05/18 19:07:12 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/* 
 * get_input (get/get_input.c)
 * ----------------------------
 *	Gets every input file found in command line, check if all
 *	of them exists and can be opened. Then returns an int
 *	with the last input file converted to fd (file descriptor).
 *
 *	PARAMS:
 *	-> str: string given by user.
 *	-> cmd: struct.
 *
 * 	RETURN
 *	-> An integer of ints with the last input file converted
 *		to fd (file descriptor).
 */
int	get_input(char *str, t_cmd *cmd)
{
	int		*inputs_fd;
	int		*input_pos;
	int		last_input;
	char	**input;
	int		i;

	input_pos = get_input_char_positions(str, cmd);
	input = malloc((cmd->nb_inputs + 1) * sizeof(char **));
	if (!input)
		return (0);
	i = -1;
	while (++i < cmd->nb_inputs)
		input[i] = get_input_from_position(input[i], str, input_pos[i]);
	input[i] = NULL;
	inputs_fd = input_filename_to_fd_converter(input, cmd->nb_inputs);
	last_input = inputs_fd[cmd->nb_inputs - 1];
	free(input_pos);
	free(inputs_fd);
	free_array(input);
	if (cmd->nb_inputs == 0)
		return (0);
	return (last_input);
}

/* 
 * get_input_from_position (get/get_input.c)
 * ----------------------------
 *	Gets the input filename (ex: test.txt) depending on the 
 *	position of the character '<' in the string.
 *
 *	PARAMS:
 *	-> input: A String where the result will be stored.
 *	-> str: string given by user.
 *	-> pos: position of character '<'.
 *
 * 	RETURN
 *	-> A String with the input filename.
 */
char	*get_input_from_position(char *input, char *str, int pos)
{
	int		i;
	int		aux;

	i = 0;
	aux = pos + 1;
	while (str[++pos])
		i++;
	input = malloc((i + 1) * sizeof(char));
	i = 0;
	if (str[aux] == '>')
	{
		aux ++;
		input[0] = '>';
		i++;
	}
	aux = skip_whitespaces(str, aux);
	while (str[aux] != ' ' && str[aux] != '\0')
	{
		input[i] = str[aux];
		aux++;
		i++;
	}
	input[i] = '\0';
	return (input);
}

/* 
 * input_filename_to_fd_converter (get/get_input.c)
 * ----------------------------
 *	Transforms each input filename into a file descriptor (in read mode).
 *	If the file does not exist, prints a message.
 *
 *	PARAMS:
 *	-> input: An array of strings with every inputs filenames.
 *	-> nb_inputs: The number of input filenames found in command line.
 *	-> cmd: struct.
 *
 * 	RETURN
 *	-> An array of ints filled with the file descriptors of each
 *		input files.
 */
int	*input_filename_to_fd_converter(char **input, int nb)
{
	int		i;
	int		j;
	int		*res;

	i = -1;
	j = 0;
	res = malloc((nb + 1) * sizeof(int));
	if (!res)
		return (NULL);
	while (++i < nb)
	{
		res[i] = open(input[i], O_RDWR);
		if (res[i] == -1)
		{
			print_error_file(input[i], "No such file or directory");
		}
	}
	return (res);
}

/* 
 * get_nb_inputs (get/get_input.c)
 * ----------------------------
 *	Counts the number of '<' inputs chars found in command line.
 *
 *	PARAMS:
 *	-> str: Command line.
 *
 * 	RETURN
 *	-> The number of '<' found in the command line. 
 *		In other words, the number of inputs files found.
 */
int	get_nb_inputs(char *str)
{
	int	i;
	int	nb;

	i = -1;
	nb = 0;
	if (are_there_char(str, '<'))
		while (str[++i])
			if (str[i] == '<' && str[i + 1] != '<')
				nb++;
	return (nb);
}

/* 
 * get_input_char_positions (get/get_input.c)
 * ----------------------------
 *	Searchs each '<' in command line and returns an array
 *	of ints whith their positions in the string.
 *
 *	PARAMS:
 *	-> str: the command line given by user.
 *	-> cmd: struct.
 *
 * 	RETURN
 *	-> An array of ints filled with the positions of chars
 * 		'<' in command line.
 */
int	*get_input_char_positions(char *str, t_cmd *cmd)
{
	int	*input_pos;
	int	i;
	int	pos;

	i = -1;
	input_pos = malloc((cmd->nb_inputs + 1) * sizeof(int));
	if (!input_pos)
		return (NULL);
	pos = 0;
	while (str[++i])
	{
		if (str[i] == '<' && str[i - 1] != '<')
			input_pos[pos++] = i;
	}
	return (input_pos);
}
