/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:34:13 by elias             #+#    #+#             */
/*   Updated: 2023/10/24 16:18:28 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include "PmergeMe.hpp"

// Print
template <typename T>
void PmergeMe<T>::print(std::string const &str, int color) const
{
	std::string colorsString = "";
	std::string reset = "\e[0m";
	
	if (color > 0 && color <= 9)
	{
		std::ostringstream oss;
		oss << "\e[3" << color << "m";
		colorsString = oss.str();
	}
	if (str.empty())
		std::cout << colorsString << "[PmergeMe] " << reset;
	else
		std::cout << colorsString << "[PmergeMe] " << reset << str << std::endl;
}

// Constructors
template <typename T>
PmergeMe<T>::PmergeMe()
{
	this->print("created", 2);
}

template <typename T>
PmergeMe<T>::PmergeMe(std::string name)
{
	std::cout << name << std::endl;
}

template <typename T>
PmergeMe<T>::PmergeMe(PmergeMe const &copy)
{
	*this = copy;
	this->print("created by copy", 2);
}

template <typename T>
PmergeMe<T> const	&PmergeMe<T>::operator=(PmergeMe const &copy)
{
	copy._unsorted = this->_unsorted;
	this->print("created by assignment", 2);
	return (*this);
}

template <typename T>
PmergeMe<T>::~PmergeMe()
{
	this->print("deleted", 1);
}

template <typename T>
T const &PmergeMe<T>::getUnsorted() const
{
	return (this->_unsorted);
}

template <typename T>
T const &PmergeMe<T>::getSorted() const
{
	return (this->_sorted);
}

// Methods
template <typename T>
void PmergeMe<T>::parseArgs(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
	{
		for (size_t j = 0; j < std::strlen(argv[i]); j++)
		{
			if (!std::isdigit(argv[i][j]))
				throw (std::invalid_argument("Not a number"));
		}
		long	number = std::strtol(argv[i], NULL, 10);
		if (number > 2147483647)
			throw (std::invalid_argument("Overflow"));
		this->_unsorted.push_back(number);
	}
}

template <typename T>
void PmergeMe<T>::mergeSort()
{

	
}