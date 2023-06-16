/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- < fortega-@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 13:53:21 by fortega-          #+#    #+#             */
/*   Updated: 2023/06/16 21:42:31 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	cmd_error(char *cmd, char *error)
{
	char	*one;
	char	*two;
	char	*three;
	char	*print;

	one = ft_strdup("minishell: ");
	two = ft_strjoin(one, cmd);
	free(one);
	three = ft_strjoin(two, ": ");
	free(two);
	print = ft_strjoin(three, error);
	free(three);
	ft_putendl_fd(print, STDERR_FILENO);
	free(print);
	return (EXIT_FAILURE);
}

int	cmd_cd_error(char *cmd, char *error)
{
	char	*one;
	char	*two;
	char	*three;
	char	*print;

	one = ft_strdup("minishell: ");
	two = ft_strjoin(one, cmd);
	free(one);
	three = ft_strjoin(two, ": ");
	free(two);
	print = ft_strjoin(three, error);
	free(error);
	free(three);
	ft_putendl_fd(print, STDERR_FILENO);
	free(print);
	return (EXIT_FAILURE);
}
