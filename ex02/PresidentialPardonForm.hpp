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

				// parameterized constructor
				PresidentialPardonForm(std::string target);
				// copy constructor
				PresidentialPardonForm(const PresidentialPardonForm& copy);
				// destructor
				~PresidentialPardonForm(void);

	private:
				std::string _target;

				// copy assignment operator
				PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
				// constructor
				PresidentialPardonForm(void);
	
};

std::ostream &		operator<<(std::ostream & o, PresidentialPardonForm const & i);

#endif

