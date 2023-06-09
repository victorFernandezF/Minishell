/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:57:27 by victofer          #+#    #+#             */
/*   Updated: 2023/06/09 12:30:58 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"

/**
 * @brief Replace heredoc by normal input in the command line.
 * 
 * @param line Commmand_line.
 * @return A string with the new command line.
 */
static char	*replace_heredoc(char *line)
{
	int		i;
	int		len;
	char	*temp;
	char	**arr_tmp;
	char	*new;

	temp = ft_copy_str(line);
	i = -1;
	temp = convert_heredoc_in_input(temp);
	arr_tmp = ft_split_minishell(temp, 0);
	i = -1;
	while (arr_tmp[++i])
	{
		if (arr_tmp[i][0] == '<' && arr_tmp[i][1] == '<')
		{
			free(arr_tmp[i]);
			arr_tmp[i] = "< #tmp";
		}
	}
	len = get_total_length_of_words_in_array(arr_tmp);
	new = ft_splitnt(arr_tmp, len);
	free_heredoc_stuff(temp, arr_tmp);
	return (new);
}

/**
 * @brief Checks if there is an heredoc sign "<<"
 * 
 * @param str String with the command.
 * @return 1 if there are a heredoc. 0 if not.
 */
int	heredoc_detector(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		if (str[i] == '<' && str[i + 1] == '<' )
			return (1);
	return (0);
}

/**
 * @brief Returns the delimiter of the heredoc.
 * 
 * @param str Command line. 
 * @return A string with the delimiter of the heredoc.
 */
char	*get_delimiter(char *str)
{
	int		i;
	int		j;
	char	*delimiter;

	i = -1;
	while (str[++i])
	{
		if (str[i] == '<' && str[i + 1] == '<' )
		{
			j = 0;
			i += 2;
			i = skip_whitespaces(str, i);
			while (str[j] && str[j] != ' ')
				j++;
			delimiter = malloc((j + 1) * sizeof(char));
			if (!delimiter)
				return (NULL);
			j = 0;
			while (str[i] && str[i] != ' ')
				delimiter[j++] = str[i++];
			delimiter[j] = '\0';
			return (delimiter);
		}
	}
	return (NULL);
}

/**
 * @brief Makes the heredoc magic. creates a temp file where
 * all heredocs inputs are stored. After that transform the
 * heredoc in a normal input in order to be read in the future.
 * 
 * @param cmd_line Command line.
 * @return A string with command line transforming the heredoc 
 * into a normal input.
 */
char	*heredoc(char *cmd_line)
{
	char	*delimiter;
	char	*tmp;
	char	*read_here;
	char	*new_line;
	int		heredoc_fd;

	tmp = ft_copy_str(cmd_line);
	delimiter = get_delimiter(tmp);
	heredoc_fd = open("#tmp", O_CREAT | O_RDWR | O_APPEND, 0644);
	while (1)
	{
		read_here = readline(">");
		write(heredoc_fd, read_here, ft_strlen(read_here));
		write(heredoc_fd, "\n", 1);
		free(read_here);
		if (are_str_equals(read_here, delimiter))
			break ;
	}
	free(delimiter);
	new_line = replace_heredoc(cmd_line);
	close(heredoc_fd);
	free(tmp);
	return (new_line);
}
