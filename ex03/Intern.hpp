#ifndef INTERN_HPP

# define INTERN_HPP

#include <iostream>
#include <string>
#include <fstream>

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

/*
what() function in exception classes should always be virtual.
This ensures that derived classes can override it to provide their 
own specific error messages.
*/
class Intern
{	
	public:
				// Exceptions
				class FormNotThere : public std::exception {
					public:
								virtual const char *what() const throw();
				};
				// public method
				AForm *makeForm(std::string formName, std::string target) const
				throw (FormNotThere);

				// Constructor
				Intern(void);
				// Destructor
				~Intern(void);
				
	private:
				// copying private and undefined = disabled
				// Copy constructor
				Intern(const Intern& copy);
				// Copy assignment operator
				Intern& operator=(const Intern& other);
				
};

#endif