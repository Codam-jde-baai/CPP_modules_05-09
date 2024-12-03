/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.hpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/14 14:27:25 by jde-baai      #+#    #+#                 */
/*   Updated: 2024/08/14 14:28:54 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include "../inc/AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
	std::string _target;

public:
	// OCF
	RobotomyRequestForm(void);
	RobotomyRequestForm(const RobotomyRequestForm &src);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);
	~RobotomyRequestForm();
	// OTHER CONSTRUCTORS
	RobotomyRequestForm(const std::string &target);
	// functions
	void execute(Bureaucrat const &executor) const override;
};

#endif /* ROBOTOMYREQUESTFORM_HPP */