// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   Account.hpp                                        :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/09/10 18:30:30 by macarval          #+#    #+#             */
// /*   Updated: 2024/09/17 16:40:06 by macarval         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #ifndef ACCOUNT_HPP
// # define ACCOUNT_HPP

// # include <iostream>
// # include <iomanip>
// # include <vector>

// // Color codes as global variables
// const std::string RESET = "\033[0m";
// const std::string RED = "\033[31;1m";
// const std::string GREEN = "\033[32;1m";
// const std::string YELLOW = "\033[33;1m";
// const std::string BLUE = "\033[34;1m";
// const std::string PURPLE = "\033[35;1m";
// const std::string CYAN = "\033[36;1m";
// const std::string GRAY = "\033[37;1m";

// class Account
// {
// 	private:
// 		int		_id;
// 		double	_value;

// 		// Constructor & Destructor ===============================================
// 		Account( void );
// 		Account(int id, double value);
// 		~Account( void );

// 		// ========================================================================
// 		Account( Account const &copy );

// 		friend class Bank;

// 	public:


// 	// Operators ==============================================================
// 		Account&	operator=( Account const &other );

// 	// Getters ================================================================
// 		int			getId( void ) const;
// 		double		getValue( void ) const;

// 	// Methods ================================================================
// 		friend std::ostream& operator<<
// 								(std::ostream& p_os, const Account& p_account);

// };



// #endif

