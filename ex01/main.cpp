/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaucher <amaucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:22:27 by amaucher          #+#    #+#             */
/*   Updated: 2024/08/29 14:27:58 by amaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	try {
			Form sheet("sheet", -1, 1); // -1 triggers exception
	}
	catch (std::exception& e) {
		std::cout << "Test1: " << e.what() << std::endl;
	}
	try {
			Form sheet("sheet ", 1, 151); // 151 triggers exception
	}
	catch (std::exception& e) {
		std::cout << "Test2: " << e.what() << std::endl;
	}
	// grade <= gradeSign for form to be signed
	try {
			Bureaucrat scheuer("Scheuer", 6); // (name, grade)
			Form maut("maut", 6, 4);
			scheuer.signForm(maut);
			maut.beSigned(scheuer);
			std::cout << maut << std::endl; // calling operator overload, to proof form got signed
			std::cout << "Test3: successfull" << std::endl;
	}
	catch (std::exception& e) {
		std::cout << "Test3: " << e.what() << std::endl;
	}
	// grade <= gradeSign for form to be signed
	try {
			Bureaucrat scheuer("Scheuer", 6); // (name, grade)
			Form maut("maut", 1, 4); // 1 triggers exception, needs to be >= 6
			std::cout << maut << std::endl; // calling operator overload, to proof form not signed
			scheuer.signForm(maut);
			maut.beSigned(scheuer);
	}
	catch (std::exception& e) {
		std::cout << "Test4: " << e.what() << std::endl;
	}
	return (0);
}

