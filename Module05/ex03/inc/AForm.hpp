/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AForm.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/01 17:20:02 by jde-baai      #+#    #+#                 */
/*   Updated: 2024/08/14 17:29:14 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>

class Bureaucrat;

class AForm
{
private:
	const std::string _name;
	const int _gradeToSign;
	const int _gradeToExecute;
	bool _signed;

public:
	// OCF
	AForm(void);
	AForm(const AForm &src);
	AForm &operator=(const AForm &rhs);
	virtual ~AForm(void);

	// other constructors
	explicit AForm(const std::string name, const int gradeToSign, const int gradeToExecute);

	// Getters
	std::string getName(void) const;
	int getGradeToSign(void) const;
	int getGradeToExecute(void) const;
	bool getSigned(void) const;

	// other functions
	void beSigned(Bureaucrat &bureaucrat);
	virtual void execute(Bureaucrat const &executor) const = 0;

	// exceptions
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	class FormNotSigned : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &os, const AForm &rhs);

#endif