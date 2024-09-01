/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaucher <amaucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:22:27 by amaucher          #+#    #+#             */
/*   Updated: 2024/08/30 16:24:44 by amaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP

# define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

class Bureaucrat
{	
	public:
		// Exceptions
		class GradeTooHighException : public std::exception {
			public:
					virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
					virtual const char *what() const throw();
		};

		// getters & setters
		std::string getName() const;
		int getGrade() const;

		// increment / decrement
		void incrementGrade() throw(GradeTooHighException);
		void decrementGrade() throw(GradeTooLowException);

		// public method
		void	signForm(AForm & form) const;
		void	executeForm(AForm const & form) const
				throw (GradeTooLowException, AForm::NotSignedException);
		
		// Default constructor
		Bureaucrat(std::string name, int grade) throw (std::exception);
		// Copy constructor
		Bureaucrat(const Bureaucrat &other);
		// Destructor
		~Bureaucrat(void);

	private:
		std::string const	_name;
		unsigned int		_grade;

		// Copy assignment operator < private & undefined > to prevent reassignment,
		// since _name is defined as 'const' and unchangeable; this way _name is immutable
		Bureaucrat& operator=(const Bureaucrat &other);
		Bureaucrat(void);
};

// overload operator, allows
// overloaded insertion operator (<<), which is used for output in C++
std::ostream &		operator<<(std::ostream & o, Bureaucrat const & i);

#endif