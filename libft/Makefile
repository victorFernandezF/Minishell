# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: victofer <victofer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/08 18:14:33 by victofer          #+#    #+#              #
#    Updated: 2023/07/26 09:59:08 by victofer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC	=	gcc
NAME	=	libft.a
CFLAGS	=	-Wall -Wextra -Werror
OPTIONS	=	-c -I.
SRC		=	mem_functions/ft_memcpy.c mem_functions/ft_memmove.c mem_functions/ft_memchr.c \
			mem_functions/ft_memcmp.c mem_functions/ft_calloc.c mem_functions/ft_memset.c \
			str_functions/ft_isalpha.c str_functions/ft_isdigit.c str_functions/ft_isalnum.c \
			str_functions/ft_isascii.c str_functions/ft_isprint.c str_functions/ft_strlen.c \
			str_functions/ft_bzero.c str_functions/ft_strcpy.c str_functions/ft_strlcpy.c \
			str_functions/ft_strlcat.c str_functions/ft_toupper.c str_functions/ft_tolower.c \
			str_functions/ft_strchr.c str_functions/ft_strrchr.c str_functions/ft_strncmp.c \
			str_functions/ft_strnstr.c str_functions/ft_str_rev.c str_functions/ft_split.c \
			str_functions/ft_strdup.c str_functions/ft_substr.c str_functions/ft_strjoin.c \
			str_functions/ft_strtrim.c str_functions/ft_itoa.c str_functions/ft_strmapi.c \
			str_functions/ft_striteri.c str_functions/ft_putchar_fd.c str_functions/ft_putstr_fd.c \
			str_functions/ft_putendl_fd.c str_functions/ft_putnbr_fd.c\
			str_functions/ft_split_2.c str_functions/ft_split.c \
			str_functions/ft_strdup.c str_functions/are_two_strs_equal.c \
			nbr_functions/max.c nbr_functions/min.c nbr_functions/ft_atoi.c \
			base_change_functions/ft_put_hexa.c base_change_functions/ft_put_bin.c \
			base_change_functions/ft_put_oct.c base_change_functions/ft_atoi_base.c\
			base_change_functions/ft_change_bases.c \
			list_functions/sort_list.c \
			printf/ft_printf.c printf/ft_print_c_str_int.c printf/ft_print_char_str.c \
			printf/ft_print_unsigned.c printf/ft_print_hexa.c printf/ft_print_ptr.c \
	 		printf/ft_print_number.c \
			gnl/get_next_line_utils.c gnl/get_next_line.c \

BONUS 	=	list_functions/ft_lstnew.c list_functions/ft_lstadd_front.c list_functions/ft_lstsize.c \
			list_functions/ft_lstlast.c list_functions/ft_lstadd_back.c list_functions/ft_lstdelone.c \
			list_functions/ft_lstclear.c list_functions/ft_lstiter.c list_functions/ft_lstmap.c
OBJ		=	$(SRC:.c=.o)
OBJ_B	=	$(BONUS:.c=.o)
 
# - COLOURS - 
G		=	\033[0;32m
R		=	\033[0;31m
B		=	\033[0;34m
Y 		=	\033[0;93m
M		=	\033[0;95m
E		=	\033[0m

#  - RULES - 
all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

bonus: $(OBJ) $(OBJ_B)
	ar rcs $(NAME) $(OBJ) $(OBJ_B)

norminette:
	@echo ""
	@echo "$(Y) ---- N O R M I N E T T E ----$(E)"
	@sleep 1
	@echo "$(BOLD)"
	@norminette
	@echo "$(Y)------- $(G)EVERITHING OK$(Y) -------$(E)"

clean:
	rm -f $(OBJ) $(OBJ_B)

fclean: clean
	rm -f $(NAME)

re: fclean all	

every: all bonus

revery: fclean all bonus

.SILENT: $(OBJS)
.PHONY: clean fclean all re bonus