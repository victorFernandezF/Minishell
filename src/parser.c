/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 18:11:40 by victofer          #+#    #+#             */
/*   Updated: 2023/07/12 12:38:00 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	get_redirections(char *expa, t_cmd *cmd, t_env *env)
{
	if (cmd->nb_outputs > 0)
		get_output(expa, cmd, env);
	if (cmd->nb_inputs > 0)
		get_input(expa, cmd, env);
}

/**
 * @brief Sets the components of the line into the struct.
 * 
 * @param tmp The struct created in main.
 * @param command An string whith the given command
 * @return [t_cmd *] The given struct filled with the datas from line.
 */
void	fill_struct(t_cmd *cmd, char *command, t_env *env)
{
	char	*expanded;
	char	*aux;

	expanded = expand_environment_variables(command, env);
	aux = ft_copy_str(expanded);
	cmd->nb_outputs = get_nb_outputs(expanded);
	cmd->nb_inputs = get_nb_inputs(expanded);
	if (cmd->nb_outputs > 0)
		expanded = delete_outputs_from_line(expanded, 1);
	if (cmd->nb_inputs > 0)
		expanded = delete_inputs_from_line(expanded);
	if (ft_strlen(expanded) == 0)
		cmd->error = 2;
	expanded = get_cmd(expanded, cmd);
	expanded = get_flags(expanded, command, cmd);
	expanded = get_parameters(expanded, cmd, env);
	get_redirections(aux, cmd, env);
	free(expanded);
	free(aux);
}

/**
 * @brief If a heredoc is found. the function creates a temp
 * file to store the heredoc.
 * 
 * @param str 
 * @param envar 
 * @return [Char *] Command with the heredoc replaced by a normal input.
 */
char	*manage_heredoc(char *str, t_env *envar)
{
	int		i;
	int		len;
	char	*new;
	char	*temp;
	char	**array;

	i = -1;
	temp = heredoc_signs_without_spaces(str);
	array = ft_split_minishell(temp, 0);
	free(temp);
	while (array[++i])
	{
		if (array[i][0] == '<' && array[i][1] == '<')
		{
			new = ft_copy_str(array[i]);
			free(array[i]);
			array[i] = heredoc(new, envar);
			free (new);
		}
	}
	len = get_total_length_of_words_in_array(array);
	new = ft_splitnt(array, len, 0);
	free_array(array);
	free(str);
	return (new);
}

/**
 * @brief Split command by pipes only if the pipe is not inside quotes
 * 
 * @param str 
 * @return [Char **] An array with the different commands found in str. 
 */
static char	**split_by_pipes(char *str)
{
	int		i;
	int		j;
	char	**arr;

	i = -1;
	while (str[++i])
		if (str[i] == '|')
			if (is_between_double_quotes(str, i)
				|| is_between_simple_quotes(str, i))
				str[i] = 25;
	arr = ft_split(str, '|');
	i = -1;
	while (arr[++i])
	{
		j = -1;
		while (arr[i][++j])
			if (arr[i][j] == 25)
				arr[i][j] = '|';
	}
	return (arr);
}

/**
 * @brief Separates the different parts of the commmand line
 *	and save them in the given structure.
 * 
 * @param cmd Struct
 * @param cmd_line Line with the command 
 * @return [t_cmd *] Given struct whith all elements from cmd_line.
 */
void	start_parser(t_cmd *cmd, char *cmd_line, t_env *envar)
{
	int		i;
	int		nb_cmd;
	char	*aux_var;
	char	**command;

	i = -1;
	nb_cmd = get_nb_cmd(cmd_line);
	cmd->nb_cmd = nb_cmd;
	command = split_by_pipes(cmd_line);
	while (command[++i])
	{
		if (heredoc_detector(command[i]))
		{
			aux_var = ft_copy_str(command[i]);
			free(command[i]);
			command[i] = manage_heredoc(aux_var, envar);
		}
	}
	fill_struct(cmd, command[0], envar);
	i = 0;
	if (nb_cmd > 1)
		while (command[++i] != NULL)
			add_new_node_to_the_list(cmd, command[i], i + 1, envar);
	free_array(command);
}
