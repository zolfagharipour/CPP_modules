/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 10:27:20 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/07/15 11:39:19 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string	_name;
	const int			_signGrade;
	const int			_execGrade;
	bool				_signature;
	void				_checkGrade( int grade );	

public:
	AForm( void );
	AForm( std::string name, int signGrade, int execGrade );
	AForm( const AForm& other );
	AForm& operator=( const AForm& other );
	virtual ~AForm( void );

	const std::string	getName( void ) const;
	bool				getSignature( void ) const;
	int					getSignGrade( void ) const;
	int					getExecGrade( void ) const;
	void				besigned( const Bureaucrat& other );
	void				execute( const Bureaucrat& executor ) const;
	virtual void		action( void ) const = 0 ;
	
	class GradeTooHighException : public std::exception {
		public:
			const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
		public:
			const char* what() const throw();
	};
	class ExecutionGradeTooHigh : public std::exception {
		public:
			const char* what() const throw();
	};
	class FormNotSigned : public std::exception {
		public:
			const char* what() const throw();
	};
};


std::ostream& operator<<( std::ostream& os, const AForm& obj );


#endif