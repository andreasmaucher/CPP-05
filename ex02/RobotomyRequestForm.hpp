#ifndef ROBOTOMYREQUESTFORM_HPP

# define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <string>
#include <fstream>

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{	
	public:
				void action() const;

				// parameterized constructor
				RobotomyRequestForm(std::string target);
				// copy constructor
				RobotomyRequestForm(const RobotomyRequestForm& copy);
				// destructor
				~RobotomyRequestForm(void);

	private:
				std::string _target;

				// copy assignement operator
				RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
				// constructor
				RobotomyRequestForm(void);
	
};

std::ostream &		operator<<(std::ostream & o, RobotomyRequestForm const & i);

#endif