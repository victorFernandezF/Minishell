/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct->c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student->42->fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 18:14:41 by victofer          #+#    #+#             */
/*   Updated: 2023/04/25 12:24:34 by victofer         ###   ########->fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_cmd	*init_struct(t_cmd *tmp)
{
	tmp = malloc(sizeof(t_cmd));
	tmp->cmd = NULL;
	tmp->flags = NULL;
	tmp->params = NULL;
	tmp->input = 0;
	tmp->nb_outputs = 0;
	tmp->output = NULL;
	tmp->index = 1;
	tmp->next = NULL;
	return (tmp);
}
