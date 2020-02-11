# library name
NAME = libftprintf.a

# compiler
CC = clang

# compilation flags
CF = -Wall -Wextra -Werror

# directories
SRCS = ./srcs
OBJ = ./obj
INCLUDES = ./includes
LIBFT = ./libft

# header
FT_PRINTF_HEADER = $(patsubst %, $(INCLUDES)/%.h, libftprintf)
LIBFT_HEADER = $(patsubst %, $(LIBFT)/$(INCLUDES)/%.h, libft)

# static library
FT_PRINTF_SLIB = $(NAME)

# function names
FT_PRINTF_SRC = ft_printf parse parse_utils \
				utils print print_num is_utf8 \
				is_utf8_3b is_utf8_4b print_txt \
				print_base print_decimal print_wide \
				print_utils print_utils2 colors cast

# object files
FT_PRINTF_O_FILES =  $(patsubst %, $(OBJ)/%.o, $(FT_PRINTF_SRC))

.PHONY: clean fclean re all libft

all: $(NAME)

libft: $(LIBFT)
	make -C $(LIBFT)

$(OBJ)/ft_printf.o: $(SRCS)/ft_printf.c $(FT_PRINTF_HEADER) $(LIBFT_HEADER)
	@mkdir -p $(OBJ)
	$(CC) $(CF) -c $(SRCS)/ft_printf.c -o $(OBJ)/ft_printf.o -I $(INCLUDES) -I $(LIBFT)/$(INCLUDES)

$(OBJ)/%.o: $(SRCS)/%.c $(FT_PRINTF_HEADER) $(LIBFT_HEADER)
	@mkdir -p $(OBJ)
	$(CC) $(CF) -c $< -o $@ -I $(INCLUDES) -I $(LIBFT)/$(INCLUDES)

$(NAME): libft $(FT_PRINTF_O_FILES)
	@cp $(LIBFT)/libft.a ./$(NAME)
	ar rc $(NAME) $(FT_PRINTF_O_FILES)
	ranlib $(NAME)

clean:
	rm -rf $(OBJ)
	make clean -C $(LIBFT)

fclean: clean
	rm -rf $(FT_PRINTF_SLIB)
	make fclean -C $(LIBFT)

re: fclean all