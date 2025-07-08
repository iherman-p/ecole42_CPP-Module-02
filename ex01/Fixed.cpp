/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 15:11:30 by iherman-          #+#    #+#             */
/*   Updated: 2025/07/08 16:09:17 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::fract = 8;

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->raw_bits = 0;
}

Fixed::Fixed(const int number)
{
	std::cout << "Int constructor called" << std::endl;
	raw_bits = (number * (1 << fract));
}

Fixed::Fixed(const float number)
{
	std::cout << "Float constructor called" << std::endl;
	raw_bits = int(roundf(number * (1 << fract)));
}

Fixed::Fixed(const Fixed &to_cpy) 
		: raw_bits(to_cpy.raw_bits)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

/* setters */
void	Fixed::setRawBits(int const raw)
{
	this->raw_bits = raw;
	std::cout << "setRawBits member function called" << std::endl;
}

/* getters */
int	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->raw_bits);
}

float	Fixed::toFloat() const
{
	return (raw_bits / float(1 << fract));
}

int	Fixed::toInt() const
{
	return (raw_bits / (1 << fract));
}

/* operators */
Fixed &Fixed::operator = (const Fixed &to_cpy)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &to_cpy)
		this->raw_bits = to_cpy.getRawBits();
	return *this;
}

std::ostream	&operator << (std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

