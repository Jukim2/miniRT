# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/09 13:30:09 by jukim2            #+#    #+#              #
#    Updated: 2023/10/01 19:57:39 by jukim2           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c 		\
ft_memset.c ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c 		\
ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c ft_substr.c	\
ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c		\
ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c get_next_line.c	\
get_next_line_utils.c

BONUSFILES = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c			\
ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

BONUSOBJS = $(BONUSFILES:.c=.o)
OBJS = $(FILES:.c=.o)
CCFLAGS = -Wall -Wextra -Werror
NAME = libft.a

ifdef WITH_BONUS
	OBJECTS = $(BONUSOBJS) $(OBJS)
else
	OBJECTS = $(OBJS)
endif

.PHONY : clean bonus all fclean re

all : $(NAME)

$(NAME): $(OBJECTS)
	ar -cr $@ $^

bonus :
	make WITH_BONUS=1 all

%.o : %.c
	$(CC) $(CCFLAGS) -c  -o $@ $<

clean :
	rm -f $(OBJS) $(BONUSOBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
