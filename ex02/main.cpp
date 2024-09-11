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
	AForm *mautForm = new ShrubberyCreationForm("Test 1");
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
	// RobotomyRequestForm false
	mautForm = new RobotomyRequestForm("test");
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
	//! mautForm:Form Exception: Grade can not be lower than 150
	// RobotomyRequestForm true
	mautForm = new RobotomyRequestForm("test");
	try {
		Bureaucrat scheuer("scheuer", 72);
		mautForm->beSigned(scheuer);
		scheuer.signForm(*mautForm);
		mautForm->execute(scheuer);
	}
	catch (std::exception& e) {
		std::cout << "mautForm:" << e.what() << std::endl;
	}
	std::cout << std::endl;
	delete mautForm;
	// PresidentialPardonForm fail 
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
	//! mautForm:Form Exception: Grade can not be lower than 150
	// PresidentialPardonForm true
	mautForm = new PresidentialPardonForm("test");
	try {
		Bureaucrat scheuer("scheuer", 25);
		std::cout << scheuer << std::endl;
		std::cout << *mautForm << std::endl;
		mautForm->beSigned(scheuer);
		scheuer.signForm(*mautForm);
		std::cout << *mautForm << std::endl;
		mautForm->execute(scheuer);
	}
	catch (std::exception& e) {
		std::cout << "mautForm:" << e.what() << std::endl;
	}
	std::cout << std::endl;
	delete mautForm;

	mautForm = new ShrubberyCreationForm("test");
	try {
		Bureaucrat scheuer("scheuer", 144);
		std::cout << scheuer << std::endl;
		std::cout << *mautForm << std::endl;
		mautForm->beSigned(scheuer);
		scheuer.signForm(*mautForm);
		mautForm->execute(scheuer);
	}
	catch (std::exception& e) {
		std::cout << "mautForm:" << e.what() << std::endl;
	}
	delete mautForm;
	return 0;
}

