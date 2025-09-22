/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:52:00 by macarval          #+#    #+#             */
/*   Updated: 2025/09/22 16:02:03 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Workshop.hpp"
#include "Worker.hpp"
# include "Shovel.hpp"
# include "Hammer.hpp"

int main(void)
{
	std::cout << BLUE << std::endl;
	std::cout << "---------------------------------------------------------\n";
	std::cout << GRAY;
	std::cout << "------------------------- TESTS -------------------------\n";
	std::cout << BLUE;
	std::cout << "---------------------------------------------------------\n";

	std::cout << CYAN;
	std::cout << "Instance a Position...\n";
	std::cout << "Instance a Statistic...\n";
	std::cout << "Creating a worker using the created Position and\n";
	std::cout << "Statistic...\n";
	std::cout << "Printing worker information...\n";
	std::cout << BLUE;
	std::cout << "---------------------------------------------------------\n";

	{
		Position pos(10, 0, 0);
		Statistic stat(50, 20);

		Worker worker(pos, stat);

		std::cout << "\n***Infomations***" << worker << std::endl;
	}

	std::cout << BLUE;
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
		std::cout << "***Infomations***" << *worker;

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
	std::cout << "Creating a second worker pointer without instantiating.\n";
	std::cout << "Position and Statistic...\n";
	std::cout << "Printing worker information...\n";
	std::cout << BLUE;
	std::cout << "---------------------------------------------------------\n";

		Worker *worker2 = new Worker(Position(10, 10, 10), Statistic(10, 10));
		std::cout << "***Infomations***" << *worker2;

	std::cout << BLUE << std::endl;
	std::cout << "---------------------------------------------------------\n";
	std::cout << CYAN;
	std::cout << "Giving a shovel to a worker...\n";
	std::cout << "Print information of the worker holding the shovel...\n";
	std::cout << BLUE;
	std::cout << "---------------------------------------------------------\n";

		std::cout << RESET;
		std::cout << "Initial tool user worker: " << *shovel.getWorker();
		std::cout << std::endl;

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

	std::cout << BLUE;
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

	std::cout << BLUE;
	std::cout << "---------------------------------------------------------\n";
	std::cout << CYAN;
	std::cout << "... the shovel still exists!\n";
	std::cout << BLUE;
	std::cout << "---------------------------------------------------------\n";

		shovel.use();
		hammer.use();
		std::cout << std::endl;
	}

	std::cout << BLUE << std::endl;
	std::cout << "---------------------------------------------------------\n";
	std::cout << CYAN;
	std::cout << "Trying to instantiate a Tool...\n";
	std::cout << "Uncomment to test\n";
	std::cout << BLUE;
	std::cout << "---------------------------------------------------------\n";

	{
		// Tool tool = new Tool();
	}

	std::cout << BLUE << std::endl;
	std::cout << "---------------------------------------------------------\n";
	std::cout << CYAN;
	std::cout << "Created a workshop, adding workers to the workshop...\n";
	std::cout << "Showing the workshop.\n";
	std::cout << BLUE;
	std::cout << "---------------------------------------------------------\n";

	{
		Workshop workshop = Workshop();
		Worker *worker1 = new Worker(Position(42, 42, 42), Statistic(42, 42));
		Worker *worker2 = new Worker(Position(88, 88, 88), Statistic(88, 88));
		Worker *worker3 = new Worker(Position(1, 1, 1), Statistic(1, 1));

		workshop.hireWorker(*worker1);
		workshop.hireWorker(*worker3);
		workshop.hireWorker(*worker2);

		std::cout << "\n***Infomations***" << workshop << RESET;

	std::cout << BLUE << std::endl;
	std::cout << "---------------------------------------------------------\n";
	std::cout << CYAN;
	std::cout << "Trying to add already registered worker...\n";
	std::cout << "Showing the workshop.\n";
	std::cout << BLUE;
	std::cout << "---------------------------------------------------------\n";

		workshop.hireWorker(*worker3);
		std::cout << "\n***Infomations***" << workshop << RESET;

	std::cout << BLUE << std::endl;
	std::cout << "---------------------------------------------------------\n";
	std::cout << CYAN;
	std::cout << "Firing a worker...\n";
	std::cout << "Showing the workshop.\n";
	std::cout << BLUE;
	std::cout << "---------------------------------------------------------\n";

		workshop.fireWorker(worker1);
		std::cout << "\n***Infomations***" << workshop << RESET;

	std::cout << BLUE << std::endl;
	std::cout << "---------------------------------------------------------\n";
	std::cout << CYAN;
	std::cout << "Created a new workshop, adding workers to the workshop...\n";
	std::cout << "Showing the workshop.\n";
	std::cout << BLUE;
	std::cout << "---------------------------------------------------------\n";

		Workshop office = Workshop();

		office.hireWorker(*worker2);
		office.hireWorker(*worker1);
		office.hireWorker(*worker3);

		std::cout << "\n***Infomations***" << office << RESET;

	std::cout << BLUE << std::endl;
	std::cout << "---------------------------------------------------------\n";
	std::cout << CYAN;
	std::cout << "Starting a workday\n";
	std::cout << BLUE;
	std::cout << "---------------------------------------------------------\n";

		Worker *worker4 = new Worker(Position(0, 0, 0), Statistic(0, 0));

		worker4->work();
		office.hireWorker(*worker4);
		worker4->work();

		std::cout << "\n***Infomations***" << office << RESET << std::endl;
		office.executeWorkDay();


	std::cout << BLUE << std::endl;
	std::cout << "---------------------------------------------------------\n";
	std::cout << CYAN;
	std::cout << "Deleting all workers\n";
	std::cout << BLUE;
	std::cout << "---------------------------------------------------------\n";

		delete worker1;
		delete worker2;
		delete worker3;
		delete worker4;
	}

	std::cout << BLUE;
	std::cout << "---------------------------------------------------------\n";
	std::cout << GRAY;
	std::cout << "---------------------- BONUS TESTS ----------------------\n";
	std::cout << BLUE;
	std::cout << "---------------------------------------------------------\n";
	std::cout << CYAN;
	std::cout << "Obtain tool from a worker\n";
	std::cout << BLUE;
	std::cout << "---------------------------------------------------------\n";

	{
		Worker *worker = new Worker(Position(25, 10, 50), Statistic(15, 45));
		Hammer hammer = Hammer();

		std::cout << std::endl;
		worker->giveTool(hammer);

		std::cout << std::endl;
		Hammer *hammer2 = worker->getTool<Hammer>();
		Shovel *shovel2 = worker->getTool<Shovel>();

		std::cout << std::endl;

		if (hammer2)
			hammer2->use();

		if (shovel2)
			shovel2->use();

		std::cout << BLUE << std::endl;
		std::cout << "---------------------------------------------------------\n";
		std::cout << CYAN;
		std::cout << "Hiring a expert\n";
		std::cout << BLUE;
		std::cout << "---------------------------------------------------------\n";

		Workshop contractor = Workshop();

		contractor.hireExpert<Shovel>(worker);
		contractor.hireExpert<Hammer>(worker);
		std::cout << std::endl;

		contractor.executeWorkDay();

		std::cout << std::endl;

		delete worker;
	}

	std::cout << BLUE;
	std::cout << "---------------------------------------------------------\n";
	std::cout << GRAY;
	std::cout << "---------------------- END OF TEST ----------------------\n";
	std::cout << BLUE;
	std::cout << "---------------------------------------------------------\n";
	std::cout << RESET << std::endl;

	return 0;
}
