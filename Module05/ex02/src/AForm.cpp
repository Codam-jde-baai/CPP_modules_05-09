/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AForm.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/01 17:53:58 by jde-baai      #+#    #+#                 */
/*   Updated: 2024/08/14 14:07:29 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/AForm.hpp"
#include "../inc/Bureaucrat.hpp"

// OCF
AForm::AForm(void) : _name("FormName"), _gradeToSign(1), _gradeToExecute(1), _signed(false)
{
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const AForm &src) : _name(src._name), _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute), _signed(src._signed)
{
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &rhs)
{
	std::cout << "AForm copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		this->_signed = rhs._signed;
		// other member variables are constant and unassignable
	}
	return (*this);
}

AForm::~AForm(void)
{
	std::cout << "AForm destructor called" << std::endl;
}

/* other constructors */

AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _signed(false)
{
	std::cout << "AForm constructor called" << std::endl;
}

// getters

std::string AForm::getName(void) const
{
	return (this->_name);
}

int AForm::getGradeToSign(void) const
{
	return (this->_gradeToSign);
}

int AForm::getGradeToExecute(void) const
{
	return (this->_gradeToExecute);
}

bool AForm::getSigned(void) const
{
	return (this->_signed);
}

// besigned

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= this->_gradeToSign)
	{
		this->_signed = true;
		std::cout << bureaucrat.getName() << " signed " << this->_name << std::endl;
	}
	else
		throw AForm::GradeTooLowException();
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (this->getSigned() == false)
	{
		throw AForm::FormNotSigned();
	}
	if (executor.getGrade() > this->getGradeToExecute())
	{
		throw AForm::GradeTooLowException();
	}
}

// exceptions

const char *
AForm::GradeTooHighException::what(void) const throw()
{
	return ("\033mTHROW: Grade too high\033[0m");
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return ("\033mTHROW: Grade too low\033[0m");
}

const char *AForm::FormNotSigned::what(void) const throw()
{
	return ("\033mTHROW: Form could not be executed cause it had not been signed\033[0m");
}

// overloading operator

std::ostream &operator<<(std::ostream &os, const AForm &rhs)
{
	os << "\033[34mForm info\n\033[0m"
	   << "Name: " << rhs.getName() << "\n"
	   << "Grade to sign: " << rhs.getGradeToSign() << "\n"
	   << "Grade to execute: " << rhs.getGradeToExecute() << "\n"
	   << "Signed: " << (rhs.getSigned() ? "yes" : "no");
	return (os);
}