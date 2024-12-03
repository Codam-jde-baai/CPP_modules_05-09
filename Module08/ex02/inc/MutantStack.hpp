/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   MutantStack.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/08/28 14:09:45 by jde-baai      #+#    #+#                 */
/*   Updated: 2024/09/04 12:19:18 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iterator>

template <typename T, typename Container = std::deque<T>>
class MutantStack : public std::stack<T, Container>
{
public:
	// OCF
	MutantStack(void);
	MutantStack(const MutantStack &other);
	~MutantStack();
	MutantStack &operator=(const MutantStack &other);
	// other constructors
	MutantStack(std::size_t n);

	// member functions:
	bool empty() const;
	std::size_t size() const;
	T &top();
	void push(const T &g);
	void pop();

	// Iterator typedefs
	typedef typename Container::iterator iterator;
	typedef typename Container::const_iterator const_iterator;

	// Iterator methods
	typename Container::iterator begin()
	{
		return this->c.begin();
	}

	typename Container::const_iterator begin() const
	{
		return this->c.begin();
	}

	typename Container::iterator end()
	{
		return this->c.end();
	}

	typename Container::const_iterator end() const
	{
		return this->c.end();
	}
};

#include "./MutantStack.tpp"
#endif /* MUTANTSTACK_HPP */