/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaucher <amaucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:22:27 by amaucher          #+#    #+#             */
/*   Updated: 2024/08/28 17:51:50 by amaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP

# define BUREAUCRAT_HPP

// needed because overload operator "<<" is used
#include <iostream>

class Bureaucrat
{	
	public:
		// Exceptions
		// virtual ensures that the correct version of what() is called based
		// on the actual type of the exception (instead of default std::exception message)
		class GradeTooHighException : public std::exception {
			public:
					virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
					virtual const char *what() const throw();
		};

		// getters & setters (const as it will not modify the objects state)
		std::string getName() const;
		int getGrade() const;

		// Two member functions
		// increment / decrement (not const because they modify the object)
		void incrementGrade() throw(GradeTooHighException);
		void decrementGrade() throw(GradeTooLowException);
		
		// Default constructor
		Bureaucrat(std::string name, int grade) throw (std::exception);
		// Copy constructor
		Bureaucrat(const Bureaucrat &other);
		// Destructor
		~Bureaucrat(void);

	private:
		std::string const	_name; // constant name
		unsigned int		_grade; // grade that ranges from 1 to 150

		// Copy assignment operator < private & undefined > to prevent reassignment,
		// since _name is defined as 'const' and unchangeable; this way _name is immutable
		Bureaucrat& operator=(const Bureaucrat &other);
		Bureaucrat(void);
};

/*
Overload operators allow to use standard operators (+, -, <<, >>) with my own types
*/
std::ostream &		operator<<(std::ostream & o, Bureaucrat const & i);

#endif