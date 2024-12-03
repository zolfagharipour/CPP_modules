/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 09:34:05 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/08/14 11:06:12 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

void	Form::_checkGrade( int grade )
{
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
}

Form::Form( void ) : _name("Default Form"), _signGrade(150), _execGrade(150), _signature(0)
{
	std::cout << "Form default constructor is called" << std::endl;
}

Form::Form( std::string name, int signGrade, int execGrade ) : _name(name), _signGrade(signGrade), _execGrade(execGrade), _signature(0)
{
	std::cout << "Form constructor is called" << std::endl;
	_checkGrade(signGrade);
	_checkGrade(execGrade);
}

Form::Form( const Form& other ) : _name(other._name)
								, _signGrade(other._signGrade)
								, _execGrade(other._execGrade)
{
	std::cout << "Form copy constructor is called" << std::endl;
	*this = other;
}
Form& Form::operator=( const Form& other )
{
	if (this == &other)
		return (*this);
	this->_signature = other._signature;
	return (*this);
}

Form::~Form( void )
{
	std::cout << "Form destructor is called" << std::endl;
}


const std::string	Form::getName( void ) const
{
	return(_name);
}
bool	Form::getSignature( void ) const
{
	return(_signature);
}
int	Form::getSignGrade( void ) const
{
	return(_signGrade);
}
int	Form::getExecGrade( void ) const
{
	return(_execGrade);
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}

void	Form::besigned( const Bureaucrat& other )
{
	if (other.getGrade() > this->getSignGrade())
		throw GradeTooLowException();
	_signature = 1;
}


std::ostream& operator<<( std::ostream& os, const Form& obj )
{
	os << "Form " << obj.getName() << " is ";
	if (!obj.getSignature())
		os << "not ";
	os << "signed.\nGrade required to sign:\t\t" << obj.getSignGrade()
		<< "\nGrade required to execute:\t" << obj.getExecGrade();
	return os;
}