/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 18:11:40 by victofer          #+#    #+#             */
/*   Updated: 2023/06/15 10:37:06 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Sets the components of the line into the struct.
 * 
 * @param tmp The struct created in main.
 * @param command An string whith the given command
 * @return The given struct filled with the datas from line.
 */
t_cmd	*fill_struct(t_cmd *tmp, char *command, t_env *envar)
{
	t_cmd	*new;
	char	*expanded;
	char	*no_outputs;
	char	*no_output_input;

	new = tmp;
	expanded = expand_environment_variables(command, envar);
	no_outputs = delete_outputs_from_line(expanded);
	no_output_input = delete_inputs_from_line(no_outputs);
	new->nb_outputs = get_nb_outputs(expanded);
	new->nb_inputs = get_nb_inputs(expanded);
	if (ft_strlen(no_output_input) == 0)
	{
		free_parser(no_output_input, no_outputs, expanded);
		return (new);
	}
	if (new->nb_outputs > 0)
		new->output = get_output(expanded, new);
	new->cmd = get_cmd(no_output_input);
	new->flags = get_flags(no_outputs);
	if (new->nb_inputs > 0)
		new->input = get_input(expanded, new);
	new->params = get_parameters(no_output_input);
	free_parser(no_output_input, no_outputs, expanded);
	return (new);
}

char	*manage_heredoc(char *str, t_env *envar)
{
	int		i;
	int		len;
	char	*new;
	char	*temporal;
	char	**arr;

	i = -1;
	temporal = heredoc_signs_without_spaces(str);
	arr = ft_split_minishell(temporal, 0);
	free(temporal);
	while (arr[++i])
	{
		if (arr[i][0] == '<' && arr[i][1] == '<')
		{
			new = ft_copy_str(arr[i]);
			free(arr[i]);
			arr[i] = heredoc(new, envar);
			free (new);
		}
	}
	len = get_total_length_of_words_in_array(arr);
	new = ft_splitnt(arr, len);
	free_array(arr);
	return (new);
}

/**
 * @brief Separates the different parts of the commmand line
 *	and save them in the given structure.
 * 
 * @param cmd Struct
 * @param cmd_line Line with the command 
 * @return Given struct whith all elements from cmd_line.
 */
t_cmd	*start_parser(t_cmd *cmd, char *cmd_line, t_env *envar)
{
	int		i;
	int		nb_cmd;
	char	*tmp;
	char	**command;

	nb_cmd = get_nb_cmd(cmd_line);
	cmd->nb_cmd = nb_cmd;
	command = ft_split(cmd_line, '|');
	i = -1;
	while (command[++i])
	{
		if (heredoc_detector(command[i]))
		{
			tmp = command[i];
			free(command[i]);
			command[i] = manage_heredoc(tmp, envar);
		}
	}
	cmd = fill_struct(cmd, command[0], envar);
	i = 0;
	if (nb_cmd > 1)
		while (command[++i] != NULL)
			cmd = add_new_node_to_the_list(cmd, command[i], i + 1, envar);
	free_array(command);
	return (cmd);
}
