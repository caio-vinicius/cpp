# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csouza-f <caio@42sp.org.br>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/20 23:40:44 by csouza-f          #+#    #+#              #
#    Updated: 2022/01/20 23:51:49 by csouza-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cpp

SOURCES_FILES = main.cpp

all: $(NAME)

$(NAME): $(SOURCES_FILES)
	g++ -std=c++98 -pedantic-errors $^ -o $@

clean:
	echo "clean"

fclean: clean
	rm -f $(NAME)

re: fclean all 
