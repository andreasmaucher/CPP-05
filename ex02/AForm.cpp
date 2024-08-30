#include "AForm.hpp"
#include "Bureaucrat.hpp"

const char *AForm::GradeTooHighException::what() const throw() {
		return ("Form Exception: Grade can not be higher than 1");
}

const char *AForm::GradeTooLowException::what() const throw() {
		return ("Form Exception: Grade can not be lower than 150");
}

const char *AForm::NotSignedException::what() const throw() {
		return ("Form Exception: Form not signed");
}

// changes the form status to signed if the bureaucrat’s grade is high enough
// '&' after Bureaucrat: to pass the object by reference, meaning we pass
// the original object and not a copy; we want to change _isSigned
void	AForm::beSigned(Bureaucrat& bureaucrat) throw (GradeTooLowException) {
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
std::string AForm::getName() const {return (_name);}

bool AForm::getSignStatus() const {return (_isSigned);}

int AForm::getGradeSign() const{return (_gradeSign);}

int AForm::getGradeExec() const {return (_gradeExec);}

// parameterized constructor
// _isSigned "false",  indicating that the form is not signed when it is created
AForm::AForm(std::string _name, int _gradeSign, int _gradeExec) throw (std::exception)
	: _name(_name), _isSigned(false), _gradeSign(_gradeSign), _gradeExec(_gradeExec) {
		if (_gradeSign > 150 || _gradeExec > 150)
			throw (GradeTooLowException());
		if (_gradeSign < 1 || _gradeExec < 1)
			throw(GradeTooHighException());
	}

// copy constructor
// initializes the member variables of the new object with the values from the src object
AForm::AForm(const AForm& src) : _name(src._name), _isSigned(src._isSigned),
			_gradeSign(src._gradeSign), _gradeExec(src._gradeExec) {}

// destructor
AForm::~AForm(void) {}

// operator overload
// allows to print the details of a Form object
// o -> output stream; i -> const reference to Form object
std::ostream &operator<<(std::ostream &o, AForm const &i)
{
	o << i.getName() << " requires " << i.getGradeSign()
	<< "/" << i.getGradeExec() << " to sign or execute. Result: "
	<< ((i.getSignStatus()) ? "signed" : "not signed");
	return (o);
}

// execute function
void AForm::execute(Bureaucrat const & executor) const
		throw (GradeTooLowException, NotSignedException) {
			if (!this->getSignStatus())
				throw (NotSignedException());
			if (executor.getGrade() > this->getGradeExec())
				throw (GradeTooLowException());
			std::cout << executor.getName() << " executed " << this->getName() << std::endl;
			this->action();
		}