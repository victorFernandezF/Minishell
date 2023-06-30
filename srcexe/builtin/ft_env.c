/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fortega- <fortega-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 09:11:39 by fortega-          #+#    #+#             */
/*   Updated: 2023/06/30 09:44:04 by fortega-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int	cntstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	printf("%s\n", s);
	while (s[i] != '\0')
	{
		i++;
		printf("%c: %d\n", s[i], i);
	}
	return (i);
}

int	ft_cntenv(t_env *env)
{
	int		i;
	int		j;
	int		t;
	t_env	*tmp;

	t = 0;
	tmp = env;
	while (tmp)
	{
		printf("Entra while\n");
		i = 0;
		j = 0;
		t += cntstr(tmp->var);
		printf("%d", t);
		while (tmp->vals[j++])
		{
			if (!(ft_strncmp("?", tmp->var, ft_strlen("?"))))
			{
				j++;
				continue ;
			}
			while (tmp->vals[j][i++])
				t++;
		}
		tmp = tmp->next;
	}
	return (t);
}

int	ft_env(t_env *env)
{
	printf("%d\n", ft_cntenv(env));
	return (EXIT_SUCCESS);
}
