/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:26:10 by macarval          #+#    #+#             */
/*   Updated: 2025/09/03 11:45:36 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bank.hpp"

void subject()
{
	Bank bank = Bank();
	bank.setLiquidity(999);

	bank.openAccount(100);
	bank.openAccount(100);

	bank.setLiquidity(-200);
	bank.giveLoan(bank[1].getId(), 400);

	std::cout << "Account : " << std::endl;
	std::cout << bank[1];
	std::cout << bank[2];

	std::cout << " ----- " << std::endl;

	std::cout << "Bank : " << std::endl;
	std::cout << bank << std::endl;

}

int main(void)
{
	try {
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

		bank.closeAccount(4);

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

		std::cout << PURPLE << std::endl;
		std::cout << "Accounts : " << std::endl;
		std::cout << bank[5];
		std::cout << bank[1];
		std::cout << bank[3];

		std::cout << BLUE << std::endl;
		std::cout << "---------------------------------------------------------\n";
		std::cout << CYAN;
		std::cout << "Granting loan\n";
		std::cout << BLUE;
		std::cout << "---------------------------------------------------------\n";

		bank.giveLoan(5, 859);

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
		std::cout << CYAN;
		std::cout << "Exceptions tests\n";
		std::cout << BLUE;
		std::cout << "---------------------------------------------------------\n";

		try
		{
			bank.closeAccount(25);
		}
		catch (const std::exception& e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}

		try
		{
			std::cout << bank[20];
		}
		catch (const std::exception& e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}

		try
		{
			bank.giveLoan(5, -250);
		}
		catch (const std::exception& e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}

		try
		{
			bank.giveLoan(10, 1);
		}
		catch (const std::exception& e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}

		try
		{
			bank.giveLoan(5, 250);
		}
		catch (const std::exception& e)
		{
			std::cerr << RED << e.what() << RESET << std::endl;
		}


		std::cout << BLUE << std::endl;
		std::cout << "---------------------------------------------------------\n";
		std::cout << GRAY;
		std::cout << "---------------------- END OF TEST ----------------------\n";
		std::cout << BLUE;
		std::cout << "---------------------------------------------------------\n";
		std::cout << RESET << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}

	return 0;
}

