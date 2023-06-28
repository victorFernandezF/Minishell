/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 19:24:11 by victofer          #+#    #+#             */
/*   Updated: 2023/06/28 19:30:03 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	print_error(char *errname, char *msg, int code)
{
	if (msg != NULL)
	{
		ft_putstr_fd(errname, 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(msg, 2);
		return (code);
	}
	ft_putendl_fd(errname, 2);
	return (code);
}
