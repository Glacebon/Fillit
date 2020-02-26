#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hkoskela <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/17 16:10:57 by hkoskela          #+#    #+#              #
#    Updated: 2020/02/26 14:42:15 by hkoskela         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit

INC = ./includes

SRC = srcs/fillit.c srcs/fillithelper.c srcs/fillitmodcoor.c srcs/fillitpiecefits.c srcs/fillitread.c srcs/fillitsolve.c srcs/fillitvalidate.c

OBJ = srcs/fillit.o srcs/fillithelper.o srcs/fillitmodcoor.o srcs/fillitpiecefits.o srcs/fillitread.o srcs/fillitsolve.o srcs/fillitvalidate.o

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	make -C libft/ fclean && make -C libft/
	gcc -o $(NAME) $(FLAGS) $(SRC) libft/libft.a -I$(INC)

.PHONY: clean

clean:
	make -C libft/ clean
	rm -f $(OBJ)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all