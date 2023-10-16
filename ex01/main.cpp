/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:46:12 by elias             #+#    #+#             */
/*   Updated: 2023/10/16 16:05:50 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv) 
{
    if (argc != 2)
        return (std::cerr << "Usage: ./RPN <input>" << std::endl, 1);
    RPN rpn(argv[1]);
    rpn.convertToStack();
    return (0);
}