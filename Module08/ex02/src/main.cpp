/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/28 14:09:31 by jde-baai      #+#    #+#                 */
/*   Updated: 2024/10/17 15:04:18 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MutantStack.hpp"
#include <iostream>
#include <list>

int main(void)
{
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << "17 is on top now: " << mstack.top() << std::endl;
		std::cout << "size: " << mstack.size() << std::endl;
		mstack.pop();
		std::cout << "17 popped, 5 on top:" << mstack.top() << std::endl;
		std::cout << "------------------------------" << std::endl;
		std::cout << "Pushing random numbers.3,5,737,0" << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		std::cout << "Showing that the iterator works:" << std::endl;
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;
		std::cout << "------------------------------" << std::endl;
		std::cout << "Printing and deleting a copy of mstack:" << std::endl;
		std::cout << "(Printing is reverse order from iterator)" << std::endl;
		MutantStack<int> mstack_copy = mstack;
		while (!mstack_copy.empty())
		{
			std::cout << mstack_copy.top() << " ";
			mstack_copy.pop();
		}
		std::cout << std::endl;
		std::cout << "Showing that assigning the stack to std::stack works:" << std::endl;
		std::stack<int> s(mstack);
		while (!s.empty())
		{
			std::cout << s.top() << " ";
			s.pop();
		}
		std::cout << std::endl;
	}
	std::cout << "------------------------------" << std::endl;
	{
		std::cout << "Same operations as earlier but then using std::list:" << std::endl;

		std::list<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);
		mstack.pop_back();
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		mstack.push_back(0);
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << " ";
			++it;
		}
		std::cout << std::endl;
	}
	return 0;
}