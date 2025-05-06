#ifndef PRESIDENTIALPARDONFORM_HPP

# define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <string>
#include <fstream>

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{	
	public:
				void action() const;

				// Constructor
				PresidentialPardonForm(std::string target);
				// Copy Constructor
				PresidentialPardonForm(const PresidentialPardonForm& copy);
				// Destructor
				~PresidentialPardonForm(void);

	private:
				std::string _target;

				// Copy Assignment Operator					
				PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
				// Default Constructor
				PresidentialPardonForm(void);
};

std::ostream &		operator<<(std::ostream & o, PresidentialPardonForm const & i);

#endif

