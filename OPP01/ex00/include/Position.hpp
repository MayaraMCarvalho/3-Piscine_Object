/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Position.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:51:42 by macarval          #+#    #+#             */
/*   Updated: 2024/09/19 19:38:53 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POSITION_HPP
# define POSITION_HPP

# include <iostream>
# include "Colors.hpp"

struct Position
{
	int	x;
	int	y;
	int	z;

	Position( void ) : x(-1), y(-1), z(-1)
	{
		std::cout << GREEN << "Position🏘️  default created!";
		std::cout << RESET << std::endl;
	}

	Position(int x, int y, int z) : x(x), y(y), z(z)
	{
		std::cout << GREEN << "Position🏘️  created!" << RESET << std::endl;
	}

	Position( Position const &copy ) : x(copy.x), y(copy.y), z(copy.z)
	{
		std::cout << YELLOW << "Position🏘️  copied!" << RESET << std::endl;
	}

	Position& operator=( Position const &other )
	{
		if (this != &other)
		{
			this->x = other.x;
			this->y = other.y;
			this->z = other.z;
		}
		std::cout << BLUE << "Position🏘️  assigned!" << RESET << std::endl;
		return *this;
	}

	~Position( void )
	{
		std::cout << RED << "Position🏘️  destroyed!" << RESET  << std::endl;
	}

	friend std::ostream& operator<<(std::ostream& p_os, const Position& p_pos)
	{
		p_os << BLUE << "   Position:\n   " << YELLOW << p_pos.x << ", "
				<< p_pos.y << ", " << p_pos.z << RESET << std::endl;

		return (p_os);
	}
};

#endif
