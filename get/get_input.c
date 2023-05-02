/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 12:12:27 by victofer          #+#    #+#             */
/*   Updated: 2023/05/02 19:00:29 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/* 
 * get_input
 * ----------------------------
 *	Splits the flags of the command from the given string
 *
 *	PARAMS:
 *	-> str: string given by user.
 *
 * 	RETURN
 *	-> A string with the flags name.
 */
int	*get_input(char *str, t_cmd *cmd)
{
	int		*inputs_fd;
	int		*input_pos;
	char	**input;
	int		i;
	int		j;

	input_pos = get_nb_input(str);
	cmd->nb_inputs = input_pos[0];
	input = malloc((input_pos[0] + 1) * sizeof(char **));
	i = -1;
	j = 1;
	while (++i < input_pos[0])
		input[i] = get_input_from_pos(input[i], str, input_pos[j++]);
	input[i] = NULL;
	inputs_fd = str_to_fd_converter_in(input, input_pos[0], cmd);
	i = 0;
	free(input_pos);
	free_array(input);
	return (inputs_fd);
}

char	*get_input_from_pos(char *input, char *str, int pos)
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

int	*str_to_fd_converter_in(char **input, int nb, t_cmd *cmd)
{
	int		i;
	int		j;
	int		*res;

	i = -1;
	j = 0;
	res = malloc((nb + 1) * sizeof(int));
	while (++i < nb)
	{
		res[i] = open(input[i], O_RDWR);
		if (res[i] == -1)
		{
			print_error_file(input[i], "No such file or directory", cmd);
		}
	}
	return (res);
}

static int	*fill_input_pos(int *inputput_pos, char *str)
{
	int	pos;
	int	i;

	pos = 1;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '<' && str[i - 1] != '<')
			inputput_pos[pos++] = i;
	}
	return (inputput_pos);
}

int	*get_nb_input(char *str)
{
	int	*input_pos;
	int	i;
	int	nb;

	i = -1;
	nb = 0;
	input_pos = NULL;
	if (are_there_char(str, '<'))
	{
		while (str[++i])
			if (str[i] == '<' && str[i + 1] != '<')
				nb++;
		input_pos = malloc((nb + 1) * sizeof(int));
		if (!input_pos)
			return (NULL);
		input_pos[0] = nb;
		input_pos = fill_input_pos(input_pos, str);
		return (input_pos);
	}
	input_pos = malloc(1 * sizeof(int));
	input_pos[0] = nb;
	return (input_pos);
}
