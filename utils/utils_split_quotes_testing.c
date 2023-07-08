/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_split_quotes_testing.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 09:54:46 by victofer          #+#    #+#             */
/*   Updated: 2023/06/22 18:10:51 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


/* static char	*ft_strndup(char *str, int nb)
{
	int		i;
	char	*res;

	i = -1;
	printf("strdup -> %s %i\n", str, nb);
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
	split = malloc(ft_strlen(str) * sizeof(char *));
	if (!split)
		return (NULL);
	while (str[i])
	{
		printf("%c\n", str[i]);
		if (str[i] == 34)
			quotes = !quotes;
		if (!quotes && str[i] == ' ')
		{
			split[x++] = ft_strndup(&str[i], i - j);
			j = i + j;
		}
		i++;
	}
	split[x++] = ft_strndup(&str[i], i - j);
	split[x] = NULL;
	print_array(split);
	return (split);
} */
