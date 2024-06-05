NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
AR = ar rcs

#Sources

SRC =  ft_printf.c \
        ft_printf_utils.c \
		converts.c	\

OBJ = $(SRC:.c=.o)

all:  $(NAME)

$(NAME):    $(OBJ)
			@$(AR) $(NAME) $(OBJ)
			@echo "ft_printf compiled!"

%.o: %.c
			@echo "Compiling: $<"
			@$(CC) $(CFLAGS) -c $< -o $@

clean:
			@$(RM) -f *.o
			@echo "$(BLUE)ft_printf object files cleaned!$(DEF_COLOR)"

fclean:		clean
			@$(RM) -f $(NAME)
			@echo "ft_printf executable files cleaned!$(DEF_COLOR)"

re:			fclean all
			@echo "Cleaned and rebuilt everything for ft_printf!"

.PHONY:		all clean fclean re norm