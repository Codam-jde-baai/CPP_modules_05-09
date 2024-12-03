/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidentialPardonForm.hpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/07 16:58:17 by jde-baai      #+#    #+#                 */
/*   Updated: 2024/08/14 12:43:09 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "../inc/AForm.hpp"

class PresidentialPardonForm : public AForm
{
private:
	std::string _target;

public:
	// OCF
	PresidentialPardonForm(void);
	PresidentialPardonForm(const PresidentialPardonForm &src);
	PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);
	~PresidentialPardonForm();
	// OTHER CONSTRUCTORS
	PresidentialPardonForm(const std::string &target);
	// functions
	void execute(Bureaucrat const &executor) const override;
};

#endif /* PRESIDENTIALPARDONFORM_HPP */