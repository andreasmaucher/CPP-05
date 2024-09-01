#include "ShrubberyCreationForm.hpp"

// Constructor
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : 
	AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

// Copy Constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) :
	AForm(src), _target(src._target) {}

// Copy Assignment Operator
ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &others)
{
	if (this != &others)
	{
		this->_target = others._target;
	}
	return *this;
}

// Operator Overload
std::ostream &operator<<(std::ostream &o, ShrubberyCreationForm const &i)
{
	o << i.getName();
	return o;
}

// Method to write ascii code
void ShrubberyCreationForm::action() const {
	std::ofstream outfile((this->_target + "_shrubbery").c_str());
	outfile << "         ccee88oo" << std::endl;
	outfile << "  C8O8O8Q8PoOb o8oo" << std::endl;
    outfile << " dOB69QO8PdUOpugoO9bD" << std::endl;
    outfile << "CgggbU8OU qOp qOdoUOdcb" << std::endl;
    outfile << "    6OuU  /p u gcoUodpP" << std::endl;
    outfile << "      \\\\//  /douUP" << std::endl;
    outfile << "        \\\\////" << std::endl;
    outfile << "         |||/\\" << std::endl;
    outfile << "         |||\\/" << std::endl;
    outfile << "         |||||" << std::endl;
    outfile << "   .....//||||\\...." << std::endl;
	outfile.close();
}