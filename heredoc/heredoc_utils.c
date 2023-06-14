/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 11:01:12 by victofer          #+#    #+#             */
/*   Updated: 2023/06/14 18:51:19 by victofer         ###   ########.fr       */
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
		if (!are_str_equals(arr_tmp[i], "< #tmp"))
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

int	check_heredoc_stop_condition(char *read_here, char *delimiter)
{	
	if (are_str_equals(read_here, delimiter) || read_here == 0)
	{
		if (are_str_equals(read_here, delimiter))
			free(read_here);
		return (1);
	}
	return (0);
}

char	*heredoc_signs_without_spaces(char *temp)
{
	int		i;
	int		j;
	int		nb;
	int		len;
	char	*new;

	nb = 0;
	i = -1;
	j = 0;
	while (temp[++i])
		if (temp[i] == '<' && temp [i + 1] == '<')
			if (temp[i + 2] == ' ')
				nb++;
	len = ft_strlen(temp) - nb;
	new = malloc (len * sizeof(char));
	if (!new)
		return (NULL);
	i = -1;
	while (temp[++i])
	{
		if (temp[i] == ' ' && temp[i - 1] == '<' && temp[i - 2] == '<')
			continue ;
		new[j++] = temp[i];
	}
	new[j] = '\0';
	return (new);
}
