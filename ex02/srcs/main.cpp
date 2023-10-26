/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:09:53 by elias             #+#    #+#             */
/*   Updated: 2023/10/26 12:15:42 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "PmergeMe.tpp"

int main(int argc, char **argv)
{
	try
	{
		if (argc <= 1)
			throw (std::invalid_argument("./usage <int array>"));
		// std::vector<int>	unsortedVector;
		// std::deque<int>		unsortedDeque;

		PmergeMe<std::vector<int> >		sortVector;
		sortVector.parseArgs(argc, argv);
		sortVector.sort();

		PmergeMe<std::deque<int> >		sortVector2;
		sortVector2.parseArgs(argc, argv);
		sortVector2.sort();

        // std::vector<int> unsorted = sortVector.getUnsorted();

        // // Affichez les éléments de _unsorted
        // for (size_t i = 0; i < unsorted.size(); i++) {
        //     std::cout << "Element " << i << ": " << unsorted[i] << std::endl;
        // }


	}
	catch(const std::exception& error)
	{
		std::cerr << "\e[31m[ERROR]\e[0m " << error.what() <<std::endl;
		return (1);
	}
	return (0);
}