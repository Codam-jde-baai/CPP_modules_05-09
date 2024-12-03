/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RPN.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/10/10 17:09:09 by jde-baai      #+#    #+#                 */
/*   Updated: 2024/10/15 13:27:30 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <sstream>

class RPN
{
private:
	std::stack<int> _stack;
	void rpn_operation(char op);
	RPN(RPN &src) = delete;
	RPN &operator=(const RPN &rhs) = delete;

public:
	RPN(void);
	~RPN();

	void clear_stack(void);
	int process_input(std::string expression);
};

#endif /* RPN_HPP */