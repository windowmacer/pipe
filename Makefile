NAME = pipex

CC = cc

FLAGS = -Wall -Wextra -Werror -I.

HEADER = pipex.h

SRC = ft_strnstr.c ft_strjoin.c ft_strdup.c ft_split.c \
	  pipex.c pipex_utils.c ft_strlen.c

OBJ = $(SRC:c=o)

SRCB = ft_strnstr.c ft_strjoin.c ft_strdup.c ft_split.c \
	   pipex_utils.c ft_heredoc.c pipex_bonus.c get_next_line.c \
	   get_next_line_utils.c ft_strlen.c ft_strncmp.c

OBJB = $(SRCB:c=o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(FLAGS)$(HEADER) -o $(NAME) $(OBJ)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS)$(HEADER) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJB)

fclean:
	rm -f $(OBJ) $(OBJB)
	rm -f $(NAME)

re: fclean all

bonus: $(OBJB) $(HEADER)
	@make OBJ="$(OBJB)" all

.PHONY: clean fclean re bonus