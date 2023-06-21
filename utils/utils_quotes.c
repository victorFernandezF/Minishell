/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 17:48:26 by victofer          #+#    #+#             */
/*   Updated: 2023/06/21 12:16:38 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*fill_without_last_quote(char *dest, char *str, int nb_quotes)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (str[++i])
	{
		if ((str[i] == 39 || str[i] == 34) && nb_quotes <= 0)
			continue ;
		if (str[i] == 39 || str[i] == 34)
			nb_quotes--;
		dest[j] = str[i];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

char	*delete_unclosed_quotes(char *str)
{
	int		i;
	int		j;
	int		len;
	int		nb_quot;
	char	*no_last_quot;

	i = -1;
	j = 0;
	nb_quot = 0;
	while (str[++i])
		if (str[i] == 39 || str[i] == 34)
			nb_quot++;
	if (nb_quot % 2 == 0)
		return (ft_copy_str(str));
	len = ft_strlen(str) - 1;
	no_last_quot = malloc(len * sizeof(char));
	if (!no_last_quot)
		return (str);
	nb_quot--;
	i = -1;
	no_last_quot = fill_without_last_quote(no_last_quot, str, nb_quot);
	return (no_last_quot);
}
