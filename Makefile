# FILES = HumanA.cpp HumanB.cpp Weapon.cpp main.cpp
# SRCS = $(addprefix srcs/, $(FILES))
# SRCS = parse.c get_next_line.c get_next_line_utils.c main.c
SRCS = $(wildcard */*/*.c)  
OBJS = $(SRCS:.c=.o)
NAME = miniRT
LIBFT = libft.a
#CPPFLAGS = -fsanitize=address -g3#-Wall -Wextra -Werror

INCLUDES = -Iincludes

.PHONY : clean all fclean re

all : $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) -o $(NAME) $(CPPFLAGS) $(OBJS) $(LIBFT)

$(LIBFT) : 
	make -C ./libft
	mv ./libft/libft.a ./

%.o : %.c
	$(CC) $(CPPFLAGS) -c -o $@ $< $(INCLUDES)
	
clean :
	rm -f $(OBJS)
	make clean -C ./libft

fclean :
	rm -f $(OBJS)
	rm -f $(NAME)
	rm -f $(LIBFT)
	make fclean -C ./libft

re :
	$(MAKE) fclean
	$(MAKE) all

test :
	cc test.c -lmlx -Iincludes -framework OpenGL -framework Appkit srcs/vector3/*.c

home : 
	cc test.c -Iincludes -framework OpenGL -framework Appkit libmlx.a srcs/vector3/*.c
