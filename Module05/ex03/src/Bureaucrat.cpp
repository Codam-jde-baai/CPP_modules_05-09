/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/01 17:52:07 by jde-baai      #+#    #+#                 */
/*   Updated: 2024/08/15 13:16:52 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Bureaucrat.hpp"
#include "../inc/AForm.hpp"

// OCF
Bureaucrat::Bureaucrat(void) : _name("Default"), _grade(150)
{
	std::cout << "Bureaucrat void constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src.getName())
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	*this = src;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
	std::cout << "Bureaucrat assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_grade = rhs._grade;
	}
	return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

/** other constructors **/
Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	std::cout << "Bureaucrat constructor called" << std::endl;
	if (grade > 150)
		throw GradeTooLowException(name);
	else if (grade < 1)
		throw GradeTooHighException(name);
	_grade = grade;
}

// getters
std::string Bureaucrat::getName(void) const
{
	return (_name);
}

int Bureaucrat::getGrade(void) const
{
	return (_grade);
}

// increment decrement

void Bureaucrat::incrementGrade(void)
{
	if (_grade - 1 < 1)
		throw GradeTooHighException(getName());
	_grade--;
}

void Bureaucrat::decrementGrade(void)
{
	if (_grade + 1 > 150)
		throw GradeTooLowException(getName());
	_grade++;
}

// other members

void Bureaucrat::signForm(AForm &form)
{
	form.beSigned(*this);
}

void Bureaucrat::executeForm(AForm const &form)
{
	form.execute(*this);
}

// exceptions

Bureaucrat::GradeTooHighException::GradeTooHighException(std::string name) : _msg(name + ", grade is too high")
{
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return (_msg.c_str());
}

Bureaucrat::GradeTooLowException::GradeTooLowException(std::string name) : _msg(name + ", grade is too low")
{
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return (_msg.c_str());
}

// overloading
std::ostream &operator<<(std::ostream &os, const Bureaucrat &rhs)
{
	os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
	return (os);
}