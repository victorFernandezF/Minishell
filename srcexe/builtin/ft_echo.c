/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 17:28:13 by fortega-          #+#    #+#             */
/*   Updated: 2023/06/21 17:50:44 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/*int	print_echo(t_cmd *cmd, bool n)
{

}*/

int	ft_echo(t_cmd *cmd)
{
	if (cmd->flags)
	{
		if (!(ft_strncmp("-n", cmd->flags, ft_strlen("-n"))))
		{
			printf("-n\n");
			return (0);
		}
		else
			cmd_error("echo", "Only -n flag\n");
	}
	else
	{
		printf("Sin flag\n");
		return (0);
	}
	return (0);
}
