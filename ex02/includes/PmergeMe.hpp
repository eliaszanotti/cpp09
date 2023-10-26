/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:34:13 by elias             #+#    #+#             */
/*   Updated: 2023/10/26 12:14:58 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_CLASS_HPP
# define PMERGEME_CLASS_HPP

# include <iostream>
# include <string>
# include <cstring>
# include <vector>
# include <deque>
# include <stdlib.h>
# include <typeinfo>
# include <sys/time.h>

# define K 5

template <typename T>
class PmergeMe
{
	private:
		T	_unsorted;
		T	_sorted;
		// Print
		void	print(std::string const &str, int color) const;
		// Methods
		std::string	_getTypeName(std::string typeName) const;
		void		_sortRecursive(int begin, int end);

	public:
		// Constructors
		PmergeMe();
		PmergeMe(std::string name);
		PmergeMe(PmergeMe const &copy);
		PmergeMe const	&operator=(PmergeMe const &copy);
		~PmergeMe();

		// Getters
		T const	&getUnsorted(void) const;
		T const	&getSorted(void) const;

		// Methods
		void	parseArgs(int argc, char **argv);
		void	sort(void);
		void	mergeSort(void);
};

#endif