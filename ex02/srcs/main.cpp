/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 14:09:53 by elias             #+#    #+#             */
/*   Updated: 2023/10/26 13:19:08 by elias            ###   ########.fr       */
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

		PmergeMe<std::vector<int> >		sortVector;
		sortVector.parseArgs(argc, argv);
		sortVector.sort();

		PmergeMe<std::deque<int> >		sortVector2(argc, argv);
		// sortVector2.parseArgs(argc, argv);
		sortVector2.sort();

	}
	catch(const std::exception& error)
	{
		return (std::cerr << "\e[31m[ERROR]\e[0m " << error.what() <<std::endl, 1);
	}
	return (0);
}