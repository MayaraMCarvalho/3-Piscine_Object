/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bank.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:31:15 by macarval          #+#    #+#             */
/*   Updated: 2024/09/17 20:37:06 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BANK_HPP
# define BANK_HPP

# include <iostream>
# include <vector>

# include "Account.hpp"

class Bank
{
	private:
		double					_liquidity;
		std::vector<Account *>	_clientAccounts;

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
		Account*	getAccount(int id) const;

	// Setters ================================================================
		void		setLiquidity(double newLiquidity);

	// Methods ================================================================
		void		openAccount(double newValue);
		void		closeAccount(int id);
		void		giveLoan(int id, double value);

		friend std::ostream& operator<<(std::ostream& p_os, const Bank& p_bank);
};

#endif
