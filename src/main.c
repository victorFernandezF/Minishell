/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:50:03 by victofer          #+#    #+#             */
/*   Updated: 2023/05/22 18:56:09 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	main(void)
{
	t_cmd	*cmd;
	char	*read;

	atexit(leaks);
	cmd = NULL;
	cmd = init_struct(cmd);
	while (1)
	{
		read = readline("[MINISHELL]: ");
		cmd = start_parser(cmd, read);
		print_test(read, cmd, 0);
	}
	if (cmd != NULL)
		free_struct(cmd);
	return (0);
}
