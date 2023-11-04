# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 16:53:40 by gyoon             #+#    #+#              #
#    Updated: 2023/11/04 17:22:39 by gyoon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= miniRT

# **************************************************************************** #
#                                                                              #
#    Options                                                                   #
#                                                                              #
# **************************************************************************** #

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -rf

ifeq ($(shell uname -p), arm)
	ARM	= 1
else
	ARM	= 0
endif

# **************************************************************************** #
#                                                                              #
#    Source Files                                                              #
#                                                                              #
# **************************************************************************** #

SRCS		= ./src/main.c $(wildcard ./src/*/*.c) $(wildcard ./src/*/*/*.c) $(wildcard ./src/*/*/*/*.c) 
OBJS		= $(SRCS:.c=.o)

MLX_PATH	= ./lib/minilibx
FT_PATH		= ./lib/libft
MLX			= ./lib/minilibx/libmlx.a
LIBFT		= ./lib/libft/libft.a

INCLUDE		= ./include

# **************************************************************************** #
#                                                                              #
#    Progress                                                                  #
#                                                                              #
# **************************************************************************** #


num_file	= $(shell echo $(SRCS) | tr ' ' '\n' | wc -w)
cnt			:= 0
bar_done	= '🟩🟩🟩🟩🟩🟩🟩🟩🟩🟩🟩🟩🟩🟩🟩🟩'
bar_ready	= '⬜️⬜️⬜️⬜️⬜️⬜️⬜️⬜️⬜️⬜️⬜️⬜️⬜️⬜️⬜️⬜️'

#			COLOR
red			= \e[1;31m
grn			= \e[1;32m
yel			= \e[1;33m
blu			= \e[1;34m
mag			= \e[1;35m
cyn			= \e[1;36m
bold		= \e[1;37m
end			= \e[0m

ifdef BONUS
	version = "bonus version"
else
	version = "mandatory version"
endif

# **************************************************************************** #
#                                                                              #
#    Executable Section                                                        #
#                                                                              #
# **************************************************************************** #

all : $(NAME)

$(NAME) : $(LIBFT) $(MLX) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS)\
		-L$(MLX_PATH) 		\
		-L$(FT_PATH) 		\
		-lmlx -lft			\
		-framework OpenGL	\
 		-framework Appkit 	\
		-D ARM=$(ARM)		\
		-I $(INCLUDE) -o $@
	@printf "\rCompiling source files... "
	@printf "%.$(shell printf "%d" 64)s" $(bar_done)
	@printf "%7.2f%%\n" 100
	@printf "🔦 Now you can simulate a ray tracer, ${bold}${NAME}.${end}"
	@printf " (%s)\n" $(version)

bonus : 
	@make BONUS=1 all

$(LIBFT) :
	@printf "Build ${bold}[LIBFT]${end}\n"
	@make -C $(FT_PATH) -s
	@printf "${grn}BUILD SUCCESSFUL${end}\n\n"

$(MLX) :
	@printf "Build ${bold}[MINILIBX]${end}\n"
	@make re -C $(MLX_PATH) -s
	@printf "${grn}BUILD SUCCESSFUL${end}\n\n"

%.o : %.c
	@$(eval cnt=$(shell printf $$(($(cnt)+1))))
	@$(eval rate_hex=$(shell echo "scale=2; ($(cnt) / $(num_file)) * 16" | bc))
	@$(eval len=$(shell printf "%.0f\n" $(rate_hex)))
	@$(eval len_done=$(shell echo "scale=0; $(len) * 4" | bc))
	@$(eval len_ready=$(shell echo "scale=0; 96 - ($(len_done) / 4) * 6" | bc))
	@$(eval percent=$(shell echo "scale=4; ($(cnt) / $(num_file)) * 100" | bc))
	@printf "\rCompiling source files... "
	@printf "%.$(shell printf "%d" $(len_done))s" $(bar_done)
	@printf "%.$(shell printf "%d" $(len_ready))s" $(bar_ready)
	@printf "%7.2f%%" $(percent)
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDE)

clean :
	@$(RM) $(OBJS)
	@$(RM) $(B_OBJS)
	@make -C $(FT_PATH) clean
	@make -C $(MLX_PATH) clean
	@printf "make clean ${bold}${NAME}.${end}\n"

fclean :
	@make clean
	@$(RM) $(NAME)
	@make -C $(FT_PATH) fclean
	@make -C $(MLX_PATH) clean
	@$(RM) $(MLX)
	@printf "make fclean ${bold}${NAME}.${end}\n"

re :
	@make fclean
	@printf "\n"
	@make all

.PHONY : all bonus clean fclean re