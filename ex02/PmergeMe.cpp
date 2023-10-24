/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:34:13 by elias             #+#    #+#             */
/*   Updated: 2023/10/24 14:03:28 by elias            ###   ########.fr       */
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
		std::cout << colorsString << "[PmergeMe " << this->_name << "] " << reset;
	else
		std::cout << colorsString << "[PmergeMe " << this->_name << "] " << reset << str << std::endl;
}

// Constructors
template <typename T>
PmergeMe<T>::PmergeMe()
{
	this->print("created", 2);
}

template <typename T>
PmergeMe<T>::PmergeMe(T const &unsorted)
{
	this->_unsorted = unsorted;
	this->print("created", 2);
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

// Methods