# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: victofer <victofer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/08 18:12:44 by victofer          #+#    #+#              #
#    Updated: 2023/05/18 10:07:15 by victofer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	minishell
CFLAGS 	= 	-Wall -Wextra -Werror -g

LIBFT_D	=	libft
SRC 	= 	src/main.c \
		 	src/parser.c \
			src/print_leaks_and_testing.c \
			struct/free_stuff.c \
			struct/init_struct.c \
			struct/fill_next_struct.c \
			get/get_cmd.c \
			get/get_flags.c \
			get/get_output.c \
			get/get_input.c \
			get/get_parameters.c \
			env_vars/env_var_line.c \
			env_vars/env_redirections.c \
			utils/utilities.c \
			utils/utilities_2.c \
			utils/utilities_3.c \
			utils/utilities_4.c \
	
OBJS	=	$(SRC:.c=.o)

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

all: nice_text lib $(NAME)

lib:
	@make -C $(LIBFT_D)

nice_text:
	@echo "$(B)"
	@echo "Minishell / parser"
	@echo "$(E)"

norminette:
	@echo ""
	@echo "$(Y) ---- N O R M I N E T T E ----$(E)"
	@sleep 1
	@echo "$(BOLD)"
	@norminette
	@echo ""
	@echo "$(Y)------- $(G)EVERITHING OK$(Y) -------$(E)"

$(NAME): $(OBJS)
	@mkdir -p redir
	@gcc $(CFLAGS) libft/libft.a $(OBJS) -o $(NAME) 
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
.SILENT: $(OBJS)