/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:50:39 by victofer          #+#    #+#             */
/*   Updated: 2023/04/11 18:22:35 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "../libft/libft.h"

typedef struct	s_cmd t_cmd;

typedef struct s_cmd
{
	char	*cmd;
	char	*flags;
	int		input;
	int		index;
	int		out;
	t_cmd	*next;
	t_cmd	*prev;
}			t_cmd;

void	start_parser(t_cmd *cmd, char *str);

#endif