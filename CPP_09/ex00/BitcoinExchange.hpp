/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 12:24:05 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/08/26 16:03:43 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <string>
# include <iostream>
# include <iomanip>
# include <fstream>
# include <algorithm>
# include <sstream>
# include <map>


class BitcoinExchange
{
private:
	std::map<std::string, float>	_data;
	std::fstream					_inputFile;
	std::string						_firstDate;

	bool	_checkLine( std::string line );
	bool	_checkDate( std::string date );
	bool	_dateFormat( std::string date );
	float	_getPrice( std::string date, float bitCoin );

public:
	BitcoinExchange( void );
	BitcoinExchange( const std::string csvFile );
	BitcoinExchange( const BitcoinExchange& other );
	~BitcoinExchange( void );

	BitcoinExchange&	operator=( const BitcoinExchange& other );
	
	const std::map<std::string, float>&		getData( void ) const;
	const std::string&						getFirstDate( void ) const;
	
	
	void								inputFile( std::string inputFile );
	void								print( void );


	class FileCantOpen : public std::exception {
		public:
			const char*	what() const throw();
	};
	
	class BadFile : public std::exception {
		public:
			const char*	what() const throw();
	};
};


#endif