/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 09:54:46 by victofer          #+#    #+#             */
/*   Updated: 2023/05/09 18:23:13 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	space(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

int	count_words(char *str)
{
	int	cont;

	cont = 0;
	while (*str)
	{
		while (*str && space(*str))
			str++;
		if (*str && !space(*str))
		{
			cont++;
			while (*str && !space(*str))
				str++;
		}
	}
	return (cont);
}

char	*write_word(char *str)
{
	int		i;
	char	*word;

	i = 0;
	while (str[i] && !space(str[i]))
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (!word)
	{
		free(str);
		return (NULL);
	}
	i = 0;
	while (str[i] && !space(str[i]))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split_2(char *str)
{
	int		i;
	char	**split;

	i = 0;
	split = (char **)malloc(sizeof(char *) * (count_words(str) + 1));
	if (!split)
		return (NULL);
	while (*str)
	{
		while (*str && space(*str))
		str++;
		if (*str && !space(*str))
		{
			split[i] = write_word(str);
			i++;
			while (*str && !space(*str))
				str++;
		}
	}
	split[i] = NULL;
	return (split);
}
