# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jukim2 <jukim2@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 16:53:40 by gyoon             #+#    #+#              #
#    Updated: 2023/11/05 10:47:32 by jukim2           ###   ########.fr        #
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

SRCS		= src/engine/clean_engine.c src/engine/color/convert_color_vec3.c src/engine/color/correct_color.c src/engine/color/get_color.c src/engine/color/get_specular_color.c src/engine/color/is_valid_color_hex.c src/engine/execute_engine.c src/engine/init_engine.c src/engine/parse/parse.c src/engine/parse/parse_ambient_light.c src/engine/parse/parse_camera.c src/engine/parse/parse_cylinder.c src/engine/parse/parse_failed.c src/engine/parse/parse_light.c src/engine/parse/parse_module.c src/engine/parse/parse_plane.c src/engine/parse/parse_sphere.c src/engine/parse/parse_utils.c src/engine/quit_engine.c src/engine/ray/hit/hit_circle.c src/engine/ray/hit/hit_cylinder.c src/engine/ray/hit/hit_plane.c src/engine/ray/hit/hit_sphere.c src/engine/ray/hit_record/get_hit_record.c src/engine/ray/hit_record/init_hit_record.c src/engine/ray/is_shadowed.c src/engine/ray/raytrace.c src/engine/term_engine.c src/main.c src/numft/abs_double.c src/numft/doublecmp.c src/numft/get_radian.c src/numft/proj_vec3.c src/numft/quat/get_conj_quat.c src/numft/quat/get_rot_quat.c src/numft/quat/mul_quat.c src/numft/quat/norm_quat.c src/numft/quat/print_quat.c src/numft/quat/quat.c src/numft/quat/quatlen.c src/numft/rand_double.c src/numft/rand_vec3_hemisphere.c src/numft/rot_vec3.c src/numft/vec3/add_vec3.c src/numft/vec3/cross_vec3.c src/numft/vec3/dot_vec3.c src/numft/vec3/invert_vec3.c src/numft/vec3/multi_vec3.c src/numft/vec3/norm_vec3.c src/numft/vec3/print_vec3.c src/numft/vec3/rand_vec3.c src/numft/vec3/scale_vec3.c src/numft/vec3/sub_vec3.c src/numft/vec3/vec3.c src/numft/vec3/vec3len.c src/numft/vec3_to_quat.c
OBJS		= $(SRCS:.c=.o)

FT_PATH		= ./lib/libft
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
	@printf "make clean ${bold}${NAME}.${end}\n"

fclean :
	@make clean
	@$(RM) $(NAME)
	@make -C $(FT_PATH) fclean
	@printf "make fclean ${bold}${NAME}.${end}\n"

re :
	@make fclean
	@printf "\n"
	@make all

.PHONY : all bonus clean fclean re