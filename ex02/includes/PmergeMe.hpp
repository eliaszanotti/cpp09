/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:34:13 by elias             #+#    #+#             */
/*   Updated: 2023/10/24 15:53:36 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_CLASS_HPP
# define PMERGEME_CLASS_HPP

# include <iostream>
# include <string>
# include <cstring>
# include <vector>
# include <deque>

template <typename T>
class PmergeMe
{
	private:
		T	_unsorted;
		T	_sorted;
		// Print
		void	print(std::string const &str, int color) const;

	public:
		// Constructors
		PmergeMe();
		PmergeMe(std::string name);
		PmergeMe(PmergeMe const &copy);
		PmergeMe const	&operator=(PmergeMe const &copy);
		~PmergeMe();

		// Getters
		T const	&getUnsorted() const;
		T const	&getSorted() const;

		// Methods
		void	parseArgs(int argc, char **argv);
		void	mergeSort();
};

#endif