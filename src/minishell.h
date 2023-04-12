/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:50:39 by victofer          #+#    #+#             */
/*   Updated: 2023/04/12 12:12:23 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <fcntl.h>
# include "../libft/libft.h"

typedef struct s_cmd	t_cmd;

typedef struct s_cmd
{
	char	*cmd;
	char	*flags;
	int		input;
	int		output;
	int		index;
	t_cmd	*next;
	t_cmd	*prev;
}			t_cmd;

void	start_parser(t_cmd *cmd, char *str);
int		get_nb_cmd(char *str, int cmd);
char	*get_part_from_str(char *str, int part);

#endif