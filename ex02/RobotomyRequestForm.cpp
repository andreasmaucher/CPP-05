#include "RobotomyRequestForm.hpp"

// Constructor
RobotomyRequestForm::RobotomyRequestForm(std::string target) : 
	AForm("PresidentialPardonForm", 72, 45), _target(target) {}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm(void) {}

// Copy Constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) :
	AForm(src), _target(src._target) {}

// Copy Assignment Operator
RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &others)
{
	if (this != &others)
	{
		this->_target = others._target;
	}
	return *this;
}

// Operator Overload
std::ostream &operator<<(std::ostream &o, RobotomyRequestForm const &i)
{
	o << i.getName();
	return o;
}

// public method
// randomly value generator (either 0 or 1)
void RobotomyRequestForm::action() const 
{
	std::srand(std::time(0)); // Seed the RNG with the current time
	int randomValue = std::rand() % 2; // Generate random number (0 or 1)

	std::cout << "drilling noises rrrrrrr...." << _target;
	if (randomValue == 0) 
		std::cout << " has been robotomized" << std::endl;
	else
		std::cout << " not robotomized" << std::endl;
	;
}