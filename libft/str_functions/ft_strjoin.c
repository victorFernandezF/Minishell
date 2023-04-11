/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 11:13:34 by victofer          #+#    #+#             */
/*   Updated: 2023/03/20 10:58:09 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*ft_join(char *strjoin, char *s1, char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1[i])
	{
		strjoin[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		strjoin[i] = s2[j];
		i++;
		j++;
	}
	strjoin[i] = '\0';
	return (strjoin);
}

/*
 * Function: ft_strjoin
 * ----------------------------
 *   Joins s1 and s2 in a new string.
 *
 *   s1: String to be joined.
 *   s2: String to be joined.
 *  
 *   Returns: A string whit the resule of join s1 and s2.
 */
char	*ft_strjoin(char *s1, char *s2)
{
	char	*strjoin;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	strjoin = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!strjoin)
		return (NULL);
	strjoin = ft_join(strjoin, s1, s2);
	return (strjoin);
}
