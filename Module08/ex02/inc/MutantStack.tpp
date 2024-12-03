/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MutantStack.tpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/06 17:09:54 by jde-baai      #+#    #+#                 */
/*   Updated: 2024/10/17 14:57:29 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANT_STACK_TPP
#define MUTANT_STACK_TPP

#include "MutantStack.hpp"
#include <cstddef>
#include <stdexcept>

/* constructors */

// Construction with no parameter: Creates an empty MutantStack.
template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(void) : std::stack<T, Container>()
{
}

// Construction by copy and assignment operator. In both cases,
// modifying either the
//  original MutantStack or its copy after copying musn’t affect the other MutantStack.

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack &other) : std::stack<T, Container>(other)
{
}

template <typename T, typename Container>
MutantStack<T, Container> &MutantStack<T, Container>::operator=(const MutantStack<T, Container> &rhs)
{
	if (this != &rhs)
	{
		std::stack<T, Container>::operator=(rhs);
	}
	return *this;
}

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack()
{
}

// member functions:

/*
The functions associated with stack are:
empty() – Returns whether the stack is empty – Time Complexity : O(1)
size() – Returns the size of the stack – Time Complexity : O(1)
top() – Returns a reference to the top most element of the stack – Time Complexity : O(1)
push(g) – Adds the element ‘g’ at the top of the stack – Time Complexity : O(1)
pop() – Deletes the most recent entered element of the stack – Time Complexity : O(1)
*/

template <typename T, typename Container>
bool MutantStack<T, Container>::empty() const
{
	return this->c.empty();
}

template <typename T, typename Container>
std::size_t MutantStack<T, Container>::size() const
{
	return this->c.size();
}

template <typename T, typename Container>
T &MutantStack<T, Container>::top()
{
	return this->c.back();
}

template <typename T, typename Container>
void MutantStack<T, Container>::push(const T &g)
{
	this->c.push_back(g);
}

template <typename T, typename Container>
void MutantStack<T, Container>::pop()
{
	if (this->size() == 0)
		throw std::runtime_error("Cant pop an empty stack");
	this->c.pop_back();
}

#endif /* MUTANT_STACK_TPP */