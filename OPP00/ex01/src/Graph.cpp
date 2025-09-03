/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Graph.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:51:55 by macarval          #+#    #+#             */
/*   Updated: 2025/09/03 15:45:50 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Graph.hpp"

// Constructor & Destructor ===================================================
Graph::Graph(Vector2 const &size) : _size(size)
{
	std::cout << GREEN << "Graph created with size: " << YELLOW << "(" <<
			_size.getX() << ", " << _size.getY() << ")" << RESET << std::endl;
}

Graph::Graph( Graph const &copy ) { *this = copy; }

Graph::~Graph( void ) {}

// Operators ==================================================================
Graph& Graph::operator=( Graph const &other )
{
	if (this != &other)
	{
		this->_size = other._size;
		this->_list = other._list;
	}
	return *this;
}

// Setters ====================================================================
void Graph::addPoint(float x, float y)
{
	if (x > _size.getX() || y > _size.getY())
	{
		std::cerr << RED << "Point outside the graph limits!"
					<< RESET << std::endl;
		return ;
	}

	_list.push_back(Vector2(x, y));
	std::cout << GREEN << "Point added to graph: " << YELLOW << "("
				<< x << ", " << y << ")" << RESET << std::endl;
}

// Methods ====================================================================
void Graph::printGraph( void )
{
	std::vector< std::vector<std::string> > graph = createGraph();

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

std::vector< std::vector<std::string> > Graph::createGraph( void )
{
	std::vector<std::string> lines(_size.getX() + 1, "⋆");
	std::vector< std::vector<std::string> > graph(_size.getY() + 1, lines );

	for (size_t i = 0; i < _list.size(); ++i)
		graph[_list[i].getY()][_list[i].getX()] = "✘";

	return graph;
}

// Bonus ======================================================================
void Graph::readFile( const char* filename )
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
