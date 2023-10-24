/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:34:13 by elias             #+#    #+#             */
/*   Updated: 2023/10/24 13:56:21 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_CLASS_H
# define PMERGEME_CLASS_H

# include <iostream>
# include <string>
// # include <vector>
// # include <deque>

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
		PmergeMe(T const &unsorted);
		PmergeMe(PmergeMe const &copy);
		PmergeMe const	&operator=(PmergeMe const &copy);
		~PmergeMe();

		// Methods
		
};

#endif