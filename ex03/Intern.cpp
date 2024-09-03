#include "Intern.hpp"

// Constructor
Intern::Intern(void) {}

// Destructor
Intern::~Intern(void) {}

// public method
AForm *Intern::makeForm(std::string formName, std::string target) const
		throw (FormNotThere) {
			AForm *form;
			std::string availableForms[] = {"Shrubbery", "Robotomy", "Presidential"};
			int i = 0;
			while (i < 3 && formName != availableForms[i]) {
				i++;
			}
			switch(i) {
				case 0:
						form = new ShrubberyCreationForm(target);
				case 1:
						form = new RobotomyRequestForm(target);
				case 2:
						form = new PresidentialPardonForm(target);
						break;
				default:
						std::cout << "Intern can't find the form. Form not part of the known collection. " << std::endl;
						throw (FormNotThere());

			}
			std::cout << "Intern creates " << form->getName() << std::endl;
			return (form);
		}