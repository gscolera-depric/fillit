# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gscolera <gscolera@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/01 12:42:01 by gscolera          #+#    #+#              #
#    Updated: 2018/12/09 19:45:16 by gscolera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fillit
SRC=fillit.c pusher.c reader.c
SRC1=libft/*.c
OBJ=*.o

$(NAME):
	gcc -Wall -Werror -Wextra -c $(SRC1)
	ar rc libft.a $(OBJ)
	ranlib libft.a
	gcc -Wall -Werror -Wextra $(SRC) -L. -lft -o $(NAME)

all: $(NAME)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME) libft.a

re: fclean all
