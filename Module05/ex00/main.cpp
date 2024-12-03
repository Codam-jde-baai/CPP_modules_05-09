/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/29 15:38:17 by jde-baai      #+#    #+#                 */
/*   Updated: 2024/07/31 13:35:29 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	{
		std::cout << "---------------------\nTesting basic constructors Bureaucrat\n---------------------" << std::endl;
		try
		{
			Bureaucrat a("John", 1);
			Bureaucrat b("Jane", 150);
			std::cout << a << std::endl;
			std::cout << b << std::endl;
			Bureaucrat c("Failure", 151);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "---------------------\nTesting increment and decrement Bureaucrat\n---------------------" << std::endl;
		try
		{
			Bureaucrat a("John", 1);
			std::cout << a << std::endl;
			a.decrementGrade();
			std::cout << "Manual printing: " << a.getName() << ", grade is " << a.getGrade() << std::endl;
			a.incrementGrade();
			std::cout << a << std::endl;
			a.incrementGrade();
			std::cout << a << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}
