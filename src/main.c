/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:50:03 by victofer          #+#    #+#             */
/*   Updated: 2023/05/23 19:20:30 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	count_words(char *str);

int	main(void)
{
	t_cmd	*cmd;
	char	*read;
	char	**test;

	atexit(leaks);
	cmd = NULL;
	cmd = init_struct(cmd);
	while (1)
	{
		read = readline("\x1B[32m[MINISHELL]: \x1B[0m");
		if (read[0] != '\0')
			add_history(read);
		if (read[0])
		{
			test = ft_split_2(read);
			//printf("%s\n", test[2]);
			cmd = start_parser(cmd, read);
			print_test(read, cmd, 0);
		}
	}
	if (cmd != NULL)
		free_struct(cmd);
	return (0);
}
