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

				RobotomyRequestForm(std::string target);
				RobotomyRequestForm(const RobotomyRequestForm& copy);
				~RobotomyRequestForm(void);

	private:
				std::string _target;

				RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
				RobotomyRequestForm(void);
	
};

std::ostream &		operator<<(std::ostream & o, RobotomyRequestForm const & i);

#endif