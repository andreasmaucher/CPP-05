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

				PresidentialPardonForm(std::string target);
				PresidentialPardonForm(const PresidentialPardonForm& copy);
				~PresidentialPardonForm(void);

	private:
				std::string _target;

				PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
				PresidentialPardonForm(void);
	
};

std::ostream &		operator<<(std::ostream & o, PresidentialPardonForm const & i);

#endif

