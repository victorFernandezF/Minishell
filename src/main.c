/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:50:03 by victofer          #+#    #+#             */
/*   Updated: 2023/04/20 13:01:51 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv)
{
	t_cmd	*cmd;
	int		i;

	atexit(leaks);
	cmd = NULL;
	i = -1;
	if (argc >= 2)
		cmd = start_parser(cmd, argv[1]);
	print_test(cmd);
	free_struct(cmd);
	return (0);
}
