/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:50:39 by victofer          #+#    #+#             */
/*   Updated: 2023/05/03 12:18:29 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

# define R	"\x1B[31m"
# define G	"\x1B[32m"
# define BG	"\x1B[92m"
# define Y	"\x1B[33m"
# define B	"\x1B[36m"	
# define W	"\x1B[37m"
# define BY	"\x1B[93m"
# define BM	"\x1B[95m"

typedef struct s_cmd	t_cmd;

typedef struct s_cmd
{
	char	*cmd;
	char	*flags;
	char	**params;
	int		nb_inputs;
	int		input;
	int		nb_outputs;
	int		*output;
	int		index;
	t_cmd	*next;
}			t_cmd;

//	P A R S E R

t_cmd	*init_struct(t_cmd *structure);
t_cmd	*start_parser(t_cmd *cmd, char *str);
t_cmd	*fill_more_than_one(t_cmd *cmd, char *str, int index);
t_cmd	*fill_struct(t_cmd *tmp, char *command, int nb_cmd);

// C O N V E R T   E N V   V A R S 

void	print_error_file(char *input, char *msg, t_cmd *cmd);
char	*transform_env_var(char *str);
char	*replace_env_by_value(char	*str, int pos, char *tmp, int i);

//	G E T   E A C H   P A R T   O F   C M D 

int		get_nb_cmd(char *str);
int		*get_nb_output(char *str);
char	*get_cmd(char *str);
char	*get_flags(char *str);
char	*get_params(char *str);
int		*get_output(char *str, t_cmd *cmd);
char	*get_output_from_pos(char *out, char *str, int pos);
int		*str_to_fd_converter(char **output, int nb);
char	*get_params_after_out(char *param, char*str, int i);

int		get_nb_inputs(char *str);
int		get_input(char *str, t_cmd *cmd);
int		*get_input_char_positions(char *str, t_cmd *cmd);
char	*get_input_from_position(char *out, char *str, int pos);
int		*input_filename_to_fd_converter(char **output, int nb, t_cmd *cmd);

//	U T I L I T I E S

int		skip_whitespaces(char *str, int i);
int		is_redirect(char c);
int		is_env_var(char c);
int		skip_characters(char *str, int i);
int		skip_characters_and_spaces(char *str, int i);

//	C H E C K S

int		are_there_char(char *str, char c);
int		is_pipe(char c);

//	F R E E   S T U F F 

void	free_struct(t_cmd *cmd);
void	free_array(char **array);

//	L E A K S   T E M P 

void	print_test(t_cmd *cmd, int repeat);
void	leaks(void);
#endif