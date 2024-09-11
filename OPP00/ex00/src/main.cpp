/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:26:10 by macarval          #+#    #+#             */
/*   Updated: 2024/09/10 20:43:24 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bank.hpp"

int main(void)
{
	Bank bank = Bank();
	bank.setLiquidity(999);

	bank.openAccount(100);
	bank.openAccount(200);
	bank.openAccount(300);
	bank.openAccount(400);

	std::cout << std::endl;
	std::cout << BLUE << " ----- " << std::endl;
	std::cout << "Bank : " << std::endl;
	std::cout << GREEN << bank;
	std::cout << BLUE << " ----- " << std::endl;
	std::cout << RESET << std::endl;

	bank.closeAccount(2);
	bank.closeAccount(5);

	bank.openAccount(200);

	bank.setLiquidity(-200);

	std::cout << std::endl;
	std::cout << BLUE << " ----- " << std::endl;
	std::cout << "Bank : " << std::endl;
	std::cout << GREEN << bank;
	std::cout << BLUE << " ----- " << std::endl;
	std::cout << RESET << std::endl;

	std::cout << PURPLE << "Account : ";
	std::cout  << *bank.getAccount(5) << RESET << std::endl;
	std::cout  << *bank.getAccount(2) << RESET << std::endl;

	return 0;
}

