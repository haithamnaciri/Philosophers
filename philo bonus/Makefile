NAME = philo_bonus
SRCS = srcs/philo.c srcs/philo_utils1.c srcs/philo_utils2.c utils/ft_atoi.c utils/ft_lstadd_back_bonus.c utils/ft_lstlast_bonus.c utils/ft_lstnew_bonus.c utils/ft_lstsize_bonus.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror
all: $(NAME)
$(NAME): $(OBJS)
	cc $(OBJS) -o $(NAME)
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all