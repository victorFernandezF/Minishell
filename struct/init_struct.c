/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:55:59 by victofer          #+#    #+#             */
/*   Updated: 2023/05/02 19:19:12 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
/*
 * init_struct
 * ----------------------------
 *	Initialize a struct with all its elements to NULL 
 *
 *	PARAMS:
 *	-> struct: A struct to be initialized
 * 	RETURN
 *	-> The struct initialized.
 */
t_cmd	*init_struct(t_cmd *structure)
{
	structure = malloc(sizeof(t_cmd));
	structure->cmd = NULL;
	structure->flags = NULL;
	structure->params = NULL;
	structure->input = 0;
	structure->nb_outputs = 0;
	structure->nb_inputs = 0;
	structure->output = NULL;
	structure->input = NULL;
	structure->index = 1;
	structure->next = NULL;
	return (structure);
}
