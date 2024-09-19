/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Graph.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:51:55 by macarval          #+#    #+#             */
/*   Updated: 2024/09/19 19:01:07 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Graph.hpp"

// Constructor & Destructor ===================================================
Graph::Graph(Vector2 const &size) : size(size)
{
	std::cout << GREEN << "Graph created with size: " << YELLOW << "(" <<
				size.getX() << ", " << size.getY() << ")" << RESET << std::endl;
}

Graph::Graph( Graph const &copy ) { *this = copy; }

Graph::~Graph( void ) {}

// Operators ==================================================================
Graph& Graph::operator=( Graph const &other )
{
	if (this != &other)
	{
		this->size = other.size;
		this->list = other.list;
	}
	return *this;
}

// Setters ====================================================================
void Graph::addPoint(float x, float y)
{
	if (x > size.getX() || y > size.getY())
		std::cerr << RED << "Point outside the graph limits!"
					<< RESET << std::endl;
	else
	{
		list.push_back(Vector2(x, y));
		std::cout << GREEN << "Point added to graph: " << YELLOW << "("
					<< x << ", " << y << ")" << RESET << std::endl;
	}
}

// Methods ====================================================================
void Graph::printGraph( void )
{
	std::vector< std::vector<std::string> >
			graph(size.getY() + 1, std::vector<std::string>(size.getX() + 1, "⋆"));

	for (size_t i = 0; i < list.size(); ++i)
		graph[list[i].getY()][list[i].getX()] = "✘";

	for (size_t y = graph.size(); y-- > 0 ;)
	{
		std::cout << BYELLOW << y << " " << RESET;
		for (size_t x = 0; x < graph[y].size(); ++x)
			std::cout << PURPLE << graph[y][x] << " " << RESET;
		std::cout << std::endl;
	}
	std::cout << BYELLOW << " ";
	for (size_t x = 0; x < graph[0].size(); ++x)
		std::cout << " " << x;
	std::cout << RESET << std::endl;
}

// Bonus ======================================================================
void Graph::readFile(const char* filename)
{
	std::ifstream file(filename);
	if (!file.is_open())
	{
		std::cerr << RED << "Error opening file!" << RESET << std::endl;
		return;
	}

	float x, y;
	while (file >> x >> y)
		addPoint(x, y);

	file.close();
}
