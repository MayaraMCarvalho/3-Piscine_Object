/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bank.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:31:15 by macarval          #+#    #+#             */
/*   Updated: 2024/09/10 20:45:17 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BANK_HPP
# define BANK_HPP

# include <iostream>
# include <vector>

# include "Account.hpp"

// Color codes as global variables
const std::string RESET = "\033[0m";
const std::string RED = "\033[31;1m";
const std::string GREEN = "\033[32;1m";
const std::string YELLOW = "\033[33;1m";
const std::string BLUE = "\033[34;1m";
const std::string PURPLE = "\033[35;1m";
const std::string CYAN = "\033[36;1m";
const std::string GRAY = "\033[37;1m";

class Bank
{
	private:
		double						liquidity;
		std::vector<Account *>	clientAccounts;

	public:
	// Constructor & Destructor ===============================================
		Bank( void );
		~Bank( void );

	// ========================================================================
		Bank( Bank const &copy );

	// Operators ==============================================================
		Bank&	operator=( Bank const &other );

	// Getters ================================================================
		double		getLiquidity( void ) const;
		Account*	getAccount(int id);
		void		getLoan(double value, int id);

	// Setters ================================================================
		void		setLiquidity(double newLiquidity);

	// Methods ================================================================
		void		openAccount(int newValue);
		void		closeAccount(int id);

		friend std::ostream& operator<<(std::ostream& p_os, const Bank& p_bank);
};

#endif
