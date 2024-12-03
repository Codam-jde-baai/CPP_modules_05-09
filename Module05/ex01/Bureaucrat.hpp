/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/07/25 16:49:51 by jde-baai      #+#    #+#                 */
/*   Updated: 2024/08/15 13:14:43 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Form;

class Bureaucrat
{
private:
	std::string const _name;
	int _grade;

public:
	// OCF
	Bureaucrat(void);
	Bureaucrat(const Bureaucrat &src);
	Bureaucrat &operator=(const Bureaucrat &rhs);
	~Bureaucrat();
	// other constructors
	Bureaucrat(std::string name, int grade);

	// getters
	std::string getName(void) const;
	int getGrade(void) const;

	// increment decrement
	void incrementGrade(void);
	void decrementGrade(void);

	void signForm(Form &form);

	// exceptoins
	class GradeTooHighException : public std::exception
	{
	private:
		std::string _msg;

	public:
		GradeTooHighException(std::string name);
		virtual const char *what() const throw();
	};
	class GradeTooLowException : public std::exception
	{
	private:
		std::string _msg;

	public:
		GradeTooLowException(std::string name);
		virtual const char *what() const throw();
	};
};

// overload operator for printing
std::ostream &operator<<(std::ostream &os, const Bureaucrat &rhs);

#endif /* BUREAUCRAT_HPP */