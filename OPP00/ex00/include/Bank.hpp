/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bank.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:31:15 by macarval          #+#    #+#             */
/*   Updated: 2025/09/03 14:23:46 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BANK_HPP
# define BANK_HPP

# include <iostream>
# include <sstream>
# include <iomanip>
# include <map>

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
	public:
	// Nested Class ===========================================================
		class Account;
		
	private:
	// Attributes ==============================================================
		double						_liquidity;
		std::map<int, Account *>	_clientAccounts;

	public:
	// Constructor & Destructor ===============================================
		Bank( void );
		~Bank( void );

	// ========================================================================
		Bank( Bank const &copy );

	// Operators ==============================================================
		Bank&	operator=( Bank const &other );

	// Getters ================================================================
		double	getLiquidity( void ) const;

	// Setters ================================================================
		void	setLiquidity(double newLiquidity);

	// Methods ================================================================
		void	openAccount(double newValue);
		void	closeAccount(int id);
		void	giveLoan(int id, double value);

		friend std::ostream& operator<<(std::ostream& p_os, const Bank& p_bank);
		Account& operator[](int id);

	// Exceptions =============================================================
		class NotFoundException : public std::exception
		{
			private:
				std::string message;
			public:
				NotFoundException(int id);
				virtual ~NotFoundException() throw() {};
				virtual const char* what() const throw();
		};

	// Nested Class ===========================================================
		class Account
		{
			private:
			// Attributes =============================================================
				int		_id;
				double	_value;

			// Constructor & Destructor ===============================================
				Account( void );
				Account(int id, double value);
				~Account( void );

			// ========================================================================
				Account( Account const &copy );

				friend class Bank;

			// Methods ================================================================
				friend std::ostream& operator<<
										(std::ostream& p_os, const Account& p_account);

			public:
			// Operators ==============================================================
				Account&	operator=( Account const &other );

			// Getters ================================================================
				int			getId( void ) const;
				double		getValue( void ) const;

			// Setters ================================================================
				void		deposit(double amount);
		};
};

#endif
