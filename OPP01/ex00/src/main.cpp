/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:52:00 by macarval          #+#    #+#             */
/*   Updated: 2024/09/19 19:18:30 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Worker.hpp"

int main(void)
{


	std::cout << BLUE << std::endl;
	std::cout << "---------------------------------------------------------\n";
	std::cout << GRAY;
	std::cout << "************************* TESTS *************************\n";
	std::cout << BLUE;
	std::cout << "---------------------------------------------------------\n";
	std::cout << CYAN;
	std::cout << "Instantiating objects" << std::endl;
	std::cout << BLUE;
	std::cout << "---------------------------------------------------------\n";

	{
		Position pos(10, 0, 0);
		Statistic stat(50, 20);
		Worker worker(pos, stat);

		std::cout << "\n***Infomations***" << worker << std::endl;
	}

	std::cout << BLUE << std::endl;
	std::cout << "---------------------------------------------------------\n";
	std::cout << CYAN;
	std::cout << "Instantiating objects" << std::endl;
	std::cout << BLUE;
	std::cout << "---------------------------------------------------------\n";

	{
		Worker worker(Position(25, 10, 50), Statistic(15, 45));

		std::cout << "\n***Infomations***" << worker << std::endl;
	}



	std::cout << BLUE << std::endl;
	std::cout << "---------------------------------------------------------\n";
	std::cout << CYAN;
	std::cout << "Text\n";
	std::cout << BLUE;
	std::cout << "---------------------------------------------------------\n";


	std::cout << BLUE << std::endl;
	std::cout << "---------------------------------------------------------\n";
	std::cout << GRAY;
	std::cout << "---------------------- END OF TEST ----------------------\n";
	std::cout << BLUE;
	std::cout << "---------------------------------------------------------\n";
	std::cout << RESET << std::endl;


	return 0;
}
