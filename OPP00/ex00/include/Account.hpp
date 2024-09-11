/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macarval <macarval@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 18:30:30 by macarval          #+#    #+#             */
/*   Updated: 2024/09/10 20:31:14 by macarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACCOUNT_HPP
# define ACCOUNT_HPP

# include <iostream>
# include <vector>

class Account
{
	private:
		int	id;
		double	value;

	public:
	// Constructor & Destructor ===============================================
		Account( void );
		~Account( void );

	// ========================================================================
		Account( Account const &copy );

	// Operators ==============================================================
		Account&	operator=( Account const &other );

	// Getters ================================================================
		int			getId( void ) const;
		double		getValue( void ) const;

	// Setters ================================================================
		void		setId(int newId);
		void		setValue(double newValue);

	// Methods ================================================================
		friend std::ostream& operator<<
								(std::ostream& p_os, const Account& p_account);

};



#endif

