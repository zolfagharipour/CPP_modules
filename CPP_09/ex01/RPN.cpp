/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:58:52 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/08/26 14:16:06 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN( void )
{
}

RPN::RPN( const std::string& input )
{
	for (int i = input.length(); i >= 0; i--)
	{
		if (input[i] != 0 && input[i] != ' ')
			_data.push(input[i]);
	}
}

RPN::RPN( const RPN& other )
{
	*this = other;
}


RPN::~RPN( void )
{
}


RPN& RPN::operator=( const RPN& other )
{
	if (this == &other)
		return (*this);
	_data = other.getData();
	return (*this);
}


int	RPN::_ctoi( char c )
{
	if (c < 48 || c > 57)
		throw GeneralError();
	return (c - 48);
}

void	RPN::_operation( std::stack< float, std::list<float> >& fStack )
{
	float	operand[2];
	char	op;


	if (fStack.size() < 2)
		throw GeneralError();
	op = _data.top();
	_data.pop();
	operand[1] = fStack.top();
	fStack.pop();
	operand[0] = fStack.top();
	fStack.pop();
	if (op == '+')
		fStack.push(operand[0] + operand[1]);
	if (op == '-')
		fStack.push(operand[0] - operand[1]);
	if (op == '*')
		fStack.push(operand[0] * operand[1]);
	if (op == '/')
		fStack.push(operand[0] / operand[1]);
}

int		RPN::_whatIs( char c )
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return (OPERATION);
	if (isdigit(c))
		return (INT);
	return (NONE);
}

void	RPN::print( void )
{
	std::stack< float, std::list<float> >	fStack;
	char									operand;

	if (!_data.size())
		throw GeneralError();
	operand = _data.top();
	_data.pop();
	if (_whatIs(operand) != INT)
		throw GeneralError();
	fStack.push(_ctoi(operand));
	
	while(!_data.empty())
	{
		while (!_data.empty() && _whatIs(_data.top()) == INT)
		{
			operand = _data.top();
			_data.pop();
			fStack.push(_ctoi(operand));
		}
		if (_data.empty() || _whatIs(_data.top()) != OPERATION)
			throw GeneralError();
		_operation (fStack);
	}
	if (fStack.size() != 1)
		throw GeneralError();
	std::cout << fStack.top() << std::endl;
}

const std::stack< char, std::list<char> >& RPN::getData( void ) const
{
	return (_data);
}

const char* RPN::GeneralError::what() const throw()
{
	return ("Error");
}
