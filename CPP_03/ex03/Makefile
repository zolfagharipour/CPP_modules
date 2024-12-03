# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/22 12:06:03 by mzolfagh          #+#    #+#              #
#    Updated: 2024/06/13 12:36:52 by mzolfagh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = DiamondTrap

SRCS =  ClapTrap.cpp main.cpp FragTrap.cpp ScavTrap.cpp DiamondTrap.cpp

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
