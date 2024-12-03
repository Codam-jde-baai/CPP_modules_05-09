/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.hpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/14 15:01:29 by jde-baai      #+#    #+#                 */
/*   Updated: 2024/08/14 15:16:11 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include "../inc/AForm.hpp"

class ShrubberyCreationForm : public AForm
{
private:
	std::string _target;

public:
	// OCF
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(const ShrubberyCreationForm &src);
	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);
	~ShrubberyCreationForm();
	// OTHER CONSTRUCTORS
	ShrubberyCreationForm(const std::string &target);
	// functions
	void execute(Bureaucrat const &executor) const override;
	class FileOpenFailure : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

#endif /* SHRUBBERYCREATIONFORM_HPP */