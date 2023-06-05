/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 10:49:00 by victofer          #+#    #+#             */
/*   Updated: 2023/06/05 11:04:18 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*find_env_from_srruct(t_env *envar, char *name)
{
	//int		i;
	t_env	*vari;
	t_env	*tmp;

	vari = envar;
	//i = 0;
	while (vari)
	{
		if (are_str_equals(vari->var, name))
			return (vari->vals[0]);
		tmp = vari->next;
		vari = tmp;
	}
	return (NULL);
}
