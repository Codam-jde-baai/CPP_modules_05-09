/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/14 16:36:22 by jde-baai      #+#    #+#                 */
/*   Updated: 2024/08/15 13:06:34 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Intern.hpp"
#include "../inc/AForm.hpp"
#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/ShrubberyCreationForm.hpp"
#include <iostream>
#include <map>

// OCF
Intern::Intern(void)
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &src)
{
	std::cout << "Intern copy constructor called" << std::endl;
	*this = src;
}

Intern &Intern::operator=(const Intern &rhs)
{
	std::cout << "Intern copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		// nothing to assign
	}
	return (*this);
}

Intern::~Intern(void)
{
	std::cout << "Intern destructor called" << std::endl;
}

// member functoins

/**
 * @warning this function creates a NEW AForm instance, delete after use
 */
AForm *Intern::makeForm(const std::string &name, const std::string &target)
{
	std::string formNames[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	AForm *form = NULL;
	int i;

	for (i = 0; i < 3; i++)
	{
		if (name == formNames[i])
			break;
	}
	if (i == 3)
	{
		std::cerr << "\033[31mCouldn't find any form by that name\033[0m" << std::endl;
		return (form);
	}
	switch (i)
	{
	case 0:
		form = new PresidentialPardonForm(target);
		break;
	case 1:
		form = new RobotomyRequestForm(target);
		break;
	case 2:
		form = new ShrubberyCreationForm(target);
		break;
	}
	std::cout << "Intern creates " << name << std::endl;
	return (form);
}