/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:28:09 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/07/15 14:34:33 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


void    Bureaucrat::_checkGrade( int grade )
{
	if (grade > 150)
		throw GradeTooLowException();
	if (grade < 1)
		throw GradeTooHighException();
}

Bureaucrat::Bureaucrat() : _name("Max Weber"), _grade(1)
{
	std::cout << "Bureaucrat default constructor is called." << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	std::cout << "Bureaucrat constructor is called." << std::endl;
	_checkGrade(grade);
	_grade = grade;	
}

Bureaucrat::Bureaucrat( const Bureaucrat& other ) : _name(other._name)
{
	*this = other;
}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& other )
{
	if (this == &other)
		return (*this);
		
	this->_grade = other._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor is called." << std::endl;
}

std::string		Bureaucrat::getName( void ) const
{
	return (this->_name);
}

int		Bureaucrat::getGrade( void ) const
{
	return (this->_grade);
}

void	Bureaucrat::incrementGrade( void )
{
	_checkGrade(_grade - 1);
	_grade--;
}

void	Bureaucrat::decrementGrade( void )
{
	_checkGrade(_grade + 1);
	_grade++;
}


void	Bureaucrat::signForm( AForm& form )
{
	try{
		form.besigned(*this);	
		std::cout << _name << " sign " << form.getName() << std::endl;
	}
	catch( AForm::GradeTooLowException& e){
		std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm( AForm const & form )
{
	try{
		form.execute(*this);
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	catch(std::exception& e){
		std::cout << "Form could'nt be executed because " << e.what() << std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}



std::ostream& operator<<( std::ostream& os, const Bureaucrat& obj )
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
	return os;
}
