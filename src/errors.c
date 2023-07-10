/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 19:24:11 by victofer          #+#    #+#             */
/*   Updated: 2023/07/10 12:21:38 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Prints an error mesage and exit the program.
 * 
 * @param name name of the error.
 * @param msg message to display before exit.
 */
void	print_error_file(char *name, char *msg, t_env *env)
{
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(msg, 2);
	set_env(env, "?", "1");
}

void	err_malloc(t_cmd *cmd, t_env *env)
{
	char	*msg;

	msg = "Error. Memory allocation failed.";
	ft_putendl_fd(msg, 2);
	cmd->error = 1;
	if (env != NULL)
		set_env(env, "?", "1");
}

/**
 * @brief If enviroment var is bad written or not found in redirection
 * prints an error message.
 * 
 * @param str String.
 */
void	print_error_file_ambiguous(char	*str, t_cmd *cmd, t_env *env)
{
	int		i;
	int		j;
	char	*bad_env;

	i = -1;
	j = 0;
	while (!is_env_var(str[i]))
		i++;
	i--;
	bad_env = malloc(strlen_starting_in(str, i) * sizeof(char));
	while (str[++i])
		bad_env[j++] = str[i];
	bad_env[j] = '\0';
	print_error_file(bad_env, "ambiguous redirect", env);
	cmd->error = 1;
	free(bad_env);
}

/**
 * @brief Print an error message depending of the given code by the
 * standard error output. if code is NULL it prints only 'Error.'
 * After the printation stuff it change the value of $? to 1. 
 * 
 * @param code A code to print different error messages.
 * @param env The list with the env vars.
 * @return [Int] the given error code.
 */
int	print_errors_by_code(int code, t_env *env)
{
	char	*msg;

	if (code == 1)
		msg = "Syntax error.";
	else if (code == 2)
		msg = "Syntax error near unexpected token `newline'";
	else if (code == 3)
		msg = "Syntax error near unexpected token `|'";
	else if (code == 4)
		msg = " : command not found";
	else
		msg = "Error.";
	ft_putendl_fd(msg, 2);
	set_env(env, "?", "1");
	return (code);
}
