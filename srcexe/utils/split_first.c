/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_first.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 11:05:24 by fortega-          #+#    #+#             */
/*   Updated: 2023/06/05 08:23:00 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static void	ft_freestr(char **str, int i)
{
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
}

static char	*ft_matfill(const char *s, char c)
{
	char	*str;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	str = ((char *)ft_calloc(i + 1, sizeof(char)));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_splitf(char const *s)
{
	char	**mat;
	int		i;

	i = 0;
	mat = (char **)malloc(3 * sizeof(char *));
	if (!mat)
		return (NULL);
	mat[0] = ft_matfill(s, '=');
	if (mat[0] == NULL)
		ft_freestr(mat, i);
	while (*s != '=')
		s++;
	s++;
	mat[1] = ft_matfill(s, '\0');
	mat[2] = NULL;
	return (mat);
}
