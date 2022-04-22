SRCS		=	srcs/operations/push.c		\
				srcs/operations/rotate_reverse.c		\
				srcs/operations/rotate.c		\
				srcs/operations/swap.c		\
				srcs/handler_tab.c		\
				srcs/main.c		\
				srcs/handler_tab,c 	\


OBJS			= $(SRCS:.c=.o)

NAME			= push_swap

CFLAGS			= -Wall -Wextra -Werror

RM				= rm -f

CC				= gcc

AR				= ar rcs

.c.o:
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L.

all:			$(NAME)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all


.PHONY:			all clean fclean c.o re
