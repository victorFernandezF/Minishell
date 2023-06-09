/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 12:12:27 by victofer          #+#    #+#             */
/*   Updated: 2023/07/11 11:34:09 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Counts the number of '<' inputs chars found in command line.
 * 
 * @param cmd_line command_line 
 * @return [Int] Number of inputs found. 
 */
int	get_nb_inputs(char *cmd_line)
{
	int	i;
	int	nb;

	i = -1;
	nb = 0;
	if (search_char_in_str(cmd_line, '<'))
		while (cmd_line[++i])
			if (cmd_line[i] == '<' && cmd_line[i + 1] != '<')
				if (!is_between_double_quotes(cmd_line, i))
					nb++;
	return (nb);
}

/**
 * @brief Check if every input found in command line exists
 * and can be opened, somethin goes wrong prints an erros.
 * If everything is fine, returns the last input file converted to fd.
 * 
 * @param cmd_line command_line
 * @param cmd Struct
 * @return [Int] A fd of the last input found.
 */
int	get_input(char *cmd_line, t_cmd *cmd, t_env *env)
{
	int		i;
	int		*in_pos;
	int		last_input;
	int		*inputs_fd;
	char	**input;

	in_pos = get_input_char_positions(cmd_line, cmd);
	input = malloc((cmd->nb_inputs + 1) * sizeof(char **));
	if (!input)
		return (0);
	i = -1;
	while (++i < cmd->nb_inputs)
		input[i] = get_input_from_pos(cmd_line, in_pos[i], cmd, env);
	input[i] = NULL;
	if (cmd->error == 1)
		return (free_redirection(in_pos, NULL, input), 0);
	inputs_fd = input_filename_to_fd(input, cmd->nb_inputs, cmd, env);
	last_input = inputs_fd[cmd->nb_inputs - 1];
	cmd->array_input = inputs_fd;
	free_redirection(in_pos, inputs_fd, input);
	if (cmd->nb_inputs == 0)
		return (0);
	cmd->input = last_input;
	return (1);
}

/**
 * @brief Gets the input filename depending on the 
 *	position of the character '<' in the string.
 * 
 * @param cmd_line command_line
 * @param pos Position where input starts.
 * @return [Char *] A string with the input filename. 
 */
char	*get_input_from_pos(char *cmd_line, int pos, t_cmd *cmd, t_env *env)
{
	int		i;
	int		aux;
	char	*input;

	aux = pos + 1;
	i = strlen_starting_in(cmd_line, pos + 1);
	input = malloc((i + 1) * sizeof(char));
	i = 0;
	if (cmd_line[aux] == '>')
	{
		aux ++;
		input[0] = '>';
		i++;
	}
	aux = skip_whitespaces(cmd_line, aux);
	while (cmd_line[aux] != ' ' && cmd_line[aux] != '\0')
	{
		input[i] = cmd_line[aux];
		aux++;
		i++;
	}
	input[i] = '\0';
	if (env_var_detector(input))
		print_error_file_ambiguous(input, cmd, env);
	return (input);
}

/**
 * @brief Transforms each input filename into a file descriptor (in read mode).
 *	If the file does not exist, prints a message.
 * 
 * @param input An array of strings with every inputs filenames.
 * @param nb_inputs The number of input filenames found in command line.
 * @return [Int *] An array with the files descriptor (fd's) of each input file. 
 */
int	*input_filename_to_fd(char **input, int nb_in, t_cmd *cmd, t_env *env)
{
	int		i;
	int		*res;

	i = -1;
	res = malloc((nb_in) * sizeof(int));
	if (!res)
		return (NULL);
	while (++i < nb_in)
	{
		res[i] = open(input[i], O_RDWR);
		if (res[i] == -1)
		{
			print_error_file(input[i], "No such file or directory", env);
			cmd->error = 1;
		}
	}
	return (res);
}

/**
 * @brief Searchs each '<' in command line and returns an array
 *	of ints whith their positions in the string.
 * 
 * @param cmd_line Command_line
 * @param cmd Struct.
 * @return [Int *] Array of ints whith the positions of each '<' in the string.
 */
int	*get_input_char_positions(char *cmd_line, t_cmd *cmd)
{
	int	i;
	int	pos;
	int	*input_pos;

	i = -1;
	pos = 0;
	input_pos = malloc((cmd->nb_inputs) * sizeof(int));
	if (!input_pos)
		return (NULL);
	while (cmd_line[++i])
	{
		if ((!is_between_double_quotes(cmd_line, i))
			&& (cmd_line[i] == '<' && cmd_line[i - 1] != '<'))
			input_pos[pos++] = i;
	}
	return (input_pos);
}
