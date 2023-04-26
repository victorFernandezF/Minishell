/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_next_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:18:37 by victofer          #+#    #+#             */
/*   Updated: 2023/04/26 09:59:58 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_cmd	*ft_lstlast_1(t_cmd *lst)
{
	t_cmd	*tmp;

	tmp = lst;
	if (!tmp)
		return (NULL);
	if (tmp->next == NULL)
		return (tmp);
	while (tmp->next != NULL)
	{
		if (tmp->next == NULL)
			return (tmp);
		tmp = tmp->next;
	}
	return (tmp);
}

static t_cmd	*ft_lstadd_back_1(t_cmd *cmd, t_cmd *new)
{
	t_cmd	*temp;

	if (cmd)
	{
		temp = cmd;
		temp = ft_lstlast_1(cmd);
		temp->next = new;
		return (cmd);
	}
	cmd = new;
	return (cmd);
}

t_cmd	*fill_more_than_one(t_cmd *cmd, char *str, int index)
{
	t_cmd	*aux;

	(void)str;
	(void)index;
	aux = NULL;
	aux = init_struct(aux);
	aux = fill_struct(aux, str, 1);
	aux->index = index;
	cmd = ft_lstadd_back_1(cmd, aux);
	return (cmd);
}
