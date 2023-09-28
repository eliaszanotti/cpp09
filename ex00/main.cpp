/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 13:49:26 by elias             #+#    #+#             */
/*   Updated: 2023/09/28 15:18:43 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "\e[31m[ERROR]\e[0m Usage: ./btc <filename>" << std::endl;
        return (1); 
    }
    BitcoinExchange bitcoin(argv[1]);
    bitcoin.openDataFile("data.csv");

    
    return (0);
}