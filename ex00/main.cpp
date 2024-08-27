/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaucher <amaucher@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 14:22:27 by amaucher          #+#    #+#             */
/*   Updated: 2024/08/27 22:55:49 by amaucher         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// exception objects are passed by reference as 'e'
int main(void)
{
	try {
			Bureaucrat andy ("andy", 150);
			std::cout << "andy created" << std::endl;
			andy.decrementGrade();
	}
	catch (std::exception & e) {
			std::cout << "test 1 - " << e.what() << std::endl;
	}
	try {
			Bureaucrat andy ("andy", 1);
			std::cout << "andy created" << std::endl;
			andy.incrementGrade();
			std::cout << andy.getGrade() << std::endl;
			std::cout << andy.getName() << std::endl;
	}
	catch (std::exception & e) {
			std::cout << "test 2 - " << e.what() << std::endl;
	}
	try {
			Bureaucrat andy ("andy", 42);
			std::cout << "andy created" << std::endl;
			andy.incrementGrade();
			std::cout << andy.getGrade() << std::endl;
			std::cout << andy.getName() << std::endl;
	}
	catch (std::exception & e) {
			std::cout << "test 3 - " << e.what() << std::endl;
	}
	try {
			Bureaucrat andy ("andy", 420);
			std::cout << "andy created" << std::endl;
	}
	catch (std::exception & e) {
			std::cout << "andy not created" << std::endl;
			std::cout << "test 4 - " << e.what() << std::endl;
	}
	return (0);
}

