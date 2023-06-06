/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_leaks_and_testing.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:02:52 by victofer          #+#    #+#             */
/*   Updated: 2023/06/06 18:26:13 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Prints every par of the struct [TEMPORAL]
 * 
 * @param str 
 * @param cmd 
 * @param repeat 
 */
void	print_test(char *str, t_cmd *cmd, int repeat)
{
	int		i;

	i = -1;
	(void)repeat;
	(void)str;
	printf("%s\n■ [ NODE %i ] %s\n", B, cmd->index, W);
	printf("%s⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽%s\n\n", B, W);
	printf("%s ● NODE ID ..... ➤%s (%d)%s\n", Y, BG, cmd->index, W);
	printf("%s ● NB CMD  ..... ➤%s %i\n", Y, W, cmd->nb_cmd);
	printf("%s ● COMMAND ..... ➤%s %s\n", Y, W, cmd->cmd);
	printf("%s ● FLAGS ....... ➤%s %s\n", Y, W, cmd->flags);
	if (cmd->params != NULL)
		while (cmd->params[++i] != NULL)
			printf("%s ● PARAM [%s%i%s] ... ➤%s %s\n", Y, B, i,
				Y, W, cmd->params[i]);
	printf("%s ● NB INPUTS ... ➤%s %i\n", Y, W, cmd->nb_inputs);
	printf("%s ● LAST INPUT FD ➤%s %i\n", Y, W, cmd->input);
	printf("%s ● NB OUTPUTS .. ➤%s %i\n", Y, W, cmd->nb_outputs);
	printf("%s ● OUTPUT FD ... ➤%s %i\n", Y, W, cmd->output);
	printf("\n");
	if (cmd->next != NULL)
		print_test(str, cmd->next, 1);
}

void	print_array(char **array)
{
	int	i;

	i = -1;
	printf("\nARRAY PRITNTATION\n");
	while (array[++i])
		printf("%sarr[%i]:%s %s\n", G, i, W, array[i]);
}

/**
 * @brief Shows the leaks [TEMPORAL]
 * 
 */
void	leaks(void)
{
	printf("%s⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽⎽\n%s", BM, W);
	printf("%s|  LEAKYS  | %s\n", BM, W);
	printf("%s⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺⎺%s\n", BM, W);
	system("leaks -q minishell");
}
