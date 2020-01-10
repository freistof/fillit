#******************************************************************************#
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fblom <marvin@codam.nl>                      +#+                      #
#                                                    +#+                       #
#    Created: 2019/02/15 04:18:50 by fblom         #+#    #+#                  #
#    Updated: 2019/02/27 14:58:03 by fblom         ########   odam.nl          #
#                                                                              #
#******************************************************************************#

NAME = fillit

LIBPATH = libft/

FLAGS = -Wall -Werror -Wextra

INCL = fillitft/fillit.h

LIB = libft/libft.a

FILES = fillit.c validity.c findcor.c fillit_solver.c makelist.c

SRCS :=${addprefix fillitft/, $(FILES)}

all: $(NAME)

$(NAME):
	make -C $(LIBPATH)
	gcc -o $(NAME) $(FLAGS) $(SRCS) $(LIB)

clean:
	rm -f
	make -C $(LIBPATH) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBPATH) fclean

re: fclean all
	make -C $(LIBPATH) re
