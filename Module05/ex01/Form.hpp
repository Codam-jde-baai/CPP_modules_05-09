/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/31 15:25:12 by jde-baai      #+#    #+#                 */
/*   Updated: 2024/08/01 17:17:00 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form
{
private:
	const std::string _name;
	const int _gradeToSign;
	const int _gradeToExecute;
	bool _signed;

public:
	// OCF
	Form(void);
	Form(const Form &src);
	Form &operator=(const Form &rhs);
	~Form(void);

	// other constructors
	Form(const std::string name, const int gradeToSign, const int gradeToExecute);

	// Getters
	std::string getName(void) const;
	int getGradeToSign(void) const;
	int getGradeToExecute(void) const;
	bool getSigned(void) const;

	void beSigned(Bureaucrat &bureaucrat);

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
};

// overload operator for printing
std::ostream &operator<<(std::ostream &os, const Form &rhs);

#endif /* FORM_HPP */