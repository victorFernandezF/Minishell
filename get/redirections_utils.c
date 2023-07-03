/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:57:23 by victofer          #+#    #+#             */
/*   Updated: 2023/06/29 19:12:09 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"

void	check_error_to_open(t_cmd *cmd, t_env *env, int res, char *output)
{
	if (res == -1)
	{
		print_error_file(output, "No such file or directory", env);
		cmd->error = 1;
	}
}

/**
 * @brief Auxiliar function to help 'delete_outputs_from_line'
 *	filling a string.
 * 
 * @param array An array with every element except outputs.
 * @param len Length of the future string.
 * @return [Char *] A string. 
 */
static char	*get_string_without_redir(char **array, int len, char sign)
{
	int		i;
	int		j;
	int		x;
	char	*res;

	x = 0;
	res = malloc(len * sizeof(char));
	if (!res)
		return (NULL);
	i = -1;
	while (array[++i])
	{
		j = -1;
		if (array[i][0] == sign)
			continue ;
		while (array[i][++j])
			res[x++] = array[i][j];
		res[x++] = ' ';
	}
	res[x - 1] = '\0';
	return (res);
}

/**
 * @brief Gets the position of the last occurrency of a char
 *	in a string.
 * 
 * @param str string in which c will be searched.
 * @param c Char that will bi searched inside str.
 * @return [Int] The position of the last occurrency of c in str.
 */
int	get_position_of_last_char_found(char *str, char c)
{
	int	i;
	int	pos;

	i = 0;
	pos = 0;
	i = skip_characters(str, i);
	i = skip_whitespaces(str, i);
	while (str[i])
	{
		if (str[i] == c)
			pos = i;
		i = skip_characters(str, i);
		i = skip_whitespaces(str, i);
		if (str[i] != c)
			break ;
	}
	return (pos);
}

/**
 * @brief Returns a string with everything except outputs.
 * 
 * @param cmd_line Command line. 
 * @return [Char *] String with everything except outputs.
 */
char	*delete_outputs_from_line(char *cmd_line)
{
	int		i;
	int		len;
	char	**array;
	char	*no_spaces;
	char	*no_outputs;

	i = -1;
	len = 0;
	no_spaces = replace_spaces_after_redirect(cmd_line);
	array = ft_split_minishell(no_spaces, 1);
	while (array[++i])
	{
		if (array[i][0] == '>')
			continue ;
		len += ft_strlen(array[i]);
		len += 1;
	}
	if (len == 0)
		len++;
	no_outputs = get_string_without_redir(array, len, '>');
	free_array_and_str(array, no_spaces);
	return (no_outputs);
}

/**
 * @brief Returns a string with everything except inputs.
 * 
 * @param cmd_line Command line. 
 * @return [Char *] String with everything except input.
 */
char	*delete_inputs_from_line(char *cmd_line)
{
	int		i;
	int		len;
	char	**array;
	char	*no_space;
	char	*no_inputs;

	i = -1;
	len = 0;
	no_space = replace_spaces_after_redirect(cmd_line);
	array = ft_split_minishell(no_space, 1);
	while (array[++i])
	{
		if (array[i][0] == '<')
			continue ;
		len += ft_strlen(array[i]);
		len += 1;
	}
	if (len == 0)
		len++;
	no_inputs = get_string_without_redir(array, len, '<');
	free_array_and_str(array, no_space);
	return (no_inputs);
}
