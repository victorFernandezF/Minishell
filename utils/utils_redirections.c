/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_redirections.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 18:57:23 by victofer          #+#    #+#             */
/*   Updated: 2023/06/02 11:23:46 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"

/**
 * @brief Auxiliar function to help 'delete_outputs_from_line'
 *	filling a string.
 * 
 * @param array An array with every element except outputs.
 * @param len Length of the future string.
 * @return A string. 
 */
char	*get_string_without_outputs(char **array, int len)
{
	int		j;
	int		i;
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
		if (array[i][0] == '>')
			continue ;
		while (array[i][++j])
			res[x++] = array[i][j];
		res[x++] = ' ';
	}
	res[x - 1] = '\0';
	return (res);
}

/**
 * @brief Auxiliar function to help 'delete_outputs_from_line'
 *	filling a string.
 * 
 * @param array An array with every element except outputs.
 * @param len Length of the future string.
 * @return A string. 
 */
char	*get_string_without_inputs(char **array, int len)
{
	int		j;
	int		i;
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
		if (array[i][0] == '<')
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
 * @return An int with the position of the last occurrency of c in str.
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
 * @brief Creates a new string with everithing except cmd name and flags.
 *	The redirection characters are followed by '_'
 *	(ex: line 'echo -n hello > out world' will become 'hello >_out world')
 * 
 * @param cmd_line Line with the command line. 
 * @return String that contains everithing except cmd name and flags
 *	and the redirection characters are followed by '_'.
 */
char	*replace_spaces_after_redirect(char *cmd_line)
{
	int		i;
	int		j;
	int		len;
	char	*res;

	i = 0;
	len = strlen_starting_in(cmd_line, i);
	res = malloc((len + 1) * sizeof(char));
	j = 0;
	i = -1;
	while (cmd_line[++i])
	{
		if ((!is_between_quotes(cmd_line, i))
			&& ((cmd_line[i] == '>' && cmd_line[i + 1] == ' ')
				|| (cmd_line[i] == '<' && cmd_line[i + 1] == ' ')))
		{
			res[j] = cmd_line[i];
			res[j + 1] = '_';
			j += 2;
			i += 2;
		}
		res[j++] = cmd_line[i];
	}
	res[j] = '\0';
	return (res);
}

/**
 * @brief Returns a string with everything except outputs.
 * 
 * @param cmd_line Command line. 
 * @return String with everything except outputs.
 */
char	*delete_outputs_from_line(char *cmd_line)
{
	int		i;
	int		len;
	char	*tmp;
	char	**array;
	char	*res;

	i = -1;
	len = 0;
	tmp = replace_spaces_after_redirect(cmd_line);
	array = ft_split_minishell(tmp, 1);
	while (array[++i])
	{
		if (array[i][0] == '>')
			continue ;
		len += ft_strlen(array[i]);
		len += 1;
	}
	if (len == 0)
		len++;
	res = get_string_without_outputs(array, len);
	free(tmp);
	free_array(array);
	return (res);
}

/**
 * @brief Returns a string with everything except inputs.
 * 
 * @param cmd_line Command line. 
 * @return String with everything except input.
 */
char	*delete_inputs_from_line(char *cmd_line)
{
	int		i;
	int		len;
	char	*tmp;
	char	**array;
	char	*res;

	i = -1;
	len = 0;
	tmp = replace_spaces_after_redirect(cmd_line);
	array = ft_split_minishell(tmp, 1);
	while (array[++i])
	{
		if (array[i][0] == '<')
			continue ;
		len += ft_strlen(array[i]);
		len += 1;
	}
	if (len == 0)
		len++;
	res = get_string_without_inputs(array, len);
	free(tmp);
	free_array(array);
	return (res);
}
