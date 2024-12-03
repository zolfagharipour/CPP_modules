/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 09:34:05 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/07/11 10:12:50 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

void	AForm::_checkGrade( int grade )
{
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
}

AForm::AForm( void ) : _name("Default AForm"), _signGrade(150), _execGrade(150), _signature(0)
{
	std::cout << "AForm default constructor is called" << std::endl;
}

AForm::AForm( std::string name, int signGrade, int execGrade ) : _name(name), _signGrade(signGrade), _execGrade(execGrade), _signature(0)
{
	std::cout << "AForm constructor is called" << std::endl;
	_checkGrade(signGrade);
	_checkGrade(execGrade);
}

AForm::AForm( const AForm& other ) : _name(other._name)
								, _signGrade(other._signGrade)
								, _execGrade(other._execGrade)
{
	std::cout << "AForm copy constructor is called" << std::endl;
	*this = other;
}
AForm& AForm::operator=( const AForm& other )
{
	if (this == &other)
		return (*this);
	this->_signature = other._signature;
	return (*this);
}

AForm::~AForm( void )
{
	std::cout << "AForm destructor is called" << std::endl;
}


const std::string	AForm::getName( void ) const
{
	return(_name);
}

bool	AForm::getSignature( void ) const
{
	return(_signature);
}

int	AForm::getSignGrade( void ) const
{
	return(_signGrade);
}

int	AForm::getExecGrade( void ) const
{
	return(_execGrade);
}

void	AForm::besigned( const Bureaucrat& other )
{
	if (other.getGrade() > this->getSignGrade())
		throw GradeTooLowException();
	_signature = 1;
}

void	AForm::execute( const Bureaucrat& executor ) const
{
	if (!this->_signature)
		throw FormNotSigned();
	if (this->_execGrade < executor.getGrade())
		throw ExecutionGradeTooHigh();
	this->action();
}


const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}

const char* AForm::ExecutionGradeTooHigh::what() const throw()
{
	return ("Execution Grade is too high!");
}

const char* AForm::FormNotSigned::what() const throw()
{
	return ("The Form is not signed to be executed.");
}

std::ostream& operator<<( std::ostream& os, const AForm& obj )
{
	os << "Form " << obj.getName() << " is ";
	if (!obj.getSignature())
		os << "not ";
	os << "signed.\nGrade required to sign:\t\t" << obj.getSignGrade()
		<< "\nGrade required to execute:\t" << obj.getExecGrade();
	return os;
}