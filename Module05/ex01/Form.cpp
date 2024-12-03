/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/31 15:25:09 by jde-baai      #+#    #+#                 */
/*   Updated: 2024/08/15 15:18:31 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

// OCF
Form::Form(void) : _name("FormName"), _gradeToSign(1), _gradeToExecute(1), _signed(false)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const Form &src) : _name(src._name), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute), _signed(src._signed)
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &rhs)
{
	std::cout << "Form copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_signed = rhs._signed;
		// other member variables are constant and unassignable
	}
	return (*this);
}

Form::~Form(void)
{
	std::cout << "Form destructor called" << std::endl;
}

/* other constructors */

Form::Form(const std::string name, const int gradeToSign, const int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _signed(false)
{
	std::cout << "Form constructor called" << std::endl;
	if (gradeToSign < 1 | gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (gradeToSign > 150 | gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

// getters

std::string Form::getName(void) const
{
	return (this->_name);
}

int Form::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

int Form::getGradeToExecute(void) const
{
	return (this->_gradeToExecute);
}

bool Form::getSigned(void) const
{
	return (this->_signed);
}

// besigned

void Form::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_gradeToSign)
	{
		this->_signed = true;
		std::cout << bureaucrat.getName() << " signed " << this->_name << std::endl;
	}
	else
		throw Form::GradeTooLowException();
}

// exceptions

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("THROW: Grade too high");
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("THROW: Grade too low");
}

// overloading operator

std::ostream &operator<<(std::ostream &os, const Form &rhs)
{
	os << "\033[34mForm info\n\033[0m"
	   << "Name: " << rhs.getName() << "\n"
	   << "Grade to sign: " << rhs.getGradeToSign() << "\n"
	   << "Grade to execute: " << rhs.getGradeToExecute() << "\n"
	   << "Signed: " << (rhs.getSigned() ? "yes" : "no");
	return (os);
}