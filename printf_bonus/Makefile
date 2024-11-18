# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ibaby <ibaby@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/17 12:57:50 by madamou           #+#    #+#              #
#    Updated: 2024/10/10 05:07:1 by ibaby            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

BLACK=	$(shell tput -Txterm setaf 0)
RED= 	$(shell tput -Txterm setaf 1)
GREEN= 	$(shell tput -Txterm setaf 2)
WHITE= 	$(shell tput -Txterm setaf 7)
YELLOW=	$(shell tput -Txterm setaf 3)
BLUE=	$(shell tput -Txterm setaf 6)
PURPLE=	$(shell tput -Txterm setaf 5)
END= 	$(shell tput -Txterm sgr0)

CC = cc

C_FLAGS = -Wall -Wextra -Werror -g3

OBJS_DIR = .objets/

LIBFT = $(addprefix libft/, ft_strcmp.c ft_strjoin.c ft_re_strdup.c ft_strdup.c ft_re_strjoin.c ft_memmove.c ft_memcpy.c ft_strlcpy.c ft_strlcat.c free_2d_array.c ft_strlen_2d.c ft_strdup.c ft_isdigit.c ft_strlen.c ft_memset.c ft_putendl_fd.c ft_putstr_fd.c ft_putchar_fd.c )

SRCS = ft_printf.c boolUtils.c parsing.c utils.c converts.c argHandling.c $(LIBFT)

OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

CREATE_OBJ_DIR = mkdir -p $(OBJS_DIR)/libft

#		LOADING BAR		#
G				= $(BLUE)
X 				= $(END)
BAR_SIZE		= 50

TOTAL_FILES		:= $(words $(SRCS))
COMPILED_FILES	:= 0
#						#

NAME = libftprintf.a

all : $(NAME)

message:
	@echo "👷$(GREEN)compiling printf files$(END)👷"

bonus: $(NAME)

$(NAME) : message $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo
	@echo "💻$(BLUE)library created $(END)✅"
	@echo

$(OBJS_DIR)%.o : %.c
	@$(CREATE_OBJ_DIR)
	@$(CC) $(C_FLAGS) -c $< -o $@
# @$(eval COMPILED_FILES := $(shell echo $$(($(COMPILED_FILES)+1))))
# @echo -n ""
# @for i in `seq 1 $(shell echo "$$(($(COMPILED_FILES)*$(BAR_SIZE)/$(TOTAL_FILES)))")`; do \
# 	echo -n "$(G)▰$(X)" ; \
# done
# @for i in `seq 1 $(shell echo "$$(($(BAR_SIZE)-$(COMPILED_FILES)*$(BAR_SIZE)/$(TOTAL_FILES)))")`; do \
# 	echo -n "▱" ; \
# done
# @echo -n " [$(shell echo "scale=2; $(COMPILED_FILES)/$(TOTAL_FILES) * 100" | bc)%] "
# @printf "\e[0K\r"

clean : 
	@rm -rf $(OBJS_DIR)
	@echo "🧼🧼$(PURPLE)objects cleaned$(END)🧼🧼"

fclean : clean
	@rm -rf $(NAME)
	@echo "🧼🧼$(PURPLE)executable cleaned$(END)🧼🧼"

re : fclean all

.PHONY : all clean fclean re debug push leak docker 
