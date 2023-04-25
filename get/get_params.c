/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:08:41 by victofer          #+#    #+#             */
/*   Updated: 2023/04/25 09:54:05 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*fill_param_out(char *res, char *param, char *str, int i)
{
	int	j;

	j = -1;
	while (param[++j])
		res[j] = param[j];
	while (str[i])
		res[j++] = str[i++];
	res[j] = '\0';
	return (res);
}

char	*get_params_after_out(char *param, char *str)
{
	int		i;
	int		last;
	int		start;
	char	*res;

	last = 0;
	i = ft_strlen(str) -1;
	while (str[i])
	{
		if (str[i] == '>')
		{
			last = i;
			break ;
		}
		i--;
	}
	last++;
	last = skip_whitespaces(str, last);
	last = skip_characters(str, last);
	last++;
	start = last;
	while (str[last])
		last++;
	res = malloc((last - start + 1) * sizeof(char));
	res = fill_param_out(res, param, str, start);
	free(param);
	return (res);
}

static	char	*fill_param(char *param, char *str, int i, int last_flag)
{
	int	j;

	j = 0;
	param = malloc((i - last_flag + 1) * sizeof(char));
	while (!is_redirect(str[last_flag]) && str[last_flag] != '\0')
		param[j++] = str[last_flag++];
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
	i = skip_characters(str, i);
	i = skip_whitespaces(str, i);
	if (str[i] == '-')
	{
		while (str[++i])
		{
			if (str[i] == '-')
			{
				i = skip_characters(str, i);
				last_flag = i;
			}
		}
	}
	if (last_flag == 0)
		last_flag = skip_characters(str, last_flag);
	i = skip_whitespaces(str, i);
	param = fill_param(param, str, i, last_flag);
	return (param);
}
