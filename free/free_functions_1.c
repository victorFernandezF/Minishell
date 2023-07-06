/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:06:01 by victofer          #+#    #+#             */
/*   Updated: 2023/06/21 11:29:54 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Frees every element of the struct that needs to
 * be freed. and frees the struct itself
 * 
 * @param cmd Struct.
 */
void	free_struct(t_cmd *cmd)
{
	t_cmd	*og;
	if (cmd == NULL)
		return ;
	og = cmd;
	free(cmd->cmd);
	free(cmd->flags);
	if (cmd->params != NULL)
		free_array(cmd->params);
	close_fds(cmd);
	while (cmd->next != NULL)
	{
		cmd = cmd->next;
		free(cmd->cmd);
		free(cmd->flags);
		if (cmd->params != NULL)
			free_array(cmd->params);
		free(cmd);
	}
	cmd = og;
	free(og);
	cmd = NULL;
	unlink("#tmp");
}

/**
 * @brief Frees every strings inside of an array of strings and
 * frees the array itself.
 * 
 * @param array Array of strings.
 */
void	free_array(char **array)
{
	int	i;

	i = -1;
	while (array[++i])
	{
		if (array[i] == NULL)
			break ;
		free(array[i]);
	}
	free(array);
	array = NULL;
}

/**
 * @brief Frees the heredoc delimiter, frees the tmp string and
 * closes the fd of the temporal file of the heredoc.
 * 
 * @param tmp String to free 
 * @param delimiter String to free
 * @param fd Fd to close
 */
void	free_and_close_heredoc_stuff(char *tmp, char *delimiter, int fd)
{	
	free(delimiter);
	free(tmp);
	close(fd);
}

/**
 * @brief Frees things used in redirection functions.
 * 
 * @param i1 array of ints
 * @param i2 array of ints
 * @param arr arrat of strings
 */
void	free_redirection(int *i1, int *i2, char **arr)
{
	if (i1 != NULL)
		free_int_array(i1);
	if (i2 != NULL)
		free_int_array(i2);
	if (arr != NULL)
		free_array(arr);
}

/**
 * @brief Frees a maximun of four memory allocated strings.
 * Four is a maximunbut it will work with less if you put NULL in the rest.
 * 
 * @param s1 String to be freed. Could be NULL.
 * @param s2 String to be freed. Could be NULL.
 * @param s3 String to be freed. Could be NULL.
 * @param s4 String to be freed. Could be NULL.
 */
void	free_maximun_of_four_str(char *s1, char *s2, char *s3, char *s4)
{
	if (s1 != NULL)
		free(s1);
	if (s2 != NULL)
		free(s2);
	if (s3 != NULL)
		free(s3);
	if (s4 != NULL)
		free(s4);
}
