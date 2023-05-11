/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:09:26 by victofer          #+#    #+#             */
/*   Updated: 2023/05/11 13:42:08 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/* 
 * fill_string_flags (get/get_flags.c)
 * ----------------------------
 *	Auxiliar function to help get_flags to fill
 *	the string with the flags of the command
 *
 *	PARAMS:
 *	-> array: array whith every part of the command.
 *	-> len: calculated length of the result string.
 *
 * 	RETURN
 *	-> A string with the flags separated by spaces.
 */
static char	*fill_fstring_flags(char **array, int len)
{
	int		i;
	int		j;
	int		x;
	char	*res;

	x = 0;
	res = malloc((len) * sizeof(char));
	if (!res)
		return (NULL);
	i = -1;
	while (array[++i])
	{
		j = 0;
		if (array[i][0] == '-')
		{
			while (array[i][j])
				res[x++] = array[i][j++];
			if (array[i + 1] && array[i + 1][0] == '-')
				res[x++] = ' ';
		}	
	}
	res[x] = '\0';
	return (res);
}

/* 
 * get_flags (get/get_flags.c)
 * ----------------------------
 *	Splits the flags of the command from the given string
 *
 *	PARAMS:
 *	-> str: string given by user.
 *
 * 	RETURN
 *	-> A string with the flags name.
 */
char	*get_flags(char *str)
{
	int		i;
	int		len;
	char	*res;
	char	*tmp;
	char	**array;

	i = -1;
	len = 0;
	tmp = replace_spaces_after_redirect(str);
	array = ft_split_2(tmp);
	while (array[++i])
	{
		if (array[i][0] == '-')
		{
			len += ft_strlen(array[i]);
			len += 1;
		}
	}
	res = fill_fstring_flags(array, len);
	free(tmp);
	free_array(array);
	return (res);
}
