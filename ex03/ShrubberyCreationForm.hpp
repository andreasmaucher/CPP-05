#ifndef SHRUBBERYCREATIONFORM_HPP

# define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <string>
#include <fstream>

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{	
	public:
				void action() const;

				// Constructor
				ShrubberyCreationForm(std::string target);
				// Copy Constructor
				ShrubberyCreationForm(const ShrubberyCreationForm& copy);
				// Destructor
				~ShrubberyCreationForm(void);

	private:
				std::string _target;

				// Copy Assignment Operator					
				ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
				// Default Constructor
				ShrubberyCreationForm(void);
};

std::ostream &		operator<<(std::ostream & o, ShrubberyCreationForm const & i);

#endif