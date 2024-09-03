/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaucher <amaucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:22:27 by amaucher          #+#    #+#             */
/*   Updated: 2024/09/03 18:57:09 by amaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

//! change the main

int main(void)
{
	Intern jonny;
	AForm	*sampleForm;
	try {
		sampleForm = jonny.makeForm("robotomy request", "1");
	}
	catch (std::exception& e) {
		std::cout << "form1: " << e.what() << std::endl;
	}
	delete sampleForm;
	std::cout << std::endl;
	
}

