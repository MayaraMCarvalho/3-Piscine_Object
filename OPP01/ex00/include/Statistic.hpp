/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Statistic.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:51:42 by macarval          #+#    #+#             */
/*   Updated: 2024/09/19 19:39:14 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATISTIC_HPP
# define STATISTIC_HPP

# include <iostream>

# include "Colors.hpp"

struct Statistic
{
	int	level;
	int	exp;

	Statistic( void ) : level(-1), exp(-1)
	{
		std::cout << GREEN << "Statistic📊 default created!";
		std::cout << RESET << std::endl;
	}

	Statistic(int level, int exp) : level(level), exp(exp)
	{
		std::cout << GREEN << "Statistic📊 created!";
		std::cout << RESET << std::endl;
	}

	Statistic( Statistic const &copy ) : level(copy.level), exp(copy.exp)
	{
		std::cout << YELLOW << "Statistic📊 copied!" << RESET << std::endl;
	}

	Statistic& operator=( Statistic const &other )
	{
		if (this != &other)
		{
			this->level = other.level;
			this->exp = other.exp;
		}
		std::cout << BLUE << "Statistic📊 assigned!" << RESET << std::endl;
		return *this;
	}

	~Statistic( void )
	{
		std::cout << RED << "Statistic📊 destroyed!" << RESET  << std::endl;
	}

	friend std::ostream& operator<<(std::ostream& p_os, const Statistic& p_stat)
	{
		p_os << BLUE << "   Statistic:" << YELLOW << "\n   level - "
				<< p_stat.level << "\n   exp - "
				<< p_stat.exp << RESET << std::endl;

		return (p_os);
	}

};

#endif
