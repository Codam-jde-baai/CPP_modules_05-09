/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/14 16:37:11 by jde-baai      #+#    #+#                 */
/*   Updated: 2024/08/14 17:52:11 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>

class AForm;

class Intern
{
public:
	// OCF
	Intern(void);
	Intern(const Intern &src);
	Intern &operator=(const Intern &rhs);
	~Intern(void);

	// member functions
	AForm *makeForm(const std::string &name, const std::string &target);
};

#endif /* INTERN_HPP */