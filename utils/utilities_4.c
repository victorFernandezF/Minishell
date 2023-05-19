/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 13:37:53 by victofer          #+#    #+#             */
/*   Updated: 2023/05/19 13:10:33 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Prints an error mesage and exit the program.
 * 
 * @param name name of the error.
 * @param msg message to display before exit.
 */
void	print_error_file(char *name, char *msg)
{
	printf("%s: %s\n", name, msg);
	exit(-1);
}

/**
 * @brief It's the oposite of ft_split. (ft_splitn't xd)
 *	It take an array of strings and the length of the array
 *	and returns a null terminated string with every elements of
 *	the array separated by spaces.
 * 
 * @param array Array to convert to string.
 * @param len Length of the array. 
 * @return A null terminated string with every elements of
 *	the array separated by spaces.
 */
char	*ft_splitnt(char **array, int len)
{
	char	*new_line;
	int		i;
	int		j;
	int		x;

	i = -1;
	x = 0;
	new_line = malloc(len * sizeof(char));
	if (!new_line)
		return (NULL);
	while (array[++i])
	{
		j = -1;
		while (array[i][++j])
			new_line[x++] = array[i][j];
		if (array[i + 1])
			new_line[x++] = ' ';
	}
	new_line[x] = '\0';
	return (new_line);
}
