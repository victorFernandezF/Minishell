/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 15:15:22 by fortega-          #+#    #+#             */
/*   Updated: 2023/07/28 09:20:28 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	*get_lexde(t_env *env);

char	ft_atoi_test_nums(char *str)
{
	int			i;

	i = 0;
	if ((str[i] == '-' || str[i] == '+')
		|| (str[i] >= '0' && str[i] <= '9'))
		i++;
	else
		return ('f');
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return ('f');
	}
	return ('r');
}

long int	ft_atoi_test_int(char *str)
{
	int			i;
	int			s;
	long int	total;

	i = 0;
	s = 1;
	total = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			s = -s;
		i++;
	}
	if (!str[i])
		return (2147483648);
	while (str[i] >= '0' && str[i] <= '9')
	{
		total = total * 10 + (str[i] - '0');
		i++;
	}
	return (total * s);
}

int	ft_exit(t_cmd *cmd, t_env *env)
{
	char	*tmp;

	if ((!cmd->params || !cmd->params[0]
			|| cmd->params[0][0] == '\0'))
	{
		exit(ft_atoi(get_lexde(env)));
	}
	if (n_params(cmd->params) > 1)
		return (cmd_error("exit", "too many arguments", env));
	if (ft_atoi_test_nums(cmd->params[0]) == 'f')
	{
		printf("exit\n");
		tmp = ft_strjoin(cmd->params[0], ": numeric argument required");
		cmd_cd_error("exit", tmp, env);
		exit (255);
	}
	closeback(cmd);
	exit (ft_atoi(cmd->params[0]));
	return (EXIT_SUCCESS);
}
