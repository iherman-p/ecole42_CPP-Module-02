/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 15:11:30 by iherman-          #+#    #+#             */
/*   Updated: 2025/08/11 17:36:11 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::fract = 8;

/*. ===> De/Constructors & Assignment <=== .*/

Fixed::Fixed()
		: raw_bits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int number)
	: raw_bits(number * (1 << fract))
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float number)
	: raw_bits(static_cast<int>(roundf(number * (1 << fract))))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) 
		: raw_bits(other.raw_bits)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->raw_bits = other.raw_bits;
	return *this;
}

/*. ===> Getter(s) & Setter(s) <=== .*/

void	Fixed::setRawBits(int const raw)
{
	this->raw_bits = raw;
	std::cout << "setRawBits member function called" << std::endl;
}

int	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->raw_bits);
}

/*. ===> Conversion <=== .*/

float	Fixed::toFloat() const
{
	return (raw_bits / float(1 << fract));
}

int	Fixed::toInt() const
{
	return (raw_bits / (1 << fract));
}

/*. ===> i/o stream <=== .*/

std::ostream	&operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

