/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:55:20 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/08/05 15:17:11 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string	_name;
	const int			_signGrade;
	const int			_execGrade;
	bool				_signature;

	void	_checkGrade( int grade );	
public:
	Form( void );
	Form( std::string name, int signGrade, int execGrade );
	Form( const Form& other );
	Form& operator=( const Form& other );
	~Form( void );

	const std::string	getName( void ) const;
	bool				getSignature( void ) const;
	int					getSignGrade( void ) const;
	int					getExecGrade( void ) const;
	void				besigned( const Bureaucrat& other );
	
	class GradeTooHighException : public std::exception {
		public:
			const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
		public:
			const char* what() const throw();
	};
};


std::ostream& operator<<( std::ostream& os, const Form& obj );


#endif