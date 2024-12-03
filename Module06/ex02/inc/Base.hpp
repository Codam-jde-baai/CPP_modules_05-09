/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Base.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/28 11:53:50 by jde-baai      #+#    #+#                 */
/*   Updated: 2024/08/28 11:59:33 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

class Base
{
private:
public:
	virtual ~Base() {
	};
};

// classes
class A : public Base
{
};

class B : public Base
{
};

class C : public Base
{
};

// general functions
Base *generate(void);
void identify(Base *p);
void identify(Base &p);