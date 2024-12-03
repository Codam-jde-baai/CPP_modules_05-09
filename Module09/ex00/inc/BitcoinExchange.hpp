/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   BitcoinExchange.hpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jde-baai <jde-baai@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/09/19 15:41:11 by jde-baai      #+#    #+#                 */
/*   Updated: 2024/10/08 17:48:54 by jde-baai      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

struct s_time
{
	int year;
	int month;
	int day;

	// Comparison operator for std::map
	bool operator<(const s_time &rhs) const
	{
		if (year != rhs.year)
			return year < rhs.year;
		if (month != rhs.month)
			return month < rhs.month;
		return day < rhs.day;
	}
};

class BitcoinExchange
{
private:
	std::map<s_time, float> _dataset;

public:
	BitcoinExchange(void);
	BitcoinExchange(BitcoinExchange &src);
	BitcoinExchange &operator=(const BitcoinExchange &rhs);
	~BitcoinExchange();

	float getRate(s_time date);
	void printDataset() const;
};

s_time split_date(std::string date);

#endif /* BITCOINEXCHANGE_HPP */