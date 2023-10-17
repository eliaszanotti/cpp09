/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elias <elias@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 13:34:13 by elias             #+#    #+#             */
/*   Updated: 2023/10/17 11:35:56 by elias            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_CLASS_H
# define RPN_CLASS_H

# include <iostream>
# include <stack>
# include <sstream>
# include <stdlib.h>

class RPN
{
	private:
		std::string 		_input;
		std::stack<double>	_stack;
		// Print
		void	print(std::string const &str, int color) const;
		// Methods
		bool	_isOperator(char c);
		bool	_isOverflow(double result);
		int		_calculate(char charOperator);

	public:
		// Constructors
		RPN();
		RPN(std::string const &input);
		RPN(RPN const &copy);
		RPN const	&operator=(RPN const &copy);
		~RPN();

		// Methods
		void	convertToStack(void);
};

#endif