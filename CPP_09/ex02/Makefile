# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/17 12:23:32 by mzolfagh          #+#    #+#              #
#    Updated: 2024/08/26 14:57:04 by mzolfagh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = PmergeMe

SRCS =  main.cpp PmergeMe.cpp PmergeDe.cpp SortVector.cpp SortDeque.cpp
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
