##
## Makefile for allum1 in /home/boulay_b/Work/cprogelem/Allum1
##
## Made by Boulay Arnaud
## Login   <boulay_b@epitech.net>
##
## Started on  Tue Feb 10 15:27:19 2015 Boulay Arnaud
## Last update Fri Feb 20 02:23:11 2015 Boulay Arnaud
##

NAME	= allum1

SRCSFO	= sources/

SRCS	= $(SRCSFO)main.c \
	  $(SRCSFO)get_next_line.c \
	  $(SRCSFO)game.c \
	  $(SRCSFO)list.c \
	  $(SRCSFO)check.c \
	  $(SRCSFO)disp.c \
	  $(SRCSFO)init.c \
	  $(SRCSFO)strtowordtab.c \
	  $(SRCSFO)tools.c

OBJS	= $(SRCS:.c=.o)

CFLAGS	= -Iinclude/ -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	cc -o $(NAME) $(OBJS) $(CFLAGS)

clean:
	rm -rf $(OBJS)

fclean:	clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
