NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs
RM = rm -rf

SRCS = ft_printf.c \
	   printf_utils.c \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Compilando libreria"
	@$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	@echo "Libreria compilada"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Limpiando archivos .o"
	@$(RM) $(OBJS)

fclean: clean
	@echo "Eliminando libreria"
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re