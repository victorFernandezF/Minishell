/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 18:13:23 by victofer          #+#    #+#             */
/*   Updated: 2023/06/22 18:22:07 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <strings.h>

static char	*ft_strndup(char *str, int nb)
{
	int		i;
	char	*res;

	i = -1;
	res = malloc(nb * sizeof(char));
	if (!res)
		return (NULL);
	while (++i < nb)
		res[i] = str[i];
	res[i] = '\0';
	return (res);
}

char	**ft_split_minishell(char *str, int quot)
{
	int		i;
	int		j;
	int		x;
	int		quotes;
	char	**split;

	(void)quot;
	i = 0;
	j = 0;
	x = 0;
	quotes = 0;
	split = malloc(strlen(str) * sizeof(char *));
	if (!split)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '/')
			quotes = !quotes;
		if (!quotes && str[i] == ' ')
		{
			split[x++] = ft_strndup(&str[i], i + j);
			j = i - j;
		}
		i++;
	}
	split[x++] = ft_strndup(&str[i], i + j);
	split[x] = NULL;
	return (split);
}

int	main(void)
{
	int		i;
	char	*str;
	char	**split;

	str = "test split /comillas todo esto/ ac";
	split = ft_split_minishell(str, 0);
	i = -1;
	while (split[++i] != NULL)
		printf("%s\n", split[i]);
	return (0);
}
