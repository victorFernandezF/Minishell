/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 11:01:12 by victofer          #+#    #+#             */
/*   Updated: 2023/06/09 11:01:24 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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