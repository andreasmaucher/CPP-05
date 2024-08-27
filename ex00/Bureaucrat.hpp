/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaucher <amaucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:22:27 by amaucher          #+#    #+#             */
/*   Updated: 2024/06/26 15:49:28 by amaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP

# define BUREAUCRAT_HPP

#include <iostream>

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
		
		// Default constructor
		Bureaucrat(std::string name, int grade) throw (std::exception);
		// Copy constructor
		Bureaucrat(const Bureaucrat &other);
		// Destructor
		~Bureaucrat(void);

	private:
		std::string const	_name;
		unsigned int		_grade;

		// Copy assignment operator
		// in this case private because of _name
		Bureaucrat& operator=(const Bureaucrat &other);
		Bureaucrat(void);
};

std::ostream &		operator<<(std::ostream & o, Bureaucrat const & i);

#endif