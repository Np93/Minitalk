# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nhirzel <marvin@42lausanne.ch>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 20:17:06 by nhirzel           #+#    #+#              #
#    Updated: 2021/12/17 18:59:42 by nhirzel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = server

NAME2 = client

CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f
CC		= gcc

FILES_NAME1	= server.c \
			outils.c \

FILES_NAME2	= client.c \
			outils.c \

all : $(NAME1) $(NAME2)

OBJS_NAME1 	= $(FILES_NAME1:.c=.o)

OBJS_NAME2 	= $(FILES_NAME2:.c=.o)
.c.o:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME1): $(OBJS_NAME1)
		$(CC) $(CFLAGS) $(OBJS_NAME1) -o $(NAME1)

$(NAME2): $(OBJS_NAME2)
		$(CC) $(CFLAGS) $(OBJS_NAME2) -o $(NAME2)

clean : 
	$(RM) $(OBJS_NAME1) $(OBJS_NAME2)

fclean : clean
	$(RM) $(NAME1) $(NAME2)

re : fclean all

.PHONY:	all clean fclean re
