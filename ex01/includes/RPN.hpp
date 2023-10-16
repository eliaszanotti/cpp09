/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:34:13 by elias             #+#    #+#             */
/*   Updated: 2023/10/16 15:54:05 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_CLASS_H
# define RPN_CLASS_H

# include <iostream>

class RPN
{
	private:
		std::string	_input;
		// Print
		void	print(std::string const &str, int color) const;

	public:
		// Constructors
		RPN();
		RPN(std::string const &input);
		RPN(RPN const &copy);
		RPN const	&operator=(RPN const &copy);
		~RPN();

		// Methods
};

#endif