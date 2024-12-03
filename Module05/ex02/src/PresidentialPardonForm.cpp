/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidentialPardonForm.cpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/07 17:17:37 by jde-baai      #+#    #+#                 */
/*   Updated: 2024/08/14 14:10:01 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PresidentialPardonForm.hpp"
#include "../inc/Bureaucrat.hpp"

PresidentialPardonForm ::PresidentialPardonForm(void) : AForm("Presidential Pardon form", 25, 5), _target("undefined")
{
	std::cout << "Presidential void constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(src), _target(src._target)
{
	std::cout << "Presidential copy constructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
	std::cout << "Presidential copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		this->_target = rhs._target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "Presidential destructor called" << std::endl;
}

// other constructors

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("Presidential Pardon form", 25, 5), _target(target)
{
	std::cout << "Presidential target constructor called" << std::endl;
}

// member functions

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	AForm::execute(executor);
	std::cout << _target << "\033[32m has been pardoned by Zaphod Beeblebrox\033[0m" << std::endl;
}