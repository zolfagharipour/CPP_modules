/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:28:55 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/07/15 11:42:20 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
	const std::string   _name;
	int                 _grade;
	
	void    _checkGrade( int grade );
public:
	Bureaucrat( void );
	Bureaucrat( std::string name, int grade );
	Bureaucrat( const Bureaucrat& other );
	Bureaucrat& operator=( const Bureaucrat& other );
	~Bureaucrat( void );

	std::string		getName( void ) const;
	int				getGrade( void ) const;
	void			incrementGrade( void );
	void			decrementGrade( void );
	void			signForm( AForm& form );
	void			executeForm( AForm const & form );
	
	class GradeTooHighException : public std::exception {
		public:
			const char* what() const throw();
	};
	class GradeTooLowException : public std::exception {
		public:
			const char* what() const throw();
	};
};


std::ostream& operator<<( std::ostream& os, const Bureaucrat& obj );


#endif