/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 12:31:11 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/08/30 11:15:07 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange( void ) : _firstDate("")
{
}

BitcoinExchange::BitcoinExchange( const std::string csvFile ) : _firstDate("~")
{
	std::fstream					fin;
	std::string						date, price;
	std::stringstream				ss;
	float							fPrice;

	fin.open(csvFile.c_str(), std::ios::in);
	if (!fin.is_open())
		throw FileCantOpen();
	getline(fin, date);
	if (date != "date,exchange_rate")
	{
		std::cerr << "Parsing Error: no header in csv file." << std::endl;
		throw  BadFile();
	}
	while (getline(fin, date, ','))
	{
		if (date < _firstDate && _dateFormat(date))
			_firstDate = date;
		getline(fin, price);
		ss.clear();
		ss.str(price);
		ss >> fPrice;
		if (!ss.fail() && _dateFormat(date) && _checkDate(date) && fPrice >= 0)
			_data.insert(std::make_pair(date, fPrice));
	}
	fin.close();
	if (_firstDate == "~")
		throw BadFile();
}

BitcoinExchange::BitcoinExchange( const BitcoinExchange& other )
{
	*this = other;
}

BitcoinExchange::~BitcoinExchange( void )
{
	if (_inputFile.is_open())
		_inputFile.close();
}



BitcoinExchange&	BitcoinExchange::operator=( const BitcoinExchange& other )
{
	std::string			date, price;
	std::stringstream	ss;
	float				fPrice;

	if (this == &other)
		return (*this);
	_firstDate = other.getFirstDate();
	_data.clear();
	for (std::map<std::string, float>::const_iterator cit = other.getData().begin(); cit != other.getData().end(); cit++)
	{
		date = cit->first;
		fPrice = cit->second;
		_data.insert(std::make_pair(date, fPrice));
	}
	return (*this);	
}





float	BitcoinExchange::_getPrice( std::string date, float bitCoin )
{
	float	result = 0;

	for (std::map<std::string, float>::iterator it = _data.begin(); it != _data.end(); it++)
	{
		if (it->first > date)
			return ((--it)->second * bitCoin);
		else if (it->first == date)
			return (it->second * bitCoin);
		result = it->second * bitCoin;
	}
	return (result);
}

bool	BitcoinExchange::_dateFormat( std::string date )
{
	if (date.length() != 10)
		return (false);
	for (int i = 0; i < 10; i++)
	{
		if (i != 4 && i != 7 && !isdigit(date[i]))
			return (false);
		else if ((i == 4 || i == 7) && date[i] != '-')
			return (false);
	}
	return (true);
}

bool	BitcoinExchange::_checkLine( std::string line )
{
	std::string			date, price;
	std::stringstream	ss;
	float				fPrice;
	bool				firstComma = true;
		
	if (line.length() < 14)
	{
		std::cerr << "Error: Bad Input => " << line << std::endl;
		return (false);
	}
	for (int i = 0; i < 10; i++)
	{
		if (i != 4 && i != 7 && !isdigit(line[i]))
		{
			std::cerr << "Error: Bad date format => " << line << std::endl;
			return (false);
		}
		else if ((i == 4 || i == 7) && line[i] != '-')
		{
			std::cerr << "Error: Bad date format => " << line << std::endl;
			return (false);
		}
	}
	if (line[10] != ' ' || line[11] != '|' || line[12] != ' ')
	{
		std::cerr << "Error: Bad Input => " << line << std::endl;
		return (false);
	}
	price = line.substr(12);
	ss.clear();
	ss.str(price);
	ss >> fPrice;
	if(ss.fail())
	{
		std::cerr << "Error: Bad Input => " << line << std::endl;
		return (false);
	}
	if (fPrice < 0)
	{
		std::cerr << "Error: Not a positive number." << std::endl;
		return (false);
	}
	if(fPrice > 1000)
	{
		std::cerr << "Error: Too large of a number." << std::endl;
		return (false);
	}
	
	for (unsigned int i = 1; i < price.length(); i++)
	{
		if (!isdigit(price[i]))
		{
			if (!(price[i] == '.' && firstComma == true))
			{
				std::cerr << "Error: bad input => " << price << std::endl;
				return (false);
			}
		}
		if (price[i] == '.')
			firstComma = false;
	}
	return (true);
}

bool	BitcoinExchange::_checkDate( std::string date )
{
	std::stringstream	ss;
	int					fYear, fMonth, fDay;

	ss.clear();
	ss.str(date.substr(0, 4));
	ss >> fYear;
	ss.clear();
	ss.str(date.substr(5,8));
	ss >> fMonth;
	ss.clear();
	ss.str(date.substr(8,11));
	ss >> fDay;

	if (date < _firstDate)
	{
		std::cerr << "I can only support dates after " << _firstDate << "!" << std::endl;
		return (false);
	}
	if (fMonth < 1 || fMonth > 12 || fDay > 31 || fDay < 1)
	{
		std::cerr << "Date cannot exist = > " << date << std::endl;
		return (false);
	}
	if (fDay == 31 && (fMonth != 1 && fMonth != 3 && fMonth != 5
			&& fMonth != 7 && fMonth != 8 && fMonth != 10 && fMonth != 12))
	{
		std::cerr << "Date cannot exist = > " << date << std::endl;
		return (false);
	}
	if (fMonth == 2 && fDay > 29)
	{
		std::cerr << "Date cannot exist = > " << date << std::endl;
		return (false);
	}
	if (fMonth == 2 && fDay == 29 && (fYear % 4 != 0 || (fYear % 100 == 0 && fYear % 400 != 0)))
	{
		std::cerr << "Date cannot exist = > " << date << std::endl;
		return (false);
	}
	return (true);
}



void	BitcoinExchange::inputFile( std::string fileName )
{
	_inputFile.open(fileName.c_str(), std::ios::in);
	if (!_inputFile.is_open())
		throw FileCantOpen();
}

const std::map<std::string, float>&	BitcoinExchange::getData( void ) const
{
	return (_data);
}

const std::string& BitcoinExchange::getFirstDate( void ) const
{
	return (_firstDate);
}


void	BitcoinExchange::print( void )
{
	std::stringstream	ss;
	std::string			line, date;
	float				fPrice;
	
	if (!_inputFile.is_open())
	{
		std::cerr << "No input file." << std::endl;
		return ;
	}
	getline(_inputFile, line);
	if (line != "date | value")
	{
		std::cerr << "Parsing Error: no header in input file."<< std::endl;
		return ;
	}
	while (getline(_inputFile, line))
	{
		if (_checkLine(line))
		{
			date = line.substr(0, 10);
			ss.clear();
			ss.str(line.substr(13));
			ss >> fPrice;
			if (!ss.fail() && _checkDate(date))
				std::cout << date << " => " << fPrice << " = " << _getPrice(date, fPrice) << std::endl;
		}
	}
}

const char*	BitcoinExchange::FileCantOpen::what() const throw()
{
	return ("Cant open the file");
}

const char*	BitcoinExchange::BadFile::what() const throw()
{
	return ("Bad csv file format");
}
