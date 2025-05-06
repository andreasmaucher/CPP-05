#ifndef SHRUBBERYCREATIONFORM_HPP

# define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <string>
#include <fstream>

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{	
	public:
				// pure virtual function
				void action() const;
				// parameterized constructor
				ShrubberyCreationForm(std::string target);
				// copy constructor
				ShrubberyCreationForm(const ShrubberyCreationForm& copy);
				// destructor
				virtual ~ShrubberyCreationForm(void);

	private:
				std::string _target;

				// copy assignment operator
				ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
				// default constructor
				ShrubberyCreationForm(void);
	
};

std::ostream &		operator<<(std::ostream & o, ShrubberyCreationForm const & i);

#endif