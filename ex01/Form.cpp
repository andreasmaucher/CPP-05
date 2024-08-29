/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaucher <amaucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:22:27 by amaucher          #+#    #+#             */
/*   Updated: 2024/08/29 14:26:51 by amaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

const char *Form::GradeTooHighException::what() const throw() {
		return ("Form Exception: Grade can not be higher than 1");
}

const char *Form::GradeTooLowException::what() const throw() {
		return ("Form Exception: Grade can not be lower than 150");
}

// changes the form status to signed if the bureaucrat’s grade is high enough
// '&' after Bureaucrat: to pass the object by reference, meaning we pass
// the original object and not a copy; we want to change _isSigned
void	Form::beSigned(Bureaucrat& bureaucrat) throw (GradeTooLowException) {
	if (bureaucrat.getGrade() <= this->_gradeSign) 
	{
		this->_isSigned = true;
	}
	else 
	{
		throw (GradeTooLowException()); // makes no sense, but subject excplicitly wants this
	}
}

// getter & setter
std::string Form::getName() const {return (_name);}

bool Form::getSignStatus() const {return (_isSigned);}

int Form::getGradeSign() const{return (_gradeSign);}

int Form::getGradeExec() const {return (_gradeExec);}

// parameterized constructor
// _isSigned "false",  indicating that the form is not signed when it is created
Form::Form(std::string _name, int _gradeSign, int _gradeExec) throw (std::exception)
	: _name(_name), _isSigned(false), _gradeSign(_gradeSign), _gradeExec(_gradeExec) {
		if (_gradeSign > 150 || _gradeExec > 150)
			throw (GradeTooLowException());
		if (_gradeSign < 1 || _gradeExec < 1)
			throw(GradeTooHighException());
	}

// copy constructor
// initializes the member variables of the new object with the values from the src object
Form::Form(const Form& src) : _name(src._name), _isSigned(src._isSigned),
			_gradeSign(src._gradeSign), _gradeExec(src._gradeExec) {}

// destructor
Form::~Form(void) {}

// operator overload
// allows to print the details of a Form object
// o -> output stream; i -> const reference to Form object
std::ostream &operator<<(std::ostream &o, Form const &i)
{
	o << i.getName() << " requires " << i.getGradeSign()
	<< "/" << i.getGradeExec() << " to sign or execute. Result: "
	<< ((i.getSignStatus()) ? "signed" : "not signed");
	return (o);
}