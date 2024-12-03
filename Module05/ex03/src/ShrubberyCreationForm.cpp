/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.cpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/14 15:02:59 by jde-baai      #+#    #+#                 */
/*   Updated: 2024/08/14 16:44:53 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ShrubberyCreationForm.hpp"
#include "../inc/Bureaucrat.hpp"
#include <fstream>
#include <iostream>

ShrubberyCreationForm ::ShrubberyCreationForm(void) : AForm("Shrubbery Creation form", 145, 137), _target("undefined")
{
	std::cout << "Shrubbery void constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src), _target(src._target)
{
	std::cout << "Shrubbery copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	std::cout << "Shrubbery copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		this->_target = rhs._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "Shrubbery destructor called" << std::endl;
}

// other constructors

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("Shrubbery Creation form", 145, 137), _target(target)
{
	std::cout << "Shrubbery target constructor called" << std::endl;
}

// exceptoins

const char *
ShrubberyCreationForm::FileOpenFailure::what(void) const throw()
{
	return ("\033mTHROW: Unable to open the file\033[0m");
}

// member functions

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	AForm::execute(executor);
	std::string filename;
	std::ofstream file;

	filename = _target + "_shrubbery";
	file.open(filename, std::ios::app);
	if (file.is_open())
	{
		file << "    *    \n   ***   \n  *****  \n ******* \n   | |   \n";
		file.close();
		std::cout << "\033[32mSuccesfully printed a tree to \033[0m" << _target << std::endl;
	}
	else
		throw ShrubberyCreationForm::FileOpenFailure();
}