/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaucher <amaucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:22:27 by amaucher          #+#    #+#             */
/*   Updated: 2024/08/29 14:20:12 by amaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP

# define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form
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
		bool		getSignStatus() const;
		int			getGradeSign() const;
		int			getGradeExec() const;
		
		// Constructor
		Form(std::string _name, int _gradeSign, int _gradeExec) throw (std::exception);
		// Copy constructor
		Form(const Form &other);
		// Destructor
		~Form(void);

		// public method
		void		beSigned(Bureaucrat& b) throw (GradeTooLowException);
		
	private:
		const std::string		_name;
		bool					_isSigned;
		const int				_gradeSign;
		const int				_gradeExec;

		// Copy assignment operator < private & undefined > to prevent reassignment,
		// since _name is defined as 'const' and unchangeable; this way _name is immutable
		Form& operator=(const Form &other);
};

std::ostream &		operator<<(std::ostream & o, Form const & i);

#endif