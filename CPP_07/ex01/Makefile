# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/10 11:27:25 by mzolfagh          #+#    #+#              #
#    Updated: 2024/08/02 13:25:01 by mzolfagh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = Iter

SRCS =  main.cpp
OBJS = ${SRCS:.cpp=.o}

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
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
