#include "Intern.hpp"

// Constructor
Intern::Intern(void) {}

// Destructor
Intern::~Intern(void) {}

// exception
const char *Intern::FormNotThere::what() const throw() 
{
	return ("Exception called: Form does not match.");
}

// public method
AForm *Intern::makeForm(std::string formName, std::string target) const
		throw (FormNotThere) 
		{
			AForm *form;
			std::string availableForms[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
			int i = 0;
			while (i < 3 && formName != availableForms[i]) 
			{
				i++;
				std::cout << "round " << i << std::endl;
			}
			switch(i) 
			{
				case 0:
						form = new ShrubberyCreationForm(target);
						std::cout << "case 0" << std::endl;
						break;
				case 1:
						form = new RobotomyRequestForm(target);
						std::cout << "case 1" << std::endl;
						break;
				case 2:
						form = new PresidentialPardonForm(target);
						std::cout << "case 2" << std::endl;
						break;
				default:
						std::cout << "Intern can't find the form. Form not part of the known collection. " << std::endl;
						throw (FormNotThere());

			}
			std::cout << "Intern creates " << form->getName() << std::endl;
			return (form);
		}