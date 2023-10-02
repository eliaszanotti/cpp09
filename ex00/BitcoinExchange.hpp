/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:34:13 by elias             #+#    #+#             */
/*   Updated: 2023/10/02 14:48:30 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_CLASS_H
# define BITCOINEXCHANGE_CLASS_H

# include <iostream>
# include <sstream>
# include <fstream>
# include <map>
# include <math.h>

class BitcoinExchange
{
	private:
		std::map<std::string, double>	_dataMap;
		std::string						_filename;
		// Print
		void	print(std::string const &str, int color) const;
		// Methods
		std::string	stringTrim(std::string const &str);
		void		checkCurrentLine(std::string &line, size_t lineCount);
		bool		checkDateFormat(std::string date);

	public:
		// Constructors
		BitcoinExchange();
		BitcoinExchange(std::string const &filename);
		BitcoinExchange(BitcoinExchange const &copy);
		BitcoinExchange const	&operator=(BitcoinExchange const &copy);
		~BitcoinExchange();

		// Methods
		void		openDataFile(std::string const &dataPath);
		void		parseInputFile(void);
};

#endif