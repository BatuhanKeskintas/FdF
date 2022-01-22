# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkeskint <bkeskint@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 13:14:01 by bkeskint          #+#    #+#              #
#    Updated: 2021/10/23 13:38:35 by bkeskint         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			= 		fdf.c reader.c drawing.c drawing_helpers.c get_next_line.c  \
					get_next_line_utils.c

OBJ			= 		${SRC:.c=.o}

LIBFTSRC 	= 	libft/ft_memset.c libft/ft_bzero.c libft/ft_memcpy.c libft/ft_memccpy.c libft/ft_strlen.c \
				libft/ft_strlcpy.c libft/ft_memmove.c libft/ft_memchr.c libft/ft_memcmp.c libft/ft_strlcat.c \
				libft/ft_strchr.c libft/ft_strrchr.c libft/ft_strncmp.c libft/ft_strnstr.c libft/ft_atoi.c \
				libft/ft_isalpha.c libft/ft_isdigit.c libft/ft_isalnum.c libft/ft_isascii.c libft/ft_isprint.c \
				libft/ft_toupper.c libft/ft_tolower.c libft/ft_calloc.c libft/ft_strdup.c libft/ft_substr.c \
				libft/ft_strjoin.c libft/ft_strtrim.c libft/ft_split.c libft/ft_itoa.c libft/ft_strmapi.c \
				libft/ft_putchar_fd.c libft/ft_putstr_fd.c libft/ft_putendl_fd.c libft/ft_putnbr_fd.c \
				libft/ft_exit.c

FRAMEWORKS	=		-framework OpenGL -framework AppKit

CC			= 		gcc
CFLAGS		= 		-Wall -Wextra -Werror

NAME		= 		FdF

INCLUDES	=		libft/libft.a minilibx_macos/libmlx.a

all:
			@make -C libft/ all
			@make -C minilibx_macos/ all
			$(CC) $(SRC) -o $(NAME) $(CFLAGS) $(INCLUDES) $(FRAMEWORKS)

clean:
			@make -C libft/ clean

fclean: 	clean
			/bin/rm -f $(NAME)
			@make -C libft/ fclean

re: 		fclean all