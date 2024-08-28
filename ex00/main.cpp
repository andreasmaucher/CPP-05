/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaucher <amaucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:22:27 by amaucher          #+#    #+#             */
/*   Updated: 2024/08/28 18:05:51 by amaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// exception objects are passed by reference as 'e'
// individual exception names make sense if each catch block handles exceptions differently 
int main(void)
{
	try {
			// code that could throw an exception
			Bureaucrat andy ("andy", 150);
			std::cout << "andy created" << std::endl;
			andy.decrementGrade(); // error: decrement to 151
	}
	catch (std::exception & e) {
			std::cout << "test 1 - " << e.what() << std::endl;
	}
	try {
			Bureaucrat andy ("andy", 1);
			std::cout << "andy created" << std::endl;
			andy.incrementGrade(); // control flow immediately jumps to the corresponding catch block
			std::cout << "Grade: " << andy.getGrade() << std::endl; // skipped in exception case
			std::cout << "Name: " << andy.getName() << std::endl; // skipped in exception case
	}
	catch (std::exception & e) {
			std::cout << "test 2 - " << e.what() << std::endl;
	}
	try {
			Bureaucrat andy ("andy", 42);
			std::cout << "andy created" << std::endl;
			andy.incrementGrade();
			std::cout << "Grade: " << andy.getGrade() << std::endl;
			std::cout << "Name: " << andy.getName() << std::endl;
	}
	catch (std::exception & e) {
			std::cout << "test 3 - " << e.what() << std::endl;
	}
	try {
			Bureaucrat andy ("andy", 420);
			std::cout << "andy created" << std::endl; // skipped, exception
	}
	catch (std::exception & e) {
			std::cout << "andy not created" << std::endl;
			std::cout << "test 4 - " << e.what() << std::endl;
	}
	return (0);
}

