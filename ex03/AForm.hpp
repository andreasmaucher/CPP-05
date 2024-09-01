/* 
Abstract class: Can not be instantiated directly and serves as a blueprint
for other clases. Designed to be inherited by other classes, and it typically
contains at least one pure virtual function.
*/

#ifndef AFORM_HPP

# define AFORM_HPP

#include <iostream>
#include <cstdlib> // for rand()
#include <ctime> // for time()

class Bureaucrat;

class AForm
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
		class NotSignedException : public std::exception {
			public:
					virtual const char *what() const throw();
		};

		// getters & setters
		std::string getName() const;
		bool		getSignStatus() const;
		int			getGradeSign() const;
		int			getGradeExec() const;
		
		// Constructor
		AForm(std::string _name, int _gradeSign, int _gradeExec) throw (std::exception);
		// Copy constructor
		AForm(const AForm &other);
		// Destructor
		virtual ~AForm(void);

		// public method
		void		beSigned(Bureaucrat& b) throw (GradeTooLowException);
		void		execute(Bureaucrat const & executor) const throw (GradeTooLowException, NotSignedException);
		virtual void action() const = 0;

	private:
		const std::string		_name;
		bool					_isSigned;
		const int				_gradeSign;
		const int				_gradeExec;

		// Copy assignment operator < private & undefined > to prevent reassignment,
		// since _name is defined as 'const' and unchangeable; this way _name is immutable
		AForm& operator=(const AForm &other);
};

std::ostream &		operator<<(std::ostream & o, AForm const & i);

#endif