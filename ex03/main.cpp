/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaucher <amaucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:22:27 by amaucher          #+#    #+#             */
/*   Updated: 2024/09/05 17:34:49 by amaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

/*
After each deletion, you need to reset sampleForm to nullptr 
to prevent re-deleting an already deleted pointer.
*/

int main(void)
{
	Intern jonny;
	AForm	*sampleForm = NULL;
	try {
		sampleForm = jonny.makeForm("robotomy request", "Bender");
		std::cout << *sampleForm << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "form1: " << e.what() << std::endl;
	}
	delete sampleForm;
	sampleForm = NULL;
	std::cout << std::endl;
	try {
		sampleForm = jonny.makeForm("shrubbery creation", "Bender");
		std::cout << *sampleForm << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "form2: " << e.what() << std::endl;
	}
	delete sampleForm;
	sampleForm = NULL;
	std::cout << std::endl;
	try {
		sampleForm = jonny.makeForm("presidential pardon", "Bender");
		std::cout << *sampleForm << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "form3: " << e.what() << std::endl;
	}
	delete sampleForm;
	sampleForm = NULL;
	std::cout << std::endl;
	try {
		sampleForm = jonny.makeForm("president pardon", "Bender");
	}
	catch (std::exception& e) {
		std::cout << "form4: " << e.what() << std::endl;
	}
	if (sampleForm)
	{
		delete sampleForm;	
		sampleForm = NULL;
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

