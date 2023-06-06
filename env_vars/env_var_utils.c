/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 10:49:00 by victofer          #+#    #+#             */
/*   Updated: 2023/06/06 10:43:59 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_inside_simple_quotes(char **array, int pos)
{
	int	i;
	int	nb_q;

	i = -1;
	nb_q = 0;
	while (++i < pos)
		if (are_there_char(array[i], 39))
			nb_q++;
	if (nb_q % 2 == 0)
		return (0);
	return (1);
}

int	check_simple_quotes(char *str)
{
	int	len;
	int	begin;
	int	end;
	int	res;

	len = ft_strlen(str) -1;
	begin = 0;
	end = 0;
	res = 0;
	if (str[0] == 39)
		begin = 1;
	if (str[len] == 39)
		end = 1;
	if (begin == 1 && end == 1)
		res = 1;
	return (res);
}

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
