/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/29 15:38:17 by jde-baai      #+#    #+#                 */
/*   Updated: 2024/08/01 16:49:45 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	{
		std::cout << "---------------------\n Testing \n---------------------" << std::endl;
		std::cout << "Basic Bureacrat will be able to sign the basic form" << std::endl;
		std::cout << "Basic Bureacrat will not be able to sign Manager form" << std::endl;
		std::cout << "---------------------\n Testing \n---------------------" << std::endl;
		std::cout << "\033[33mBasic Bureacrat signing both:(using Bureacrat sign function)\033[0m" << std::endl;

		Form form_a("Accesible_Form", 60, 60);
		Form form_b("Manager_Form", 1, 1);

		Bureaucrat bureaucrat_a("Basic_Bureaucrat", 60);
		try
		{
			std::cout << form_a << '\n'
					  << std::endl;
			std::cout << form_b << '\n'
					  << std::endl;
			bureaucrat_a.signForm(form_a);
			bureaucrat_a.signForm(form_b);
			std::cout << form_a << '\n'
					  << std::endl;
			std::cout << form_b << '\n'
					  << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "\033[33m\nManager Bureacrat signing both:(using bureacrat sign function\n\033[0m" << std::endl;
		Form form_a("Accesible_Form", 60, 60);
		Form form_b("Manager_Form", 1, 1);

		Bureaucrat bureaucrat_b("Manager_Bureaucrat", 1);
		try
		{
			std::cout << form_a << '\n'
					  << std::endl;
			std::cout << form_b << '\n'
					  << std::endl;
			bureaucrat_b.signForm(form_a);
			bureaucrat_b.signForm(form_b);
			std::cout << form_a << '\n'
					  << std::endl;
			std::cout << form_b << '\n'
					  << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "\033[33m\nSigning Form using Form member function\n(will throw when signing manager form)\n\033[0m" << std::endl;
		Form form_a("Accesible_Form", 60, 60);
		Form form_b("Manager_Form", 1, 1);

		Bureaucrat bureaucrat_a("Basic_Bureaucrat", 60);
		try
		{
			std::cout << form_a << '\n'
					  << std::endl;
			form_a.beSigned(bureaucrat_a);
			std::cout << form_a << '\n'
					  << std::endl;
			form_b.beSigned(bureaucrat_a);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}
