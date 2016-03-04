##
## asciifun.c for octocat in /home/amira_s/octo/src
## 
## Made by AMIRA Syrine
## Login   <amira_s@etna-alternance.net>
## 
## Started on  Fri Jan  22 12:23:25 2015 AMIRA Syrine
## Last update Fri Jan  22 16:45:07 2015 AMIRA Syrine
##

NAME		=	solve

SRC 		=	lib/my_putchar.c 		\
				lib/my_putstr.c 		\
				lib/my_put_nbr.c 		\
				lib/my_getnbr.c 		\
				lib/my_strlen.c 		\
				lib/my_strcmp.c 		\
				lib/my_strcat.c 		\
				lib/noop.c    			\
				lib/dynamic_array.c     \
				lib/dynamic_array2.c    \
				lib/swap.c 		        \
				lib/memcpy.c 	        \
				lib/vect.c   	        \
				lib/vect2.c   	        \
				lib/trace.c   	        \
				src/getmap.c 			\
				src/play.c 				\
				src/outcome.c 			\
				src/paths.c 			\
				src/print.c 			\
				src/copymap.c			\
				src/freeing.c			\
				src/init.c 				\
				src/solve.c

INC_DIR		=	.

OBJ			=	$(SRC:%.c=%.o)

CFLAGS		=   -g -W -Wall -Werror -pedantic -ansi -Wextra

CC			=	gcc

RM			=	rm -f

all:			$(NAME)

$(NAME):		$(OBJ)
				$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
				$(RM) $(OBJ)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
