/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 11:01:12 by victofer          #+#    #+#             */
/*   Updated: 2023/06/28 10:57:43 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Frees the memory mallocked in heredoc.
 * 
 * @param temp String to free
 * @param arr_tmp Array to free
 */
void	free_heredoc_stuff(char *temp, char **arr_tmp)
{
	int	i;

	i = -1;
	free(temp);
	while (arr_tmp[++i])
		if (!are_two_strs_equal(arr_tmp[i], "< #tmp"))
			free(arr_tmp[i]);
	free(arr_tmp);
	arr_tmp = NULL;
}

/**
 * @brief Convert the heredoc int he command line into an
 * intput.
 * 
 * @param temp String with the command.
 * @return A string with the command after converting the heredoc
 *  into an input. 
 */
char	*convert_heredoc_in_input(char *temp)
{
	int	i;

	i = -1;
	while (temp[++i])
		if (temp[i] == '<' && temp [i + 1] == '<')
			if (temp[i + 2] == ' ')
				temp[i + 2] = '_';
	return (temp);
}

/**
 * @brief Deletes the spaces after heredoc signs(<<).
 * 
 * @param temp String to be modified.
 * @return A String whit the heredocs sings following by their delimiters
 */
char	*heredoc_signs_without_spaces(char *temp)
{
	int		i;
	int		j;
	int		nb;
	char	*new;

	nb = 0;
	i = -1;
	while (temp[++i])
		if (temp[i] == '<' && temp [i + 1] == '<')
			if (temp[i + 2] == ' ')
				nb++;
	j = ft_strlen(temp) - nb;
	new = malloc (j * sizeof(char));
	if (!new)
		return (NULL);
	i = -1;
	j = 0;
	while (temp[++i])
	{
		if (temp[i] == ' ' && temp[i - 1] == '<' && temp[i - 2] == '<')
			continue ;
		new[j++] = temp[i];
	}
	new[j] = '\0';
	return (new);
}

/**
 * @brief Writes the heredoc lines given by user in a temp
 * file that will be used as input later. 
 * 
 * @param fd fd of temp file.
 * @param read_here line read by heredoc.
 */
void	write_in_heredoc_temp_file(int fd, char *read_here)
{
	int	i;

	i = -1;
	while (read_here[++i])
	{
		if (is_env_var(read_here[i]))
		{
			i++;
			while (ft_isalpha(read_here[i]))
				i++;
			write(fd, " ", 1);
		}
		else if (read_here[i])
			write(fd, &read_here[i], 1);
	}
	write(fd, "\n", 1);
	free(read_here);
}
