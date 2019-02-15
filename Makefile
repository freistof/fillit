#******************************************************************************#
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fblom <marvin@codam.nl>                      +#+                      #
#                                                    +#+                       #
#    Created: 2019/02/15 04:18:50 by fblom         #+#    #+#                  #
#    Updated: 2019/02/15 04:22:13 by fblom         ########   odam.nl          #
#                                                                              #
#******************************************************************************#

NAME = fillit

FLAGS = -Wall -Werror -Wextra

INCL = fillit.h

SRCS =

all: $(NAME)

$(NAME):
	gcc -c $(FLAGS) $(SRCS) -I $(INCL)
	ar rc $(NAME) $(OSRC)

clean:


fclean: clean
	rm -f $(NAME)

re: fclean all