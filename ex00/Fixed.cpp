/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 15:11:30 by iherman-          #+#    #+#             */
/*   Updated: 2025/06/28 17:31:23 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

const int Fixed::fract = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->raw_bits = 0;
}

Fixed::Fixed(const Fixed &original)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = original;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->raw_bits);
}

void	Fixed::setRawBits(int const raw)
{
	this->raw_bits = raw;
	std::cout << "setRawBits member function called" << std::endl;
}

Fixed &Fixed::operator = (const Fixed &to_cpy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &to_cpy)
		this->raw_bits = to_cpy.getRawBits();
	return *this;
}