/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:50:39 by victofer          #+#    #+#             */
/*   Updated: 2023/05/12 12:32:05 by victofer         ###   ########.fr       */
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
t_cmd	*fill_struct(t_cmd *tmp, char *command);

// C O N V E R T   E N V   V A R S 

t_cmd	*check_env_param(t_cmd *cmd);
char	*get_env_cmd(char *str);
char	**check_env_input(char **input);
char	**check_env_output(char **output);
char	*transforming(char *str);
char	*replace_env_by_value(char	*str, int pos, char *tmp, int i);
void	print_error_file(char *input, char *msg);

//	G E T   E A C H   P A R T   O F   C M D   L I N E

char	*replace_spaces_after_redirect(char *str);
int		get_nb_cmd(char *str);
char	*get_cmd(char *str);
char	*get_flags(char *str);
char	**get_parameters(char *str);
int		get_nb_outputs(char *str);
int		*get_output(char *str, t_cmd *cmd);
int		*get_output_char_positions(char *str, t_cmd *cmd);
char	*get_output_from_position(char *out, char *str, int pos);
int		*output_to_fd_converter(char **output, int nb);
int		get_nb_inputs(char *str);
int		get_input(char *str, t_cmd *cmd);
int		*get_input_char_positions(char *str, t_cmd *cmd);
char	*get_input_from_position(char *out, char *str, int pos);
int		*input_filename_to_fd_converter(char **output, int nb);

//	U T I L I T I E S

int		strlen_starting_in(char *str, int i);
int		is_redirect(char c);
int		is_env_var(char c);
int		skip_characters(char *str, int i);
int		skip_whitespaces(char *str, int i);
int		skip_characters_and_spaces(char *str, int i);
int		skip_cmd_and_flags(char	*str);
int		are_there_char(char *str, char c);
int		is_pipe(char c);
char	*delete_outputs_from_line(char *str);
char	*delete_inputs_from_line(char *str);
int		get_position_of_last_char_found(char *str, char c);

//	F R E E   S T U F F 

void	free_struct(t_cmd *cmd);
void	free_array(char **array);

//	L E A K S   T E M P 

void	print_test(char *str, t_cmd *cmd, int repeat);
void	leaks(void);

#endif