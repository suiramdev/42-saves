INCLUDES_PATH = includes

SOURCES_PATH = srcs
SOURCES = ft_putchar.c \
		  ft_swap.c \
		  ft_putstr.c \
		  ft_strlen.c \
		  ft_strcmp.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Starting messing with stuff
OBJECTS = $(addprefix $(SOURCES_PATH)/, $(SOURCES:%.c=%.o))

%.o: %.c
	$(CC) $(CFLAGS) -I $(INCLUDES_PATH) -c $< -o $@

libft.a: $(OBJECTS)
	ar rsc libft.a $(OBJECTS)

all: libft.a

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f libft.a

re: fclean all

.PHONY: all
