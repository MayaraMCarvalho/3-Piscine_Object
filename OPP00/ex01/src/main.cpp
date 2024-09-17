/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:52:00 by macarval          #+#    #+#             */
/*   Updated: 2024/09/17 19:40:48 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Graph.hpp"

int main( void )
{
	std::cout << BLUE << std::endl;
	std::cout << "---------------------------------------------------------\n";
	std::cout << GRAY;
	std::cout << "************************* TESTS *************************\n";
	std::cout << BLUE;
	std::cout << "---------------------------------------------------------\n";
	std::cout << CYAN;
	std::cout << "Instantiating the graph..." << std::endl;
	std::cout << BLUE;
	std::cout << "---------------------------------------------------------\n";

	Graph graph(Vector2(5.2f, 5.8f));

	std::cout << BLUE << std::endl;
	std::cout << "---------------------------------------------------------\n";
	std::cout << CYAN;
	std::cout << "Adding the graph points...\n";
	std::cout << BLUE;
	std::cout << "---------------------------------------------------------\n";

	graph.addPoint(0.0f, 0.0f);
	graph.addPoint(2.0f, 2.0f);
	graph.addPoint(4.0f, 2.0f);
	graph.addPoint(2.0f, 4.0f);

	std::cout << BLUE << std::endl;
	std::cout << "---------------------------------------------------------\n";
	std::cout << CYAN;
	std::cout << "Printing the graph...\n";
	std::cout << BLUE;
	std::cout << "---------------------------------------------------------\n";

	graph.printGraph();

	std::cout << BLUE << std::endl;
	std::cout << "---------------------------------------------------------\n";
	std::cout << GRAY;
	std::cout << "---------------------- END OF TEST ----------------------\n";
	std::cout << BLUE;
	std::cout << "---------------------------------------------------------\n";
	std::cout << RESET << std::endl;

	return 0;
}
