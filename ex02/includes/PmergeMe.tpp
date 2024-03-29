/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:34:13 by elias             #+#    #+#             */
/*   Updated: 2023/11/02 15:30:19 by elias            ###   ########.fr       */
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
PmergeMe<T>::PmergeMe(int argc, char **argv)
{
	this->parseArgs(argc, argv);
	this->print("created and parsed", 2);
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
T const &PmergeMe<T>::getUnsorted(void) const
{
	return (this->_unsorted);
}

template <typename T>
T const &PmergeMe<T>::getSorted(void) const
{
	return (this->_sorted);
}

// Private Methods
template <typename T>
void	PmergeMe<T>::_display(T container) const
{
	size_t	size = container.size();
	if (container.size() > 10)
		size = 10;
	for (size_t i = 0; i < size; i++)
		std::cout << "\e[36m[" << container[i] << "]\e[0m" << std::flush;
	if (size == 10)
		std::cout << "\e[36m...\e[0m" << std::flush;
	std::cout << std::endl;
}

template <typename T>
std::string	PmergeMe<T>::_getTypeName(std::string typeName) const
{
	if (typeName == "St6vectorIiSaIiEE")
        return ("std::vector<int>");
	if (typeName == "St5dequeIiSaIiEE")
		return ("std::deque<int>");
	return (typeName);
}

template <typename T>
void	PmergeMe<T>::_sortRecursive(int begin, int end)
{
	if (end - begin > K)
	{
		int middle = (begin + end) / 2;
		this->_sortRecursive(begin, middle);
		this->_sortRecursive(middle + 1, end);
		this->_mergeSort(begin, middle, end);
	}
	else
		this->_insertSort(begin, end);
}

template <typename T>
void PmergeMe<T>::_mergeSort(int begin, int middle, int end)
{
	int	n1 = middle - begin + 1;
	int	n2 = end - middle;
	int	rightIndex = 0;
	int	leftIndex = 0;
	T	left(this->_sorted.begin() + begin, this->_sorted.begin() + middle + 1);
	T	right(this->_sorted.begin() + middle + 1, this->_sorted.begin() + end + 1);

	for (int i = begin; i < end; i++)
	{
		if (rightIndex == n2)
		{
			this->_sorted[i] = left[leftIndex];
			leftIndex++;
		}
		else if (leftIndex == n1)
		{
			this->_sorted[i] = right[rightIndex];
			rightIndex++;
		}
		else if (right[rightIndex] > left[leftIndex])
		{
			this->_sorted[i] = left[leftIndex];
			leftIndex++;
		}
		else
		{
			this->_sorted[i] = right[rightIndex];
			rightIndex++;
		}
	}
}

template <typename T>
void	PmergeMe<T>::_insertSort(int begin, int end)
{
	for (int i = begin; i < end; i++)
	{
		int	tempValue = this->_sorted[i + 1];
		int	j = i + 1;
		while (j > begin && this->_sorted[j - 1] > tempValue)
		{
			this->_unsorted[j] = this->_unsorted[j - 1]; 
			j--;
		}
		this->_sorted[j] = tempValue;
	}
}

// Public Methods
template <typename T>
void	PmergeMe<T>::parseArgs(int argc, char **argv)
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
	this->_sorted = this->_unsorted;
}

template <typename T>
void PmergeMe<T>::sort(void)
{
	clock_t	start, finish;
	double	timeDiff;

	std::cout << "\e[33m[Unsorted Array] = \e[0m" << std::flush;
	this->_display(this->_unsorted);

	start = clock();
	this->_sortRecursive(0, this->_unsorted.size() - 1);
	finish = clock();
	timeDiff = ((double) (finish - start)) / CLOCKS_PER_SEC;
	std::cout << "\e[32m[Time to process a range of " \
		<< this->_unsorted.size() << " elements with a " \
		<< this->_getTypeName(typeid(this->_unsorted).name()) << " is " \
		<< std::fixed << timeDiff << "s]" << std::endl;

	std::cout << "\e[33m[Sorted Array]   = \e[0m" << std::flush;
	this->_display(this->_sorted);
	std::cout << std::endl;
}