/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_next_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 10:18:37 by victofer          #+#    #+#             */
/*   Updated: 2023/05/11 10:59:52 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*
 * ft_lstlast_minishell (struct/fill_next_struct.c)
 * ----------------------------
 *	Returns the last element of the list. 
 *
 *	PARAMS:
 *	-> A list. 
 * 	RETURN
 *	-> The last element of the given list.
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

/*
 * ft_lstadd_back__minishell (struct/fill_next_struct.c)
 * ----------------------------
 *	Adds a new element in the last position of the given list. 
 *
 *	PARAMS:
 *	-> cmd: The list in wich we want to add a new node.
 *	-> new: The new node to add. 
 * 	RETURN
 *	-> The list with the new element added in the back.
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

/*
 * fill_more_than_one (struct/fill_next_struct.c)
 * ----------------------------
 *	If there are more than one command in command line
 *	this function will fill each one in a new node of the list.
 *
 *	PARAMS:
 *	-> cmd: the first node of the list (it will be the first command). 
 * 	-> str: The command line (splited by pipe).
 * 	-> index: An index for the new node. To make easyer to identify each one. 
 * 	RETURN
 *	-> The list created.
 */
t_cmd	*fill_more_than_one(t_cmd *cmd, char *str, int index)
{
	t_cmd	*aux;

	(void)str;
	(void)index;
	aux = NULL;
	aux = init_struct(aux);
	aux = fill_struct(aux, str);
	aux->index = index;
	cmd = ft_lstadd_back_minishell(cmd, aux);
	return (cmd);
}
