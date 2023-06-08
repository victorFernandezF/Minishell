/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:57:27 by victofer          #+#    #+#             */
/*   Updated: 2023/06/08 19:43:04 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../minishell.h"

int	heredoc_detector(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
		if (str[i] == '<' && str[i + 1] == '<' )
			return (1);
	return (0);
}

static char	*replace_heredoc(char *line)
{
	int		i;
	int		len;
	char	**arr_tmp;
	char	*new;

	i = -1;
	while (line[++i])
		if (line[i] == '<' && line [i + 1] == '<')
			if (line[i + 2] == ' ')
				line[i + 2] = '_';
	arr_tmp = ft_split_2(line);
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
	return (new);
}

char	*heredoc(char *cmd_line)
{
	char	*delimiter;
	char	*read_here;
	char	*new_line;
	int		heredoc_fd;

	delimiter = get_delimiter(cmd_line);
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
	return (new_line);
}

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
