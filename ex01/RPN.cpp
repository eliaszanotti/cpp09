/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:34:13 by elias             #+#    #+#             */
/*   Updated: 2023/10/16 15:55:24 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>
#include "RPN.hpp"

// Print
void RPN::print(std::string const &str, int color) const
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
		std::cout << colorsString << "[RPN " << this->_input << "] " << reset;
	else
		std::cout << colorsString << "[RPN " << this->_input << "] " << reset << str << std::endl;
}

// Constructors
RPN::RPN()
{
	this->_input = "default";
	this->print("created", 2);
}

RPN::RPN(std::string const &input)
{
	this->_input = input;
	this->print("created with input", 2);
}

RPN::RPN(RPN const &copy)
{
	*this = copy;
	this->print("created by copy", 2);
}

RPN const	&RPN::operator=(RPN const &copy)
{
	this->_input = copy._input;
	this->print("created by assignment", 2);
	return (*this);
}

RPN::~RPN()
{
	this->print("deleted", 1);
}

// Methods
