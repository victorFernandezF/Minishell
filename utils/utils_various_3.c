/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_various_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 12:48:44 by victofer          #+#    #+#             */
/*   Updated: 2023/07/13 12:50:30 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Change the terminal settings to avoid printing
 * '^C' when ctrl-c is pressed. And before exit the program
 * change the settings to its orriginal values.
 * 
 */
void	settings(void)
{
	struct termios	settings;

	if (tcgetattr(0, &settings))
		perror("Error");
	settings.c_lflag &= ~ECHOCTL;
	if (tcsetattr(0, 0, &settings))
		perror("Error.");
}

/**
 * @brief Counts every env vars sign '$' in the string-
 * 
 * @param str String (command line).
 * @return [Int] The number of '$' found.
 */
int	env_var_counter(char *str)
{
	int	i;
	int	res;

	i = -1;
	res = 0;
	while (str[++i])
		if (is_env_var(str[i]))
			res++;
	return (res);
}
