/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 09:54:46 by victofer          #+#    #+#             */
/*   Updated: 2023/05/23 19:20:02 by victofer         ###   ########.fr       */
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
	int	quot;

	cont = 0;
	quot = 0;
	while (*str)
	{
		while (*str && space(*str))
			str++;
		if (*str == 34)
		{
			cont++;
			str++;
			while (*str && *str != 34)
				str++;
			str++;
		}
		else if (*str && !space(*str))
		{
			cont++;
			while (*str && !space(*str))
				str++;
		}
	}
	return (cont);
}

char	*quot_manager(char *str)
{
	int		i;
	int		j;
	char	*word;

	i = 1;
	j = 0;
	while (str[i] != 34)
		i++;
	word = malloc((i) * sizeof(char));
	if (!word)
		return (NULL);
	i = 1;
	while (str[i] != 34)
		word[j++] = str[i++];
	word[j] = '\0';
	return (word);
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
		/* if (*str && *str == 34)
		{
			split[i] = quot_manager(str);
			i++;
			while (*str && *str != 34)
				str++;
		}
		else */ if (*str && !space(*str))
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
