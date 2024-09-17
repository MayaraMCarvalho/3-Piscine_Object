/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:26:10 by macarval          #+#    #+#             */
/*   Updated: 2024/09/17 20:37:38 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bank.hpp"
void subject()
{
	Bank bank = Bank();
	bank.setLiquidity(999);

	bank.openAccount(100);
	bank.openAccount(100);
	Account *accountA = bank.getAccount(1);
	Account *accountB = bank.getAccount(2);

	bank.setLiquidity(-200);
	bank.giveLoan(accountA->getId(), 400);

	std::cout << "Account : " << std::endl;
	std::cout << *accountA;
	std::cout << *accountB;

	std::cout << " ----- " << std::endl;

	std::cout << "Bank : " << std::endl;
	std::cout << bank << std::endl;

}

int main(void)
{
	Bank bank = Bank();
	bank.setLiquidity(999);

	std::cout << BLUE << std::endl;
	std::cout << "---------------------------------------------------------\n";
	std::cout << GRAY;
	std::cout << "************************* TESTS *************************\n";
	std::cout << BLUE;
	std::cout << "---------------------------------------------------------\n";
	std::cout << CYAN;
	std::cout << "Creating accounts" << std::endl;
	std::cout << BLUE;
	std::cout << "---------------------------------------------------------\n";

	bank.openAccount(100);
	bank.openAccount(200);
	bank.openAccount(300);
	bank.openAccount(400);

	std::cout << BLUE << std::endl;
	std::cout << "---------------------------------------------------------\n";
	std::cout << CYAN;
	std::cout << "Showing bank information\n";
	std::cout << BLUE;
	std::cout << "---------------------------------------------------------\n";

	std::cout << YELLOW << "--------------------" << std::endl;
	std::cout << "***** Bank *****" << std::endl;
	std::cout << bank;
	std::cout << YELLOW << "--------------------" << RESET << std::endl;

	std::cout << BLUE << std::endl;
	std::cout << "---------------------------------------------------------\n";
	std::cout << CYAN;
	std::cout << "Closing accounts\n";
	std::cout << BLUE;
	std::cout << "---------------------------------------------------------\n";

	bank.closeAccount(2);
	bank.closeAccount(5);

	std::cout << BLUE << std::endl;
	std::cout << "---------------------------------------------------------\n";
	std::cout << CYAN;
	std::cout << "Showing bank information\n";
	std::cout << BLUE;
	std::cout << "---------------------------------------------------------\n";

	bank.openAccount(200);

	std::cout << std::endl;
	std::cout << YELLOW << "--------------------" << std::endl;
	std::cout << "***** Bank *****" << std::endl;
	std::cout << bank;
	std::cout << YELLOW << "--------------------" << RESET << std::endl;

	std::cout << BLUE << std::endl;
	std::cout << "---------------------------------------------------------\n";
	std::cout << CYAN;
	std::cout << "Showing accounts information\n";
	std::cout << BLUE;
	std::cout << "---------------------------------------------------------\n";

	Account* accountA = bank.getAccount(1);
	Account* accountB = bank.getAccount(3);
	Account* accountC = bank.getAccount(20);

	std::cout << PURPLE << std::endl;
	std::cout << "Accounts : " << std::endl;
	std::cout << *bank.getAccount(5);
	std::cout << *bank.getAccount(2);
	std::cout << *accountA;
	std::cout << *accountB;
	std::cout << *accountC << std::endl;

	std::cout << BLUE << std::endl;
	std::cout << "---------------------------------------------------------\n";
	std::cout << CYAN;
	std::cout << "Granting loans\n";
	std::cout << BLUE;
	std::cout << "---------------------------------------------------------\n";

	bank.giveLoan(5, -250);
	bank.giveLoan(10, 1000);
	bank.giveLoan(5, 859);
	bank.giveLoan(5, 250);

	std::cout << BLUE << std::endl;
	std::cout << "---------------------------------------------------------\n";
	std::cout << CYAN;
	std::cout << "Showing bank information\n";
	std::cout << BLUE;
	std::cout << "---------------------------------------------------------\n";

	std::cout << YELLOW << "--------------------" << std::endl;
	std::cout << "***** Bank *****" << std::endl;
	std::cout << bank;
	std::cout << YELLOW << "--------------------" << RESET << std::endl;

	std::cout << BLUE << std::endl;
	std::cout << "---------------------------------------------------------\n";
	std::cout << CYAN;
	std::cout << "Subject tests\n";
	std::cout << BLUE;
	std::cout << "---------------------------------------------------------\n";

	subject();

	std::cout << BLUE << std::endl;
	std::cout << "---------------------------------------------------------\n";
	std::cout << GRAY;
	std::cout << "---------------------- END OF TEST ----------------------\n";
	std::cout << BLUE;
	std::cout << "---------------------------------------------------------\n";
	std::cout << RESET << std::endl;

	return 0;
}

