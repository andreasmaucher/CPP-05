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

				// Constructor
				RobotomyRequestForm(std::string target);
				// Copy Constructor
				RobotomyRequestForm(const RobotomyRequestForm& copy);
				// Destructor
				~RobotomyRequestForm(void);

	private:
				std::string _target;

				// Copy Assignment Operator						
				RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
				// Default Constructor
				RobotomyRequestForm(void);
};

std::ostream &		operator<<(std::ostream & o, RobotomyRequestForm const & i);

#endif