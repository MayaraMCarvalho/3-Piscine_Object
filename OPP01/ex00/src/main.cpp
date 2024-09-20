/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:52:00 by macarval          #+#    #+#             */
/*   Updated: 2024/09/19 22:33:41 by macarval         ###   ########.fr       */
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
	std::cout << "Instance a Position..." << std::endl;
	std::cout << "Instance a Statistic..." << std::endl;
	std::cout << "Creating a worker using the created Position and\n";
	std::cout << "Statistic...\n";
	std::cout << "Printing worker information..." << std::endl;
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
	std::cout << "Instance a Shovel...\n";
	std::cout << BLUE;
	std::cout << "---------------------------------------------------------\n";

	{
		Shovel shovel = Shovel();

	std::cout << BLUE << std::endl;
	std::cout << "---------------------------------------------------------\n";
	std::cout << CYAN;
	std::cout << "Creating a worker pointer without instantiating Position\n";
	std::cout << "and Statistic...\n";
	std::cout << "Printing worker information...\n";
	std::cout << BLUE;
	std::cout << "---------------------------------------------------------\n";

		Worker *worker = new Worker(Position(25, 10, 50), Statistic(15, 45));
		std::cout << "\n***Infomations***" << *worker << std::endl;

	std::cout << BLUE << std::endl;
	std::cout << "---------------------------------------------------------\n";
	std::cout << CYAN;
	std::cout << "Giving a shovel to a worker...\n";
	std::cout << "Print information of the worker holding the shovel...\n";
	std::cout << BLUE;
	std::cout << "---------------------------------------------------------\n";

		worker->giveShovel(shovel);
		std::cout << *shovel.getWorker() << std::endl;

		shovel.use();//mudar método

		Worker *worker2 = new Worker(Position(0, 0, 0), Statistic(0, 0));
		worker2->giveShovel(shovel);
		std::cout << *shovel.getWorker() << std::endl;


	std::cout << BLUE << std::endl;
	std::cout << "---------------------------------------------------------\n";
	std::cout << CYAN;
	std::cout << "Deleting the worker but...\n";
	std::cout << BLUE;
	std::cout << "---------------------------------------------------------\n";

		delete worker;

	std::cout << BLUE << std::endl;
	std::cout << "---------------------------------------------------------\n";
	std::cout << CYAN;
	std::cout << "... the shovel still exists!\n";
	std::cout << BLUE;
	std::cout << "---------------------------------------------------------\n";

		shovel.use();//mudar método

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
