/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:06:01 by victofer          #+#    #+#             */
/*   Updated: 2023/06/19 12:08:20 by victofer         ###   ########.fr       */
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

	og = cmd;
	free(cmd->cmd);
	free(cmd->flags);
	if (cmd->params != NULL)
		free_array(cmd->params);
	while (cmd->next != NULL)
	{
		cmd = cmd->next;
		free(cmd->cmd);
		free(cmd->flags);
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
 * @brief An auxiliar function to free every *chars used
 * 	in parser/fill_struct function.
 * 
 * @param no_in_out thing to be freed;
 * @param no_out thing to be freed;
 * @param spanded thing to be freed;
 */
void	free_parser(char *no_in_out, char *no_out, char *spanded)
{
	free(no_in_out);
	free(no_out);
	free(spanded);
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

void	free_output_stuff(int *out_pos, char **out, int *out_fd, char *line)
{
	free(out_pos);
	out_pos = NULL;
	free_array(out);
	if (out_fd != NULL)
	{
		free(out_fd);
		out_fd = NULL;
	}
	if (line != NULL)
		free(line);
}
