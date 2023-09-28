/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:34:13 by elias             #+#    #+#             */
/*   Updated: 2023/09/28 15:58:40 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// Print
void BitcoinExchange::print(std::string const &str, int color) const
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
		std::cout << colorsString << "[BitcoinExchange] " << reset;
	else
		std::cout << colorsString << "[BitcoinExchange] " << reset << str << std::endl;
}

// Constructors
BitcoinExchange::BitcoinExchange()
{
	this->_filename = "";
	this->print("created", 2);
}

BitcoinExchange::BitcoinExchange(std::string const &filename)
{
	this->_filename = filename;
	this->print("created", 2);
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &copy)
{
	*this = copy;
	this->print("created by copy", 2);
}

BitcoinExchange const	&BitcoinExchange::operator=(BitcoinExchange const &copy)
{
	this->_filename = copy._filename;
	this->print("created by assignment", 2);
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
	this->print("deleted", 1);
}

// Methods
void BitcoinExchange::openDataFile(std::string const &dataPath)
{
	std::ifstream	infile;
	infile.open(dataPath.c_str(), std::ios::in);
	if (infile.fail())
	{
		std::cout << "\e[31m[ERROR]\e[0m Failed to open: " << dataPath << std::endl;
		return ;
	}

	std::string	date;
	std::string	value;
	while (!infile.eof())
	{
		getline(infile, date, ',');
		getline(infile, value, '\n');
		this->_dataMap[date] = strtod(value.c_str(), NULL);
	}
	infile.close();
}

void BitcoinExchange::parseInputFile(void)
{
	std::ifstream	infile;
	infile.open(this->_filename.c_str(), std::ios::in);
	if (infile.fail())
	{
		std::cout << "\e[31m[ERROR]\e[0m Failed to open: " << this->_filename << std::endl;
		return ;
	}

	std::string	line;
	size_t		pos = 0;
	while (!infile.eof())
	{
		getline(infile, line);
		pos = line.find('|');
		line = line.substr(0, pos);
		line = this->stringTrim(line);
		if (!this->checkDateFormat(line))
			std::cout << "NUN" << std::endl;


	}



}

bool BitcoinExchange::checkDateFormat(std::string const &date)
{

	std::cout << date << std::endl;

	if (date.length() != 10)
	{
		std::cout << "ok" << std::endl;
		
		return (false);
	}
	
	// int		datesArray[3];
	size_t	pos = 0;
	for (size_t i = 0; i < 3; i++)
	{
		pos = date.find('-');
		if ((pos == 4 || pos == 7) && date[pos] != '-')
			return (false);
		// datesArray[i] = strtol(date.substr(0, pos).c_str());


	}

	return (true);
}

std::string BitcoinExchange::stringTrim(std::string const &str)
{
	size_t start = str.find_first_not_of(" \t");
	size_t end = str.find_last_not_of(" \t");
	return (str.substr(start, end - start + 1));
}
