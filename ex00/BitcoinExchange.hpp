/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:34:13 by elias             #+#    #+#             */
/*   Updated: 2023/09/28 16:02:53 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_CLASS_H
# define BITCOINEXCHANGE_CLASS_H

# include <iostream>
# include <sstream>
# include <fstream>
# include <string>
# include <map>
// # include <iomanip>
# include <cstdlib>

class BitcoinExchange
{
	private:
		std::map<std::string, double>	_dataMap;
		std::string						_filename;
		// Print
		void	print(std::string const &str, int color) const;
		// Methods
		std::string	stringTrim(std::string const &str);

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
		bool		checkDateFormat(std::string const &date);
};

#endif