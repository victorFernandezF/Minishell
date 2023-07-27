/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:50:03 by victofer          #+#    #+#             */
/*   Updated: 2023/07/27 08:48:22 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	title(void)
{
	printf("%s\n", B);
	printf(" ███╗   ███╗██╗███╗   ██╗██╗██████╗██╗  ██╗██████╗██╗    ██╗\n");
	printf(" ████╗ ████║██║████╗  ██║██║██╔═══╝██║  ██║██╔═══╝██║    ██║\n");
	printf(" ██╔████╔██║██║██╔██╗ ██║██║██████╗███████║████╗  ██║    ██║\n");
	printf(" ██║╚██╔╝██║██║██║╚██╗██║██║╚════█║██╔══██║██╔═╝  ██║    ██║\n");
	printf(" ██║ ╚═╝ ██║██║██║ ╚████║██║██████║██║  ██║██████╗██████╗██████╗\n");
	printf(" ╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝╚═════╝╚═╝  ╚═╝╚═════╝╚═════╝╚═════╝\n");
	printf("                    FORTEGA-  VICTOFER        %s\n\n", W);
}

int	main(int argc, char **argv, char **env)
{
	t_cmd	*cmd;
	t_env	*envars;

	(void)argv;
	if (argc != 1)
	{
		ft_putendl_fd("Error: execute minishell without parameters", 2);
		return (0);
	}
	cmd = NULL;
	envars = ft_envar(env);
	atexit(leaks);
	settings();
	title();
	mini_loop(cmd, envars);
	return (0);
}
