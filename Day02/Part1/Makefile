##
## AdventOfCode 2023 Makefile for C
##
##

SRC	=	\

CC	=	gcc

SRC_MAIN	=	src/main.c

NAME		=	Part1

FLAG_DEBUG				=	-Wall -Wextra -g
FLAG_INCLUDE			=	-I include/
FLAG_C_LIBS				=	-lm

COMPILATION_FLAGS	=	$(FLAG_DEBUG) $(FLAG_C_LIBS) $(FLAG_INCLUDE)

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean	all

$(NAME):
	$(CC) -o $(NAME) $(SRC) $(SRC_MAIN) $(COMPILATION_FLAGS)
