/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:50:39 by victofer          #+#    #+#             */
/*   Updated: 2023/04/17 12:28:43 by victofer         ###   ########.fr       */
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
	char	*params;
	int		input;
	int		nb_outputs;
	int		*output;
	int		index;
	t_cmd	*next;
}			t_cmd;

//	I N I T

//	P A R S E R

t_cmd	*start_parser(t_cmd *cmd, char *str);
char	*get_part_from_str(char *str, int part);

//	G E T   E A C H   P A R T   O F   C M D 

int		get_nb_cmd(char *str);
int		*get_nb_output(char *str);
char	*get_cmd(char *str);
char	*get_flags(char *str);
int		*get_output(char *str, t_cmd *cmd);
char	*get_output_from_pos(char *out, char *str, int pos);
int		*get_fd_ftom_outputs(char **output, int nb);
char	*get_params(char *str);
char	*transform_env_var(char *str);


//	U T I L I T I E S

int		skip_whitespaces(char *str, int i);
int		is_redirect(char c);
int		is_env_var(char c);

//	C H E C K S

int		are_there_char(char *str, char c);
int		is_token(char c);

//	F R E E   S T U F F 

void	free_struct(t_cmd *cmd);
void	free_array(char **array);

//	L E A K S   T E M P 

void	leaks(void);

#endif