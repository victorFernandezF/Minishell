/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 19:24:11 by victofer          #+#    #+#             */
/*   Updated: 2023/06/29 18:03:22 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	print_errors_by_code(int code, t_env *env)
{
	char	*msg;

	if (code == 1)
		msg = "Syntax error.";
	else if (code == 2)
		msg = "Syntax error near unexpected token `newline'";
	else if (code == 3)
		msg = "Syntax error near unexpected token `|'";
	else
		msg = "Error.";
	ft_putendl_fd(msg, 2);
	set_env(env, "?", "1");
	return (code);
}
