/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:38:54 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/06/01 11:25:09 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
private:
	const Fixed	_x;
	const Fixed	_y;
public:
	Point( void );
	Point( const float x, const float y );
	Point( const Fixed x, const Fixed y );
	Point( const Point& other );
	Point operator=( const Point& other);
	
	const Fixed&	fixedX( void ) const;
	const Fixed&	fixedY( void ) const;
	float	getX( void ) const;
	float	getY( void ) const;

    Point operator+( const Point& other ) const;
    Point operator-( const Point& other ) const;
    Fixed operator*( const Point& other ) const;
	
	~Point();
};


// bool    bsp( Point const a, Point const b, Point const c, Point const point );


#endif