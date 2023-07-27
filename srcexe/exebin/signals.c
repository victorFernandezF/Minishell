/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 12:43:44 by fortega-          #+#    #+#             */
/*   Updated: 2023/07/27 08:54:59 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	g_sign = 0;

void	actsdad(int sig)
{
	extern int	g_sign;

	(void)sig;
	g_sign = 1;
	write(1, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	signal_handler_child(int sig)
{
	(void)sig;
	rl_on_new_line();
}

void	no_sigquit(void)
{
	struct sigaction	no_sigquit;

	ft_memset(&no_sigquit, 0, sizeof(no_sigquit));
	no_sigquit.sa_handler = SIG_IGN;
	no_sigquit.sa_flags = SA_RESTART;
	sigaction(SIGQUIT, &no_sigquit, NULL);
}

void	sigdad(void)
{
	struct sigaction	dad;

	no_sigquit();
	ft_memset(&dad, 0, sizeof(dad));
	dad.sa_handler = &actsdad;
	dad.sa_flags = SA_RESTART;
	sigaction(SIGINT, &dad, NULL);
}

void	sigchild(void)
{
	struct sigaction	child;

	no_sigquit();
	ft_memset(&child, 0, sizeof(child));
	child.sa_handler = &signal_handler_child;
	child.sa_flags = SA_RESTART;
	sigaction(SIGINT, &child, NULL);
}
