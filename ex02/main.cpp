/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaucher <amaucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:22:27 by amaucher          #+#    #+#             */
/*   Updated: 2024/09/11 21:42:07 by amaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

/*
destructor of abstract base class needs to be virtual if a derived object
through a base class pointer is supposed to be deleted (relevant for *form)
*/

int main(void)
{
	// Form executed with public method function 
	AForm *mautForm = new ShrubberyCreationForm("Test random"); // change the name here for a new ascii file
	try {
		Bureaucrat scheuer("scheuer", 1);
		mautForm->beSigned(scheuer);
		scheuer.signForm(*mautForm);
		mautForm->execute(scheuer);
	}
	catch (std::exception& e) {
		std::cout << "mautForm:" << e.what() << std::endl;
	}
	delete mautForm;
	std::cout << std::endl;
	// Bureaucrat is executing the form
	mautForm = new ShrubberyCreationForm("test");
	try {
		Bureaucrat scheuer("scheuer", 1);
		mautForm->beSigned(scheuer);
		scheuer.signForm(*mautForm);
		scheuer.executeForm(*mautForm);
	}
	catch (std::exception& e) {
		std::cout << "mautForm:" << e.what() << std::endl;
	}
	delete mautForm;
	std::cout << std::endl;
	// RobotomyRequestForm executed (Required grades: sign 72, exec 45_)
	mautForm = new RobotomyRequestForm("test");
	try {
		Bureaucrat scheuer("scheuer", 1);
		mautForm->beSigned(scheuer); // Checks if scheuer's grade (1) <= 72
		scheuer.signForm(*mautForm); // Checks if scheuer's grade (1) <= 45
		mautForm->execute(scheuer);
	}
	catch (std::exception& e) {
		std::cout << "mautForm:" << e.what() << std::endl;
	}
	std::cout << std::endl;
	delete mautForm;
	// RobotomyRequestForm fail
	mautForm = new RobotomyRequestForm("test");
	try {
		Bureaucrat scheuer("scheuer", 72);
		mautForm->beSigned(scheuer); // Checks if scheuer's grade (72) <= 72
		scheuer.signForm(*mautForm); // this fails because 72 > 45
		mautForm->execute(scheuer);
	}
	catch (std::exception& e) {
		std::cout << "mautForm:" << e.what() << std::endl;
	}
	std::cout << std::endl;
	delete mautForm;
	// PresidentialPardonForm true (Required grades: sign 25, exec 5)
	mautForm = new PresidentialPardonForm("test");
	try {
		Bureaucrat scheuer("scheuer", 1);
		mautForm->beSigned(scheuer);
		scheuer.signForm(*mautForm);
		mautForm->execute(scheuer);
	}
	catch (std::exception& e) {
		std::cout << "mautForm:" << e.what() << std::endl;
	}
	std::cout << std::endl;
	delete mautForm;
	// PresidentialPardonForm false 
	mautForm = new PresidentialPardonForm("test");
	try {
		Bureaucrat scheuer("scheuer", 25);
		std::cout << scheuer << std::endl;
		std::cout << *mautForm << std::endl;
		mautForm->beSigned(scheuer);
		scheuer.signForm(*mautForm);
		std::cout << *mautForm << std::endl;
		mautForm->execute(scheuer); // can't be executed 25 > 5
	}
	catch (std::exception& e) {
		std::cout << "mautForm:" << e.what() << std::endl;
	}
	std::cout << std::endl;
	delete mautForm;

	// Required grades: sign 145, exec 137
	mautForm = new ShrubberyCreationForm("test");
	try {
		Bureaucrat scheuer("scheuer", 130);
		std::cout << scheuer << std::endl;
		std::cout << *mautForm << std::endl;  // this prints "Result: not signed" since it is called before signing
		mautForm->beSigned(scheuer); // changes the form's isSigned status to true
		std::cout << *mautForm << std::endl;  // call again, to show that the form is now signed
		scheuer.signForm(*mautForm); // doesnt't sign anything, only prints a message about the signing
		mautForm->execute(scheuer);
	}
	catch (std::exception& e) {
		std::cout << "mautForm:" << e.what() << std::endl;
	}
	delete mautForm;
	return 0;
}