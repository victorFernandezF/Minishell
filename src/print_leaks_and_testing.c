/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_leaks_and_testing.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:02:52 by victofer          #+#    #+#             */
/*   Updated: 2023/05/08 19:19:50 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/* 
 * print_test
 * ----------------------------
 *	Prints all elements of the struct cms
 *	JUST FOR TESTING.
 */

void	print_test(char *str, t_cmd *cmd, int repeat)
{
	int		i;

	i = -1;
	if (repeat == 0)
		printf("%s LINE -> %s%s\n\n", BM, W, str);
	printf("%s◼︎ [ NODE %i ] %s\n", B, cmd->index, W);
	printf("%s⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽%s\n\n", B, W);
	printf("%s ● COMMAND ..... ➤%s %s\n", Y, W, cmd->cmd);
	printf("%s ● FLAGS ....... ➤%s %s\n", Y, W, cmd->flags);
	printf("%s ● NODE ID ..... ➤%s %d\n", Y, W, cmd->index);
	while (cmd->params[++i] != NULL)
		printf("%s ● PARAM [%s%i%s] ... ➤%s %s\n", Y, B, i,
			Y, W, cmd->params[i]);
	printf("%s ● NB OUTPUTS .. ➤%s %i\n", Y, W, cmd->nb_outputs);
	i = -1;
	while (++i < cmd->nb_outputs)
		printf("%s ● OUTPUT FD [%s%i%s] ➤%s %i\n",
			Y, B, i, Y, W, cmd->output[i]);
	printf("%s ● NB INPUTS ... ➤%s %i\n", Y, W, cmd->nb_inputs);
	printf("%s ● LAST INPUT FD ➤%s %i\n", Y, W, cmd->input);
	printf("\n");
	if (cmd->next != NULL)
		print_test(str, cmd->next, 1);
}

void	leaks(void)
{
	printf("%s⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽\n%s", BM, W);
	printf("%s|  LEAKYS  | %s\n", BM, W);
	printf("%s⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺%s\n", BM, W);
	system("leaks -q minishell");
}
