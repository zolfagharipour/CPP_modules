/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 13:43:22 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/08/01 16:33:05 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <sstream>

typedef struct s_data{
	char	c;
	int		i;
	float	f;
	double	d;
} t_data;


int		isAllDigit( std::string str );
bool	isJustADot( std::string str, int mode );
void	runInf( std::string str );
void	runNan( void );
