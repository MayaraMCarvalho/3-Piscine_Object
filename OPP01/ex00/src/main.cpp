/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:52:00 by macarval          #+#    #+#             */
/*   Updated: 2025/09/19 22:15:00 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Workshop.hpp"
#include "Worker.hpp"

int main(void)
{
	std::cout << BLUE << std::endl;
	std::cout << "---------------------------------------------------------\n";
	std::cout << GRAY;
	std::cout << "------------------------- TESTS -------------------------\n";
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
	std::cout << "Instance a Shovel and a Hammer...\n";
	std::cout << BLUE;
	std::cout << "---------------------------------------------------------\n";

	{
		Shovel shovel = Shovel();
		Hammer hammer = Hammer();

	std::cout << BLUE << std::endl;
	std::cout << "---------------------------------------------------------\n";
	std::cout << CYAN;
	std::cout << "Creating a worker pointer without instantiating Position\n";
	std::cout << "and Statistic...\n";
	std::cout << "Printing worker information...\n";
	std::cout << BLUE;
	std::cout << "---------------------------------------------------------\n";

		Worker *worker = new Worker(Position(25, 10, 50), Statistic(15, 45));
		std::cout << "\n***Infomations***" << *worker;

	std::cout << BLUE << std::endl;
	std::cout << "---------------------------------------------------------\n";
	std::cout << CYAN;
	std::cout << "Giving a shovel to a worker...\n";
	std::cout << "Print information of the worker holding the shovel...\n";
	std::cout << BLUE;
	std::cout << "---------------------------------------------------------\n";

		worker->giveTool(shovel);
		worker->giveTool(hammer);
		std::cout << "\nWork Information: " << *worker;
		std::cout << "\nTool user worker: " << *shovel.getWorker();

	std::cout << BLUE << std::endl;
	std::cout << "---------------------------------------------------------\n";
	std::cout << CYAN;
	std::cout << "Creating a second worker pointer without instantiating\n";
	std::cout << "Position and Statistic...\n";
	std::cout << "Printing worker information...\n";
	std::cout << BLUE;
	std::cout << "---------------------------------------------------------\n";

		Worker *worker2 = new Worker(Position(10, 10, 10), Statistic(10, 10));
		std::cout << "\n***Infomations***" << *worker2;

	std::cout << BLUE << std::endl;
	std::cout << "---------------------------------------------------------\n";
	std::cout << CYAN;
	std::cout << "Giving a shovel to a worker...\n";
	std::cout << "Print information of the worker holding the shovel...\n";
	std::cout << BLUE;
	std::cout << "---------------------------------------------------------\n";

		std::cout << RESET << std::endl;
		std::cout << "Initial tool user worker: " << *shovel.getWorker();

		worker2->giveTool(shovel);
		std::cout << "\nWork Information: " << *worker2;
		std::cout << "\nTool user worker: " << *shovel.getWorker();

	std::cout << BLUE << std::endl;
	std::cout << "---------------------------------------------------------\n";
	std::cout << CYAN;
	std::cout << "Deleting the worker but...\n";
	std::cout << BLUE;
	std::cout << "---------------------------------------------------------\n";

		delete worker2;

	std::cout << BLUE << std::endl;
	std::cout << "---------------------------------------------------------\n";
	std::cout << CYAN;
	std::cout << "returning the tool to the worker...\n";
	std::cout << BLUE;
	std::cout << "---------------------------------------------------------\n";

		worker->giveTool(shovel);

	std::cout << BLUE << std::endl;
	std::cout << "---------------------------------------------------------\n";
	std::cout << CYAN;
	std::cout << "Deleting the other worker but...\n";
	std::cout << BLUE;
	std::cout << "---------------------------------------------------------\n";

		delete worker;

	std::cout << BLUE << std::endl;
	std::cout << "---------------------------------------------------------\n";
	std::cout << CYAN;
	std::cout << "... the shovel still exists!\n";
	std::cout << BLUE;
	std::cout << "---------------------------------------------------------\n";

		shovel.use();
		hammer.use();
	}

	std::cout << BLUE << std::endl;
	std::cout << "---------------------------------------------------------\n";
	std::cout << CYAN;
	std::cout << "Trying to instantiate a Tool\n";
	std::cout << "Uncomment to test\n";
	std::cout << BLUE;
	std::cout << "---------------------------------------------------------\n";

	{
		// Tool tool = new Tool();
	}

	std::cout << BLUE << std::endl;
	std::cout << "---------------------------------------------------------\n";
	std::cout << CYAN;
	std::cout << "Created a workshop,\n";
	std::cout << "adding workers to the workshop and\n";
	std::cout << "showing the workshop.\n";
	std::cout << BLUE;
	std::cout << "---------------------------------------------------------\n";

	{
		Workshop workshop = Workshop();
		Worker worker1 = Worker(Position(42, 42, 42), Statistic(42, 42));
		Worker worker2 = Worker(Position(88, 88, 88), Statistic(88, 88));
		Worker worker3 = Worker(Position(1, 1, 1), Statistic(1, 1));

		workshop.registerWorker(&worker1);
		workshop.registerWorker(&worker3);
		workshop.registerWorker(&worker2);

		std::cout << "\n***Infomations***" << workshop
					<< "\n" << RESET << std::endl;
	}


	std::cout << BLUE << std::endl;
	std::cout << "---------------------------------------------------------\n";
	std::cout << GRAY;
	std::cout << "---------------------- END OF TEST ----------------------\n";
	std::cout << BLUE;
	std::cout << "---------------------------------------------------------\n";
	std::cout << RESET << std::endl;

	return 0;
}
