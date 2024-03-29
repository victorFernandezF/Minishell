# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: victofer <victofer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/08 18:12:44 by victofer          #+#    #+#              #
#    Updated: 2023/07/26 10:01:42 by victofer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	minishell
COMP	= 	gcc
CFLAGS 	= 	-Wall -Wextra -Werror -g
SRC 	= 	src/loop.c \
			src/main.c \
		 	src/parser.c \
		 	src/initial_checks.c \
		 	src/errors.c \
			src/print_leaks_and_testing.c \
			free/free_functions_1.c \
			free/free_functions_2.c \
			struct/init_struct.c \
			struct/fill_next_struct.c \
			get/get_cmd.c \
			get/get_flags.c \
			get/get_output.c \
			get/get_input.c \
			get/get_parameters.c \
			get/redirections_utils.c \
			heredoc/heredoc.c \
			heredoc/heredoc_utils.c \
			heredoc/heredoc_expander.c \
			env_vars/env_vars_expander.c \
			env_vars/env_vars_redirections.c \
			env_vars/env_vars_utils.c \
			env_vars/path.c \
			utils/utils_checks_1.c \
			utils/utils_checks_2.c \
			utils/utils_skip.c \
			utils/utils_various_1.c \
			utils/utils_various_2.c \
			utils/utils_various_3.c \
			utils/utils_quotation.c \
			utils/utils_split_quotes.c \
			srcexe/processing.c \
			srcexe/exebin/exegutor.c \
			srcexe/exebin/pipes.c \
			srcexe/exebin/signals.c \
			srcexe/utils/cd_utils.c \
			srcexe/utils/split_first.c \
			srcexe/utils/errors.c \
			srcexe/utils/memory.c \
			srcexe/utils/f_split.c \
			srcexe/utils/envar_utils.c \
			srcexe/utils/envar_utils_exe.c \
			srcexe/utils/export_utils.c \
			srcexe/utils/exe_utils.c \
			srcexe/envar/envar.c \
			srcexe/envar/set_env.c \
			srcexe/envar/getvarcd.c \
			srcexe/builtin/ft_cd.c \
			srcexe/builtin/ft_echo.c \
			srcexe/builtin/ft_pwd.c \
			srcexe/builtin/ft_exit.c \
			srcexe/builtin/ft_env.c \
			srcexe/builtin/ft_unset.c \
			srcexe/builtin/ft_export.c

OBJS	=	$(SRC:.c=.o)
LIBFT_PATH 	=  libft/
LIBFT		= -L./libft -lft
LIBFT		= libft/libft.a

# T E X T   S T U F F
G		= \033[0;92m
R		= \033[0;31m
B		= \033[0;96m
Y		= \033[0;33m
WY		= \033[0;93m
M		= \033[0;95m
BOLD	= \033[0;1m
E		= \033[0m

NICE_TEST = compiling

READLINE_DIR = $(shell brew --prefix readline)
READLINE_LIB = -lreadline -lhistory -L $(READLINE_DIR)/lib

all: lib $(NAME)

test: lib $(NAME)

lib:
	@make -C $(LIBFT_PATH)

norminette:
	@echo ""
	@echo "$(Y) ---- N O R M I N E T T E ----$(E)"
	@sleep 1
	@echo "$(BOLD)"
	@norminette
	@echo ""
	@echo "$(Y)------- $(G)EVERITHING OK$(Y) -------$(E)"

$(NAME): $(OBJS)
	@$(COMP) $(CFLAGS) $(LDFLAGS) $(OBJS) $(LIBFT) $(READLINE_LIB) -o $(NAME)
	@echo "$(Y)0-----------------------0"
	@echo "$(Y)|$(G)    MINISHELL CREATED $(Y) |"
	@echo "$(Y)0-----------------------0"
	@echo "$(E)"

clean:
	@/bin/rm -f $(OBJS)

fclean: clean
	@echo ""
	@echo "$(Y)0------------------------0"
	@echo "$(Y)|$(M)  EVERYTHING CLEANED   $(Y) |"
	@echo "$(Y)0------------------------0"
	@echo "$(E)"
	@/bin/rm -f $(NAME)
	@make -C libft/ fclean
	@find . -type f ! -name "*.*" ! -name "Makefile" -not -path "./.git/*" -delete

superclean: fclean
	@rm -rf redir
re: fclean all

.PHONY: all clean fclean re
.SILENT: al $(OBJS)
