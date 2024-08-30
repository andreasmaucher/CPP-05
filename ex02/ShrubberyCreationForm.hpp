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

				ShrubberyCreationForm(std::string target);
				ShrubberyCreationForm(const ShrubberyCreationForm& copy);
				~ShrubberyCreationForm(void);

	private:
				std::string _target;

				ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
				ShrubberyCreationForm(void);
	
};

std::ostream &		operator<<(std::ostream & o, ShrubberyCreationForm const & i);

#endif