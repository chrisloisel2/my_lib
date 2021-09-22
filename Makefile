# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clkuznie <clkuznie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/11 02:24:34 by lchristo          #+#    #+#              #
#    Updated: 2021/03/14 20:37:45 by clkuznie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

LIB_OBJ =	ft_atoi\
			ft_itoa\
			ft_bzero\
			ft_check\
			ft_calloc\
			ft_isalnum\
			ft_isalpha\
			ft_isascii\
			ft_isdigit\
			ft_isprint\
			ft_memccpy\
			ft_memchr\
			ft_memcmp\
			ft_memcpy\
			ft_memccpy\
			ft_memmove\
			ft_memset\
			ft_putchar_fd\
			ft_putendl_fd\
			ft_putnbr_fd\
			ft_putstr_fd\
			ft_split\
			ft_free_strjoin\
			get_next_line\
			get_next_line_utils\
			ft_strchr\
			ft_strdup\
			ft_strjoin\
			ft_strlcat\
			ft_strlcpy\
			ft_strlen\
			ft_strmapi\
			ft_strncmp\
			ft_strnstr\
			ft_strrchr\
			ft_strtrim\
			ft_substr\
			ft_tolower\
			ft_toupper\
			ft_beta\
			ft_white_space\
			ft_supp_gnl\
			ft_printf\
			ft_puthexa\
			ft_putstr\
			ft_get\
			ft_star\
			ft_atoi\
			ft_get_str\
			ft_strjoin\
			ft_get_numbers\
			ft_strlen\
			ft_dot\
			ft_calculus\
			ft_alpha\
			ft_minus\
			ft_zero\
			ft_flag


O = $(addsuffix .o, $(LIB_OBJ))

%.o: %.c $H
	$(CC) $(FLAG) $(OPTION) $< -o $@

H = 	gnl.h \
	 	libft.h \

cc = gcc

FLAG = -Wall -Wextra -Werror

OPTION = -c

all: $(NAME)

$(NAME): $O $H
	ar rc $(NAME) $O
	ranlib $(NAME)

clean:
	/bin/rm -f $O

fclean: clean
	/bin/rm -f $O $(NAME)

re: fclean all