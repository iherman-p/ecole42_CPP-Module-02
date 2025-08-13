/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 16:01:35 by iherman-          #+#    #+#             */
/*   Updated: 2025/08/11 17:53:25 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << Fixed::min(Fixed(float(5.5)), Fixed(float(4.5)) ) << std::endl;

	// Float example:
	{
		const float fl1(3.14);
		const float fl2(5.2);
		const float fl3(1.001);

		std::cout << "Float example:" << std::endl;
		std::cout << fl1 << std::endl;
		std::cout << fl1 + fl2 << std::endl;
		std::cout << fl3 + fl3 << std::endl;
	}

	// Fixed example:
	{
		const Fixed fi1(float(3.14));
		const Fixed fi2(float(5.2));
		const Fixed fi3(float(1.001));

		std::cout << "Fixed example:" << std::endl;
		std::cout << fi1 << std::endl;
		std::cout << fi1 + fi2 << std::endl;
		std::cout << fi3 + fi3 << std::endl;
	}

	// Negative example:
	{
		const Fixed fi1(float(-3.14));
		const Fixed fi2(float(-5.2));
		const Fixed fi3(float(-1.001));

		std::cout << "Negative example:" << std::endl;
		std::cout << fi1 << std::endl;
		std::cout << fi1 + fi2 << std::endl;
		std::cout << fi3 + fi3 << std::endl;
	}
	return 0;
}