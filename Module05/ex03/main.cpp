/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/02/29 15:38:17 by jde-baai      #+#    #+#                 */
/*   Updated: 2024/08/15 13:07:01 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "./inc/AForm.hpp"
#include "./inc/Bureaucrat.hpp"
#include "./inc/PresidentialPardonForm.hpp"
#include "./inc/RobotomyRequestForm.hpp"
#include "./inc/ShrubberyCreationForm.hpp"
#include "./inc/Intern.hpp"

/*options:
	switchTree["presidential pardon"] = 1;
	switchTree["robotomy request"] = 2;
	switchTree["shrubbery creation"] = 3;
*/

int main(void)
{
	{
		std::cout << "\033[33m-------------------\nFully functional piece\n-------------------\033[0m" << std::endl;
		Bureaucrat a("Supercrat", 1);
		Intern free_employee;
		AForm *pres_form = free_employee.makeForm("presidential pardon", "prisoner");
		if (!pres_form)
			return (0);
		AForm *robot_form = free_employee.makeForm("robotomy request", "fleshy weak human");
		if (!robot_form)
		{
			delete pres_form;
			return (0);
		}
		AForm *shrub_form = free_employee.makeForm("shrubbery creation", "filename");
		if (!shrub_form)
		{
			delete pres_form;
			delete robot_form;
			return (0);
		}

		pres_form->beSigned(a);
		robot_form->beSigned(a);
		shrub_form->beSigned(a);

		pres_form->execute(a);
		robot_form->execute(a);
		shrub_form->execute(a);
		delete pres_form;
		delete robot_form;
		delete shrub_form;
	}
	{
		std::cout << "\033[33m-------------------\nNon-existant form\n-------------------\033[0m" << std::endl;
		Intern free_employee;
		AForm *not_gonna_work = free_employee.makeForm("spelling error", "target");
		if (not_gonna_work == NULL)
			return (0);
		std::cout << not_gonna_work->getName();
	}
}
