/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:06:01 by victofer          #+#    #+#             */
/*   Updated: 2023/06/21 11:32:40 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Frees an array of integers.
 * 
 * @param array array of ints to be freed;
 */
void	free_int_array(int *array)
{
	if (array != NULL)
	{
		free(array);
		array = NULL;
	}
}

/**
 * @brief Frees an array of strings and a string.
 * 
 * @param array array of strings to be freed;
 * @param str string to be freed;
 */
void	free_array_and_str(char **array, char *str)
{
	if (array != NULL)
		free_array(array);
	if (str != NULL)
		free(str);
}

