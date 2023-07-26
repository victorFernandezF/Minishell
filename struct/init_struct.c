/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:55:59 by victofer          #+#    #+#             */
/*   Updated: 2023/07/26 18:00:26 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * @brief Initialize a struct with all its elements to NULL or 0
 * 
 * @param structure The struct to initialize.
 * @return [t_cmd] The initilized struct.
 */
t_cmd	*init_struct(t_cmd *structure)
{
	structure = malloc(sizeof(t_cmd));
	structure->cmd = NULL;
	structure->nb_cmd = 0;
	structure->flags = NULL;
	structure->params = NULL;
	structure->input = 0;
	structure->nb_outputs = 0;
	structure->nb_inputs = 0;
	structure->output = 0;
	structure->input = 0;
	structure->index = 1;
	structure->error = 0;
	structure->next = NULL;
	return (structure);
}
