/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victofer <victofer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:50:39 by victofer          #+#    #+#             */
/*   Updated: 2023/06/28 19:30:12 by victofer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <signal.h>
# include <termios.h>
# include "libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>

// C O L O R
# define R	"\x1B[31m"
# define G	"\x1B[32m"
# define BG	"\x1B[92m"
# define BB	"\x1B[94m"
# define Y	"\x1B[33m"
# define B	"\x1B[36m"
# define W	"\x1B[0m"
# define BY	"\x1B[93m"
# define BM	"\x1B[95m"

// S T R U C T
typedef struct s_cmd	t_cmd;
typedef struct s_env	t_env;

typedef struct s_cmd
{
	int		nb_cmd;
	char	*cmd;
	char	*flags;
	char	**params;
	int		nb_inputs;
	int		input;
	int		nb_outputs;
	int		output;
	int		index;
	int		error;
	t_cmd	*next;
}			t_cmd;

typedef struct s_env
{
	char	*var;
	char	**vals;
	t_env	*next;
}			t_env;

// S T R U C T   S T U F F

t_cmd	*init_struct(t_cmd *structure);
t_cmd	*add_new_node_to_the_list(t_cmd *cmd, char *str, int id, t_env *envar);

// I N I T I A L   C H E C K S

int		is_pipe_at_end_of_line(char	*str);
int		check_two_pipes_in_a_row(char *str, int i);
int		check_bad_redirection_chars(char *str, int i);
int		check_empty_cmd_or_bad_input_output(t_cmd *cmd);
int		check_invalid_characters(char *str);
int		print_error(char *errname, char *msg, int code);


//	P A R S E R

t_cmd	*start_parser(t_cmd *cmd, char *cmd_line, t_env *envar);
t_cmd	*fill_struct(t_cmd *tmp, char *command, t_env *envar);
void	settings(int set);

// E N V I R O M E N T   V A R S

char	*del_last_quote(char *str);
char	*convert_env_var_in_its_value(char *cmd_line, t_env *envar);
char	*replace_simple_quotes_by_double_quotes(char *str);
char	*find_env_from_srruct(t_env *envar, char *tmp);
char	*expand_environment_variables(char *cmd_line, t_env *envar);
char	*env_var_transformation(char *env_name, t_env *envar);
char	*fill_string_with_env_var_value(char *redirection, char *env, int flag);
char	*get_env_var_name_including_dollar(char *redirection);
int		get_total_length_of_words_in_array(char **array);
char	*more_than_one_env_vars(char *str, t_env *envar);

//	G E T   E A C H   P A R T   O F   C M D   L I N E

int		get_nb_cmd(char *str);
char	*get_cmd(char *str);
char	*get_flags(char *str);
int		get_nb_inputs(char *cmd_line);
char	*get_input_from_pos(char *cmd_line, int pos, int aux, t_cmd *cmd);
int		*get_input_char_positions(char *cmd_line, t_cmd *cmd);
int		*input_filename_to_fd_converter(char **input, int nb_in, t_cmd *cmd);
int		get_input(char *cmd_line, t_cmd *cmd);
int		get_nb_outputs(char *str);
char	*get_output_from_pos(t_cmd *cmd, char *cmd_line, int pos, int aux);
int		*get_output_char_positions(char *str, t_cmd *cmd);
int		*output_filename_to_fd_converter(char **output, int nb_outputs);
int		get_output(char *str, t_cmd *cmd);
char	**get_parameters(char *str);
char	*fill_string_param(char *param, char *cmd_line, int i);

//	U T I L I T I E S

int		is_pipe(char c);
int		is_env_var(char c);
int		is_redirect(char c);
int		env_var_detector(char *str);
int		is_space_minishel(char c);
int		is_there_open_quotes(char *str, int end);
int		is_between_double_quotes(char *cmd_line, int end);
int		is_between_simple_quotes(char *cmd_line, int end);
int		search_char_in_str(char *str, char c);

int		skip_whitespaces(char *str, int start);
int		skip_characters(char *str, int start);
int		skip_characters_and_spaces(char *str, int start);
int		skip_cmd_and_flags(char	*cmd_line);
int		skip_everything_til_quotes(char	*str, int j);
int		skip_cmd_name(char *str, int start);
int		skip_characters_until_char(char *str, int start, char limit);

int		get_position_of_last_char_found(char *str, char c);
char	*replace_spaces_after_redirect(char *cmd_line);
char	*delete_outputs_from_line(char *cmd_line);
char	*delete_inputs_from_line(char *str);
void	print_error_file(char *input, char *msg);
char	*ft_splitnt(char **array, int len);
void	print_error_file_ambiguous(char	*str, t_cmd *cmd);
char	**ft_split_minishell(char *str, int quot);
int		count_words_minishell(char *str);
char	**ft_split_pipes(char *str, int quot);
int		count_words_pipes(char *str);

int		strlen_starting_in(char *str, int i);
int		get_next_char(char *str, int i);
int		is_inside_simple_quotes(char **array, int pos);
int		check_simple_quotes(char *str);
char	*delete_unclosed_quotes(char *str);
int		check_unclosed_quotes(char *str);

// L O O P P I N G   A N D   S I G N A L S

void	mini_loop(t_cmd *cmd, t_env *envars);
void	signal_handler(int sig);
void	check_ctrl_d(char *read, t_env *envars, char *prompt);
void	rl_replace_line(const char *text, int clear_undo);

// H E R E D O C

int		heredoc_detector(char *str);
char	*get_delimiter(char *str);
char	*heredoc(char *cmd_line, t_env *envar);
char	*convert_heredoc_in_input(char *temp);
char	*convert_heredoc_env_var_in_its_value(char *here_line, t_env *envar);
void	free_heredoc_stuff(char *temp, char **arr_tmp);
char	*heredoc_signs_without_spaces(char *temp);
void	write_in_heredoc_temp_file(int fd, char *read_here);
char	*expand_heredoc_env_vars(char *here_line, t_env *envar);

//	F R E E   S T U F F

void	free_struct(t_cmd *cmd);
void	free_int_array(int *array);
void	free_array(char **array);
void	free_array_and_str(char **array, char *str);
void	free_and_close_heredoc_stuff(char *tmp, char *delimiter, int fd);
void	free_redirection(int *i1, int *i2, char **arr);
void	free_maximun_of_four_str(char *s1, char *s2, char *s3, char *s4);

//	[T E M P]   L E A K S   &   P R I N T S

void	print_test(char *str, t_cmd *cmd, int repeat);
void	leaks(void);
void	print_array(char **array);

// PROCESSING AND EXECUTE

void	processing(t_cmd *cmd, t_env *env);
t_env	*ft_envar(char **env);
char	**ft_splitf(char const *s);
char	**f_split(char const *s, char c);
void	freeenv(t_env *env);
void	freevals(char **vals);
void	set_env(t_env *env, char *var, char *vals);
int		ft_cd(t_cmd *cmd, t_env *env);
int		ft_echo(t_cmd *cmd, t_env *env);
int		ft_pwd(t_cmd *cmd, t_env *env);
int		ft_exit(t_cmd *cmd, t_env *env);
int		n_params(char **mat);
int		n_flags(char *array);
int		cmd_error(char *cmd, char *error, t_env *env);
int		cmd_cd_error(char *cmd, char *error, t_env *env);
void	free_mat(char **mat);

#endif
