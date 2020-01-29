# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aagripin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/11 13:17:52 by aagripin          #+#    #+#              #
#    Updated: 2019/12/06 16:08:06 by aagripin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_atol.c ft_error.c ft_strndup.c get_next_line.c ft_itoa_base.c ft_create_elem.c ft_list_clear.c ft_list_push_back.c ft_list_size.c ft_memccpy.c ft_str_is_uppercase.c ft_strncmp.c ft_memchr.c ft_strcapitalize.c ft_strncpy.c ft_memcmp.c ft_strcat.c ft_strnequ.c ft_memcpy.c ft_strchr.c ft_strnew.c ft_atoi.c ft_memdel.c ft_strclr.c ft_strnstr.c ft_bzero.c ft_memmove.c ft_strcmp.c ft_strrchr.c ft_isalnum.c ft_memset.c ft_strcpy.c ft_strsplit.c ft_isalpha.c ft_putchar.c ft_strdel.c ft_strstr.c ft_isascii.c ft_putchar_fd.c ft_strdup.c ft_strsub.c ft_isdigit.c ft_putendl.c ft_strequ.c ft_strtrim.c ft_isprint.c ft_putendl_fd.c ft_striter.c ft_strupcase.c ft_itoa.c ft_putnbr.c ft_striteri.c ft_tolower.c ft_lstadd.c ft_putnbr_fd.c ft_strjoin.c ft_toupper.c ft_lstdel.c ft_putstr.c ft_strlcat.c ft_lstdelone.c ft_putstr_fd.c ft_strlen.c ft_lstiter.c ft_str_is_alpha.c ft_strlowcase.c ft_lstmap.c ft_str_is_lowercase.c ft_strmap.c ft_lstnew.c ft_str_is_numeric.c ft_strmapi.c ft_memalloc.c ft_str_is_printable.c ft_strncat.c

all: $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror -c libft.h $(SRC) 
	@ar rc $(NAME) $(SRC:.c=.o) libft.h
%.o : %.c
	gcc -Wall -Wextra -Werror libft.h -o $@ -c $<
clean:
	@/bin/rm -f $(SRC:.c=.o)
fclean: clean
	@/bin/rm -f $(NAME) libft.h.gch
re: fclean all
.PHONY: all clean fclean re
