#******************************************************************************#
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fblom <marvin@codam.nl>                      +#+                      #
#                                                    +#+                       #
#    Created: 2019/02/15 04:18:50 by fblom         #+#    #+#                  #
#    Updated: 2019/02/16 14:42:49 by fblom         ########   odam.nl          #
#                                                                              #
#******************************************************************************#

NAME = fillit

FLAGS = -Wall -Werror -Wextra

INCL = fillit.h

LIB = ../libft/libft.a

SRCS = fillit.c validity.c

all: $(NAME)

$(NAME):
	gcc -o $(NAME) $(FLAGS) $(SRCS) -I $(INCL) $(LIB)

clean:
	rm -f a.out fillit

fclean: clean
	rm -f $(NAME)

re: fclean all

lib:
	make -C libft/

libclean:
	make -C libft/ clean

libfclean:
	make -C libft/ fclean

libre:
	make -C libft/ re
