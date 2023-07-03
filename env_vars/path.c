/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 13:27:28 by victofer          #+#    #+#             */
/*   Updated: 2023/06/30 13:51:14 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static char	*all_together(char **array)
{
	int		len;
	int		i;
	char	*res;

	i = -1;
	len = get_total_length_of_words_in_array(array);
	res = ft_splitnt(array, len);
	while (res[++i])
		if (res[i] == ' ')
			res[i] = ':';
	return (res);
}

/**
 * @brief Take an string with the name of the env var
 *	and returns a new string with its value.
 * 
 * @param str String with env var name starrting with '$'
 * @return [Char *] String with the enviroment var value.
 */
char	*get_path(t_env *envar)
{
	char	**array;
	char	*res;
	t_env	*vari;
	t_env	*tmp;

	vari = envar;
	while (vari)
	{
		if (are_two_strs_equal(vari->var, "PATH"))
		{
			array = vari->vals;
			res = all_together(array);
			return (res);
		}
		tmp = vari->next;
		vari = tmp;
	}
	return (NULL);
}

void	free_env_var_things(char *s1, char *s2, char *envname, char *env)
{
	if (s1 != NULL)
		free(s1);
	if (s2 != NULL)
		free(s2);
	if (are_two_strs_equal(envname, "$PATH"))
		free(env);
	if (envname != NULL)
		free(envname);
}

