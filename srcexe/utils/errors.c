/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:53:21 by fortega-          #+#    #+#             */
/*   Updated: 2023/06/13 14:11:20 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	cmd_error(char *cmd, char *error)
{
	char	*print;

	print = ft_strdup("minishell: ");
	print = ft_strjoin(print, cmd);
	print = ft_strjoin(print, ": ");
	print = ft_strjoin(print, error);
	ft_putendl_fd(print, STDERR_FILENO);
	free(print);
	return (EXIT_FAILURE);
}
