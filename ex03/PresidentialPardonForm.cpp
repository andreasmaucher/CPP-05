#include "PresidentialPardonForm.hpp"

// Constructor
PresidentialPardonForm::PresidentialPardonForm(std::string target) : 
	AForm("PresidentialPardonForm", 25, 5), _target(target) {}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm(void) {}

// Copy Constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) :
	AForm(src), _target(src._target) {}

// Copy Assignment Operator
PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &others)
{
	if (this != &others)
	{
		//this->_target = others._target;
		// no functionality, function can not be called since it's private
		// best practice would be to but copy assignment operator '= delete' in .hpp, but
		// not allowed until C++11
	}
	return *this;
}

// Operator Overload
std::ostream &operator<<(std::ostream &o, PresidentialPardonForm const &i)
{
	o << i.getName();
	return o;
}

// public method
void PresidentialPardonForm::action() const {
	std::cout <<_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}