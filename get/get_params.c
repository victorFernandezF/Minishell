/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:08:41 by victofer          #+#    #+#             */
/*   Updated: 2023/05/10 18:02:25 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_params_after_out(char *str, t_cmd *cmd)
{
	int		i;
	int		j;
	int		*pos;

	i = -1;
	pos = get_output_char_positions(str, cmd);
	while (++i < cmd->nb_outputs)
	{
		j = pos[i];
		j = skip_characters_and_spaces(str, j);
		j++;
	}
	return (NULL);
}

static	char	*fill_param(char *param, char *str, int i)
{
	int	j;
	int	size;

	j = 0;
	size = ft_strlen(str) - i;
	param = malloc((size + 1) * sizeof(char));
	while (!is_redirect(str[i]) && str[i] != '\0')
		param[j++] = str[i++];
	param[j] = '\0';
	return (param);
}

/* 
 * get_cmd
 * ----------------------------
 *	Splits the name of the command from the given string
 *
 *	PARAMS:
 *	-> str: string given by user.
 *
 * 	RETURN
 *	-> A string with the command name.
 */
char	*get_params(char *str)
{
	int		i;
	int		last_flag;
	char	*param;

	i = 0;
	param = NULL;
	last_flag = 0;
	i = skip_characters_and_spaces(str, i);
	if (str[i] == '-')
	{
		last_flag = i;
		while (str[++i])
		{
			if (str[i] == '-')
			{
				i = skip_characters(str, i);
				last_flag = i;
			}
		}
	}
	last_flag = skip_characters(str, last_flag);
	i = skip_characters(str, last_flag);
	i++;
	param = fill_param(param, str, last_flag);
	return (param);
}
