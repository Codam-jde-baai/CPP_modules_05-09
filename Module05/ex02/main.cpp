/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/29 15:38:17 by jde-baai      #+#    #+#                 */
/*   Updated: 2024/08/14 15:22:04 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "./inc/AForm.hpp"
#include "./inc/Bureaucrat.hpp"
#include "./inc/PresidentialPardonForm.hpp"
#include "./inc/RobotomyRequestForm.hpp"
#include "./inc/ShrubberyCreationForm.hpp"

int main(void)
{
	// signing form from Bureacrat class
	{
		std::cout << "\033[33m-------------------\nSigning form from Bureaucrat class\n-------------------\033[0m" << std::endl;
		PresidentialPardonForm pres_form("prisoner");
		Bureaucrat cant_sign("Basic_Bureaucrat", 60);
		Bureaucrat can_sign("High_level_Bureacrat", 3);

		try
		{
			std::cout << "\033[33m-------------------\033[0m" << std::endl;
			std::cout << pres_form << std::endl;
			std::cout << "\033[33m-------------------\033[0m" << std::endl;
			std::cout << cant_sign << std::endl;
			std::cout << "\033[33m-------------------\033[0m" << std::endl;
			std::cout << can_sign << std::endl;
			std::cout << "\033[33m-------------------\nWill throw when basic bureaucrat signs:\033[0m" << std::endl;
			can_sign.signForm(pres_form);
			cant_sign.signForm(pres_form);
		}
		catch (const std::exception &exception)
		{
			std::cerr << exception.what() << std::endl;
		}
	}
	// signing form from form class
	{
		std::cout << "\033[33m-------------------\nSigning form from Form class\n-------------------\033[0m" << std::endl;
		PresidentialPardonForm pres_form("prisoner");
		Bureaucrat cant_execute("Basic_Bureaucrat", 20); // increasing this number to above 25 means it wont be able to sign
		Bureaucrat can_execute("High_level_Bureacrat", 3);

		try
		{
			std::cout << "\033[33m-------------------\033[0m" << std::endl;
			std::cout << pres_form << std::endl;
			std::cout << "\033[33m-------------------\033[0m" << std::endl;
			std::cout << cant_execute << std::endl;
			std::cout << "\033[33m-------------------\033[0m" << std::endl;
			std::cout << can_execute << std::endl;
			std::cout << "\033[33m-------------------\nBoth bureaucrats can sign:\033[0m" << std::endl;
			pres_form.beSigned(cant_execute);
			pres_form.beSigned(can_execute);

			std::cout << "\033[33mExecuting form:\033[0m" << std::endl;
			pres_form.execute(can_execute);
			pres_form.execute(cant_execute);
		}
		catch (const std::exception &exception)
		{
			std::cerr << exception.what() << std::endl;
		}
	}
	{
		std::cout << "\033[33m-------------------\nRobot Form\n-------------------\033[0m" << std::endl;
		RobotomyRequestForm robot_form_a("to_be_upgraded_a"); // signing is 72, exec is 45
		RobotomyRequestForm robot_form_b("to_be_upgraded_b"); // signing is 72, exec is 45
		Bureaucrat cant_execute("Basic_Bureaucrat", 60);	  //
		Bureaucrat can_execute("High_level_Bureacrat", 40);
		try
		{
			robot_form_a.beSigned(can_execute);
			robot_form_b.beSigned(cant_execute);
			robot_form_a.execute(can_execute);
			robot_form_b.execute(cant_execute);
		}
		catch (const std::exception &exception)
		{
			std::cerr << exception.what() << std::endl;
		}
	}
	{
		std::cout << "\033[33m-------------------\nShrubbery Form\n-------------------\033[0m" << std::endl;
		ShrubberyCreationForm shrubbery_form("beautiful"); // signing is 72, exec is 45  //
		Bureaucrat can_execute("High_level_Bureacrat", 1);
		try
		{
			shrubbery_form.beSigned(can_execute);
			shrubbery_form.execute(can_execute);
			shrubbery_form.execute(can_execute);
			shrubbery_form.execute(can_execute);
			shrubbery_form.execute(can_execute);
		}
		catch (const std::exception &exception)
		{
			std::cerr << exception.what() << std::endl;
		}
	}
}
