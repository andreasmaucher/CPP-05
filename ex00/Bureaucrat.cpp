/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaucher <amaucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:22:27 by amaucher          #+#    #+#             */
/*   Updated: 2024/06/26 15:13:43 by amaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// any attemtp to instantiate a bureaucrat with an invalid grade will throw an exception
// 1 is the best grade and 150 the worst grade
void Bureaucrat::incrementGrade() throw(GradeTooHighException) {
		if ((_grade - 1) < 1)
			throw (GradeTooHighException());
		--_grade;
}

void Bureaucrat::decrementGrade() throw(GradeTooLowException) {
		if ((_grade + 1) > 150)
			throw (GradeTooLowException());
		++_grade;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
		return ("Exception: Grade can not be higher than 1");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
		return ("Exception: Grade can not be lower than 150");
}

// getter & setter
std::string Bureaucrat::getName() const {return (_name);}

int Bureaucrat::getGrade() const {return (_grade);}

// default constructor
Bureaucrat::Bureaucrat(void) {}

// constructor
Bureaucrat::Bureaucrat(std::string name, int grade) throw (std::exception) : _name(name), _grade(grade) {
			if (grade < 1)
				throw (GradeTooHighException());
			if (grade > 150)
				throw (GradeTooHighException());
}

// copy constructor
// initializes the member variables _name and _grade of the new object with the values from the src object
Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src._name), _grade(src._grade) {}

// destructor
Bureaucrat::~Bureaucrat(void) {}

// operator overload
// allows to print the details of a Bureaucrat object
// o -> output stream; i -> const reference to Bureaucrat object
std::ostream &operator<<(std::ostream &o, Bureaucrat const &i)
{
	o << i.getName() << " bureaucrat grade " << i.getGrade() << ".";
	return (o);
}