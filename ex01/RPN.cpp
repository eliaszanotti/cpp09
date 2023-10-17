/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:34:13 by elias             #+#    #+#             */
/*   Updated: 2023/10/17 11:48:18 by elias            ###   ########.fr       */
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

// Methods
bool RPN::_isOperator(char c)
{
	return (c == '+' || c == '-' || c == '/' || c == '*');
}

bool RPN::_isOverflow(double result)
{
	return (result > 2147483647 || result < -2147483648);
}

int	RPN::_calculate(char charOperator)
{
	if (this->_stack.size() < 2)
		throw (std::runtime_error("two operands are required"));
	double	result;
	double	operands[2];
	operands[0] = this->_stack.top();
	this->_stack.pop();
	operands[1] = this->_stack.top();
	this->_stack.pop();
	switch (charOperator)
	{
		case '*':
			result = operands[0] * operands[1];
			if (this->_isOverflow(result))
				throw (std::runtime_error("overflow !"));
			return (result);
		case '/':
			if (operands[1] == 0)
				throw (std::runtime_error("division by 0"));
			result = operands[0] / operands[1];
			if (this->_isOverflow(result))
				throw (std::runtime_error("overflow !"));
			return (result);
		case '+':
			result = operands[0] + operands[1];
			if (this->_isOverflow(result))
				throw (std::runtime_error("overflow !"));
			return (result);
		case '-':
			result = operands[0] - operands[1];
			if (this->_isOverflow(result))
				throw (std::runtime_error("overflow !"));
			return (result);
	}
	return (0);
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
void RPN::convertToStack(void)
{
	std::istringstream	iss(this->_input);
	std::string 		element;
	bool				lastIsOperator = false;
	try
	{
		while (getline(iss, element, ' '))
		{
			if (this->_isOperator(element[0]))
			{
				this->_stack.push(this->_calculate(element[0]));
				lastIsOperator = true;
			}
			else
			{
				if (this->_stack.size() == 2)
					throw (std::runtime_error("too much operands"));
				if (!isdigit(element[0]))
					throw (std::runtime_error("non numeric character"));
				if (element.size() > 1)
					throw (std::runtime_error("number sould be between 0 and 9"));
				this->_stack.push(std::strtol(element.c_str(), NULL, 10));
				lastIsOperator = false;
			}
		}
		if (!lastIsOperator)
			throw (std::runtime_error("last char is not an operator"));
		std::cout << this->_stack.top() << std::endl;
	}
	catch(const std::exception& error)
	{
		std::cerr << "\e[31m[ERROR]\e[0m " << error.what() << std::endl;
	}
}