/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.cpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/14 14:27:345 by jde-baai      #+#    #+#                 */
/*   Updated: 2024/08/14 14:28:10 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RobotomyRequestForm.hpp"
#include "../inc/Bureaucrat.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm ::RobotomyRequestForm(void) : AForm("Robotomy request form", 72, 45), _target("undefined")
{
	std::cout << "Robotomy void constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src) : AForm(src), _target(src._target)
{
	std::cout << "Robotomy copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	std::cout << "Robotomy copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		this->_target = rhs._target;
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Robotomy destructor called" << std::endl;
}

// other constructors

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("Robotomy request form", 72, 45), _target(target)
{
	std::cout << "Robotomy target constructor called" << std::endl;
}

// member functions

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	AForm::execute(executor);
	std::cout << "\033[35m DRILLING NOISES\nDRRRRrrrrrr\nDRRRRrrrrrr\033[0m" << std::endl;
	srand(time(NULL));
	if ((rand() % 2) == 0)
		std::cout << _target << "\033[32m has been robotomised succesfully\033[0m" << std::endl;
	else
		std::cout << _target << "\033[31m Robotomy failure\033[0m" << std::endl;
}