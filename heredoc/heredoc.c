/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:57:27 by victofer          #+#    #+#             */
/*   Updated: 2023/07/28 13:11:59 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"

void	sigchild(void);
void	heredoc_while(char *del, int fd, t_env *envar);

/**
 * @brief Replace heredoc by normal input in the command line.
 * 
 * @param line Commmand_line.
 * @return [Char *] A string with the new command line.
 */
static char	*replace_heredoc(char *line)
{
	int		i;
	int		len;
	char	*temp;
	char	**arr_tmp;
	char	*new;

	temp = ft_strdup(line);
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
	new = ft_splitnt(arr_tmp, len, 0);
	free_heredoc_stuff(temp, arr_tmp);
	return (new);
}

/**
 * @brief Checks if there is an heredoc sign "<<"
 * 
 * @param str String with the command.
 * @return [Int] 1 if there are a heredoc. 0 if not.
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
 * @return [Char *] A string with the delimiter of the heredoc.
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
 * @brief Opens the temporary file that will be use
 * to store the heredoc content.
 * 
 * @return [Int] FD of the opened file.
 */
int	open_heredoc_file(void)
{
	int	fd;

	if (open("#tmp", O_RDONLY) > 0)
		unlink("#tmp");
	fd = open("#tmp", O_CREAT | O_RDWR | O_APPEND, 0644);
	return (fd);
}

/**
 * @brief Makes the heredoc magic. creates a temp file where
 * all heredocs inputs are stored. After that transform the
 * heredoc in a normal input in order to be read in the future.
 * 
 * @param cmd_line Command line.
 * @return [Char *] A string with command line transforming the heredoc 
 * into a normal input.
 */
char	*heredoc(char *cmd_line, t_env *envar)
{
	int		heredoc_fd;
	char	*delimiter;
	void	*old;

	old = rl_getc_function;
	rl_getc_function = getc;
	delimiter = get_delimiter(cmd_line);
	heredoc_fd = open_heredoc_file();
	heredoc_while(delimiter, heredoc_fd, envar);
	rl_getc_function = old;
	return (free_close(NULL, delimiter, heredoc_fd), replace_heredoc(cmd_line));
}
