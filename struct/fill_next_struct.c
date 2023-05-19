/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_next_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:18:37 by victofer          #+#    #+#             */
/*   Updated: 2023/05/19 10:50:10 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Returns the last element of the list. 
 * 
 * @param lst List.
 * @return The last element of the given list.
 */
static t_cmd	*ft_lstlast_minishell(t_cmd *lst)
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

/**
 * @brief Adds a new element in the last position of the given list.
 * 
 * @param cmd The list in wich we want to add a new node.
 * @param new The new node to add. 
 * @return list with the new element added in the back.
 */
static t_cmd	*ft_lstadd_back_minishell(t_cmd *cmd, t_cmd *new)
{
	t_cmd	*temp;

	if (cmd)
	{
		temp = cmd;
		temp = ft_lstlast_minishell(cmd);
		temp->next = new;
		return (cmd);
	}
	cmd = new;
	return (cmd);
}

/**
 * @brief If there are more than one command in command line
 *	this function will fill each one in a new node of the list.
 * 
 * @param cmd Struct.
 * @param str line with the command.º
 * @param index index of the new node we are creating.
 * @return The list created.  
 */
t_cmd	*fill_more_than_one(t_cmd *cmd, char *cmd_line, int index)
{
	t_cmd	*aux;

	aux = NULL;
	aux = init_struct(aux);
	aux = fill_struct(aux, cmd_line);
	aux->index = index;
	cmd = ft_lstadd_back_minishell(cmd, aux);
	return (cmd);
}
