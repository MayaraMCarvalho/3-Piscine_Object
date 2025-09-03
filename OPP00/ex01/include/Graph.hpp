/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Graph.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 16:51:42 by macarval          #+#    #+#             */
/*   Updated: 2025/09/03 15:10:53 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPH_HPP
# define GRAPH_HPP

# include <fstream>
# include <vector>
# include <string>

# include <cmath>

# include "Vector2.hpp"

// Color codes as global variables
const std::string RESET = "\033[0m";
const std::string RED = "\033[31;1m";
const std::string GREEN = "\033[32;1m";
const std::string YELLOW = "\033[33;1m";
const std::string BLUE = "\033[34;1m";
const std::string PURPLE = "\033[35;1m";
const std::string CYAN = "\033[36;1m";
const std::string GRAY = "\033[37;1m";

// Bold Colors
const std::string BRED = "\033[1;31m";
const std::string BGREEN = "\033[1;32m";
const std::string BYELLOW = "\033[1;33m";
const std::string BBLUE = "\033[1;34m";
const std::string BPURPLE = "\033[1;35m";
const std::string BCYAN = "\033[1;36m";
const std::string BWHITE = "\033[1;37m";

class Graph
{
	private:
	// Attributes =============================================================
		Vector2					_size;
		std::vector<Vector2>	_list;

	// Methods ================================================================
		std::vector< std::vector<std::string> >	createGraph( void );

	public:
	// Constructor & Destructor ===============================================
		Graph(Vector2 const &size);
		~Graph( void );

	// ========================================================================
		Graph( Graph const &copy );

	// Operators ==============================================================
		Graph& operator=( Graph const &other );

	// Setters ================================================================
		void	addPoint(float x, float y);

	// Methods ================================================================
		void	printGraph( void );

	// Bonus ==================================================================
		void	readFile(const char* filename);
};

#endif
