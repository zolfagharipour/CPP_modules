# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/17 12:23:32 by mzolfagh          #+#    #+#              #
#    Updated: 2024/08/20 18:06:59 by mzolfagh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = btc

SRCS =  main.cpp BitcoinExchange.cpp
OBJS = ${SRCS:.cpp=.o}

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g
RM	=	rm -rf

all: ${NAME}

${NAME}: ${OBJS}
	${CXX} ${CXXFLAGS} -o ${NAME} $^

%.o: %.cpp
	${CXX} ${CXXFLAGS} -c $< -o $@


clean: 
	${RM} ${OBJS}


fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all bonus clean fclean re
