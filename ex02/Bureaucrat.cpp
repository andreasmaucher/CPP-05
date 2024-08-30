/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaucher <amaucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:22:27 by amaucher          #+#    #+#             */
/*   Updated: 2024/08/30 16:28:33 by amaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// any attemtp to instantiate a bureaucrat with an invalid grade will 
// throw an exception; 1 is the best grade and 150 the worst grade
// throw("ex_name") will be caught by any catch func with that "ex_name"
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

// pointer function, because returns a pointer to string
// what: standard method to return the description of an exception
// throw: exception specification, means this func is not supposed to throw any exceptions
const char *Bureaucrat::GradeTooHighException::what() const throw() {
		return ("Exception: Grade can not be higher than 1");
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
		return ("Exception: Grade can not be lower than 150");
}

// getter & setter
std::string Bureaucrat::getName() const {return (_name);}

int Bureaucrat::getGrade() const {return (_grade);}

// default constructor: creates a Bureaucrat object without any arguments.
// usage: create Bureaucrat object and set properties later
Bureaucrat::Bureaucrat(void) {}

// parameterized constructor
// includes a check if grade is valid
Bureaucrat::Bureaucrat(std::string name, int grade) throw (std::exception) : _name(name), _grade(grade) {
			if (grade < 1)
				throw (GradeTooHighException());
			if (grade > 150)
				throw (GradeTooLowException());
}

// copy constructor
// initializes the member variables _name and _grade of the new object with the values from the src object
Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src._name), _grade(src._grade) {}

// copy assignment operator
Bureaucrat &Bureaucrat::operator=(Bureaucrat const &others)
{
	if (this != &others)
		{
			// no functionality, function can not be called since it's private
			// best practice would be to but copy assignment operator '= delete' in .hpp, but
			// not sure if allowed by the subject
		}
	return (*this);
}

// destructor
Bureaucrat::~Bureaucrat(void) {}

// operator overload
// allows to print the details of a Bureaucrat object
// o -> output stream; i -> const reference to Bureaucrat object
// o << ...: Appends the name and grade to the output stream o in a formatted way
std::ostream &operator<<(std::ostream &o, Bureaucrat const &i)
{
	o << i.getName() << " bureaucrat grade " << i.getGrade() << ".";
	return (o);
}

// public method
void Bureaucrat::signForm(AForm& form) const {
	if (this->getGrade() <= form.getGradeSign()) {
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	else 
	{
		std::cout << this->getName() << " couldn't sign " << form.getName()
			<< " because he got fired before." << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form) const
	throw (GradeTooLowException, AForm::NotSignedException) {
	if (!form.getSignStatus())
		throw (AForm::NotSignedException());
	if (this->getGrade() >= form.getGradeExec()) {
		throw (GradeTooLowException());
	}
	form.execute(*this);
}
