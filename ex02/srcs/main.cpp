/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:09:53 by elias             #+#    #+#             */
/*   Updated: 2023/10/24 16:04:22 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "PmergeMe.tpp"
#include <vector>
#include <deque>

int main(int argc, char **argv)
{
	try
	{
		if (argc <= 2)
			throw (std::invalid_argument("./usage <int array>"));
		std::vector<int>	unsortedVector;
		std::deque<int>		unsortedDeque;
		PmergeMe<int>		sortVector("vector");
		(void)argv;
		// sortVector.parseArgs(argc, argv);
		// PmergeMe<std::deque<int> >	sortDeque;
	}
	catch(const std::exception& error)
	{
		std::cerr << "\e[31m[ERROR]\e[0m " << error.what() <<std::endl;
		return (1);
	}
	return (0);
}