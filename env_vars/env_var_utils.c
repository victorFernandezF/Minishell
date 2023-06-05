/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 10:49:00 by victofer          #+#    #+#             */
/*   Updated: 2023/06/05 13:30:28 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*find_env_from_srruct(t_env *envar, char *name)
{
	int		i;
	int		len;
	t_env	*vari;
	t_env	*tmp;

	vari = envar;
	len = 0;
	while (vari)
	{
		i = 0;
		if (are_str_equals(vari->var, name))
		{
			if (vari->vals[i + 1] == NULL)
				return (vari->vals[0]);
			while (vari->vals[i])
			{
				len += ft_strlen(vari->vals[i]) - 1;
				i++;
			}
			return (vari->vals[0]);
		}
		tmp = vari->next;
		vari = tmp;
	}
	return (NULL);
}
