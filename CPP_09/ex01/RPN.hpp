/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 18:57:36 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/08/26 14:15:02 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# define NONE 0
# define INT 1
# define OPERATION 2


# include <string>
# include <iostream>
# include <stack>
# include <list>

class RPN
{
private:
	std::stack< char, std::list<char> >		_data;

	int		_ctoi( char c );
	void	_operation( std::stack< float, std::list<float> >& intStack );
	int		_whatIs( char c );

public:
	RPN( void );
	RPN( const std::string& input );
	RPN( const RPN& other );
	~RPN( void );
	
	RPN& operator=( const RPN& other );

	void					print( void );
	const std::stack< char, std::list<char> >&	getData( void ) const;

	class GeneralError : public std::exception{
		public:
			const char* what() const throw();
	};
};


#endif