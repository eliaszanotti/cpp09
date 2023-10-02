/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:34:13 by elias             #+#    #+#             */
/*   Updated: 2023/10/02 16:10:31 by elias            ###   ########.fr       */
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

// Private Methods
std::string BitcoinExchange::stringTrim(std::string const &str)
{
	size_t start = str.find_first_not_of(" \t");
	size_t end = str.find_last_not_of(" \t");
	return (str.substr(start, end - start + 1));
}

void BitcoinExchange::checkCurrentLine(std::string &line, size_t lineCount)
{
	std::stringstream ss;
	ss << lineCount;
	if (line.empty())
		throw std::invalid_argument("\e[36m[" + ss.str() + "]\e[0m empty line");
	size_t	pos = line.find('|');
	if (pos == std::string::npos)
		throw std::invalid_argument("\e[36m[" + ss.str() + "]\e[0m wrong value (YYYY-MM-DD)");
	std::string	date = this->stringTrim(line.substr(0, pos));
	if (!this->checkDateFormat(date))
		throw std::invalid_argument("\e[36m[" + ss.str() + "]\e[0m bad input => " + date);
	std::string	value = this->stringTrim(line.substr(pos + 1, line.size() - pos));
	double		valueDouble = strtod(value.c_str(), NULL);
	if (valueDouble < 0)
		throw std::invalid_argument("\e[36m[" + ss.str() + "]\e[0m not a positive number => " + value);
	if (valueDouble == HUGE_VAL)
		throw std::invalid_argument("\e[36m[" + ss.str() + "]\e[0m overflow on value => " + value);
	this->searchDate(date, valueDouble);
}

bool BitcoinExchange::checkDateFormat(std::string date)
{
	if (date.length() != 10)
		return (false);
	int		datesArray[3];
	size_t	pos = 0;
	size_t	i = 0;
	for (i = 0; i < 3; i++)
	{
		pos = date.find('-');
		if ((pos == 4 || pos == 7) && date[pos] != '-')
			return (false);
		datesArray[i] = strtol(date.substr(0, pos).c_str(), NULL, 10);
		date.erase(0, pos + 1);
	}
	if (i != 3 || !datesArray[0] || !datesArray[1] || !datesArray[2])
		return (false);
	if (datesArray[0] > 2022 || datesArray[0] < 2009)
		return (false);
	if (datesArray[1] < 1 || datesArray[1] > 12)
		return (false);
	if (datesArray[2] < 1 || datesArray[2] > 31)
		return (false);
	return (true);
}

void BitcoinExchange::searchDate(std::string &date, double value)
{
	std::map<std::string, double>::iterator	mapIterator;

	std::cout << date << " => " << std::flush;
	mapIterator = this->_dataMap.find(date);
	while (mapIterator == this->_dataMap.end())
	{
		date = this->decreaseDate(date);
		mapIterator = this->_dataMap.find(date);
	}
	std::cout << value << " = " << std::setprecision(7) << mapIterator->second * value << std::endl;
}

std::string BitcoinExchange::decreaseDate(std::string &date)
{
	std::stringstream stream[3];
	std::string	datesString[3];
	int			datesInt[3];
	datesInt[0]	= strtol(date.substr(0, 4).c_str(), NULL, 10);
	datesInt[1]	= strtol(date.substr(5, 2).c_str(), NULL, 10);
	datesInt[2]	= strtol(date.substr(8, 2).c_str(), NULL, 10);
	if (datesInt[2] > 1)
		datesInt[2]--;
	else if (datesInt[2] <= 1)
	{
		datesInt[2] = 31;
		if (datesInt[1] <= 1)
		{
			datesInt[0]--;
			datesInt[1] = 12;
		}
		else
			datesInt[1]--;
	}
	stream[0] << datesInt[0];
	stream[0] >> datesString[0];
	stream[1] << datesInt[1];
	stream[1] >> datesString[1];
	stream[2] << datesInt[2];
	stream[2] >> datesString[2];
	if (datesString[1].length() < 2)
		datesString[1] = "0" + datesString[1];
	if (datesString[2].length() < 2)
		datesString[2] = "0" + datesString[2];
	date =  datesString[0] + "-" + datesString[1] + "-" + datesString[2];
	return (date);
}

// Methods
void BitcoinExchange::openDataFile(std::string const &dataPath)
{
	std::ifstream	infile;
	infile.open(dataPath.c_str(), std::ios::in);
	if (infile.fail())
		throw std::invalid_argument("\e[31m[ERROR]\e[0m Failed to open => " + dataPath);
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
		throw std::invalid_argument("\e[31m[ERROR]\e[0m Failed to open => " + this->_filename);
	std::string	line;
	size_t		lineCount = 0;
	while (!infile.eof())
	{
		getline(infile, line);
		try
		{
			this->checkCurrentLine(line, lineCount++);
		}
		catch(const std::exception& error)
		{
			std::cerr << "\e[31m[ERROR]\e[0m " << error.what() << '\n';
		}
	}
}