/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Statistic.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:51:42 by macarval          #+#    #+#             */
/*   Updated: 2024/09/19 23:23:59 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATISTIC_HPP
# define STATISTIC_HPP

# include <iostream>

# include "Colors.hpp"

struct Statistic
{
	int	_level;
	int	_exp;

	Statistic( void ) : _level(-1), _exp(-1)
	{
		std::cout << GREEN << "Statistic📊 default created!";
		std::cout << RESET << std::endl;
	}

	Statistic(int level, int exp) : _level(level), _exp(exp)
	{
		std::cout << GREEN << "Statistic📊 created!";
		std::cout << RESET << std::endl;
	}

	~Statistic( void )
	{
		std::cout << RED << "Statistic📊 destroyed!" << RESET  << std::endl;
	}

	friend std::ostream& operator<<(std::ostream& p_os, const Statistic& p_stat)
	{
		p_os << BLUE << "   Statistic:" << YELLOW << "\n   level - "
				<< p_stat._level << "\n   exp - "
				<< p_stat._exp << RESET << std::endl;

		return (p_os);
	}

};

#endif
