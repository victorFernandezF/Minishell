# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: victofer <victofer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/11 17:49:58 by victofer          #+#    #+#              #
#    Updated: 2023/04/18 18:15:50 by victofer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	minishell
CFLAGS 	= 	-Wall -Wextra -Werror -g

LIBFT_D	=	libft
SRC 	= 	src/main.c \
		 	src/parser.c \
			src/leaks.c \
			src/free_stuff.c \
			utils/get.c \
			utils/utilities.c \
			utils/output_management.c \
			utils/get_env_vars.c \
			utils/get_params.c \
	
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

re: fclean all
.PHONY: all clean fclean re
.SILENT: $(OBJS)