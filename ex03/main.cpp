/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaucher <amaucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:22:27 by amaucher          #+#    #+#             */
/*   Updated: 2024/09/01 20:13:05 by amaucher         ###   ########.fr       */
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

//! change the main

int main(void)
{
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
	mautForm = new ShrubberyCreationForm("test");
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

	mautForm = new PresidentialPardonForm("test");
	try {
		Bureaucrat scheuer("scheuer", 25);
		std::cout << scheuer << std::endl;
		std::cout << *mautForm << std::endl;
		mautForm->beSigned(scheuer);
		scheuer.signForm(*mautForm);
		mautForm->execute(scheuer);
	}
	catch (std::exception& e) {
		std::cout << "mautForm:" << e.what() << std::endl;
	}
	std::cout << std::endl;
	delete mautForm;

	mautForm = new ShrubberyCreationForm("test");
	try {
		Bureaucrat scheuer("scheuer", 146);
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

