TARGET = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs
RM = rm -f
INCLUDE_DIR = -I.

# Define colors
DEFAULT_COLOR = \033[0;39m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m

# Source and object file lists
SOURCE_FILES =	ft_printf \
		ft_printf_utils \
		converts \

SOURCES = $(addsuffix .c, $(SOURCE_FILES))
OBJECTS = $(addsuffix .o, $(SOURCE_FILES))

# Build rules

$(TARGET): $(OBJECTS)
	@ make -C libft
	@ cp libft/libft.a .
	@ mv libft.a $(TARGET)
	@ $(AR) $(TARGET) $(OBJECTS)
	@ echo "$(GREEN)Compiled libftprintf.a successfully!$(DEFAULT_COLOR)"

%.o: %.c
	@ $(CC) $(CFLAGS) $(INCLUDE_DIR) -c $< -o $@
	@ echo "$(GREEN)Created object files successfully$(DEFAULT_COLOR)"

all: $(TARGET)

clean:
	@ $(RM) -rf $(OBJECTS)
	@ make clean -C libft
	@ echo "$(RED)Removed object files$(DEFAULT_COLOR)"

fclean: clean
	@ $(RM) $(TARGET)
	@ $(RM) libft/libft.a
	@ echo "$(RED)Removed 'libftprintf.a' and 'libft.a' successfully$(DEFAULT_COLOR)"

bonus: all

re: fclean all