/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 15:11:30 by iherman-          #+#    #+#             */
/*   Updated: 2025/08/11 17:50:43 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::fract = 8;

static void	fixed_debug_messages(std::string message, bool allowed)
{
	if (allowed)
		std::cout << message << std::endl;
}

/*. ===> De/Constructors & Assignment <=== .*/

Fixed::Fixed()
		: raw_bits(0)
{
	fixed_debug_messages("Default constructor called", ALLOW_FIXED_DEBUG);
}

Fixed::Fixed(const int number)
	: raw_bits(number * (1 << fract))
{
	fixed_debug_messages("Int constructor called", ALLOW_FIXED_DEBUG);
}

Fixed::Fixed(const float number)
	: raw_bits(static_cast<int>(roundf(number * (1 << fract))))
{
	fixed_debug_messages("Float constructor called", ALLOW_FIXED_DEBUG);
	raw_bits = int(roundf(number * (1 << fract)));
}

Fixed::Fixed(const Fixed &other) 
		: raw_bits(other.raw_bits)
{
	fixed_debug_messages("Copy constructor called", ALLOW_FIXED_DEBUG);
}

Fixed::~Fixed()
{
	fixed_debug_messages("Destructor called", ALLOW_FIXED_DEBUG);
}

Fixed &Fixed::operator= (const Fixed &other)
{
	fixed_debug_messages("Copy assignment operator called", ALLOW_FIXED_DEBUG);
	if (this != &other)
		this->raw_bits = other.getRawBits();
	return *this;
}

/*. ===> Comparison operators <=== .*/

bool	Fixed::operator< (const Fixed &other) const
{
	return (this->raw_bits < other.raw_bits);
}

bool	Fixed::operator> (const Fixed &other) const
{
	return (this->raw_bits > other.raw_bits);
}

bool	Fixed::operator== (const Fixed &other) const
{
	if (!(*this < other || other < *this))
		return (true);
	else
		return (false);
}

bool	Fixed::operator<= (const Fixed &other) const
{
	if (*this == other || *this < other)
		return (true);
	else
		return (false);
}

bool	Fixed::operator>= (const Fixed &other) const
{
	if (other == *this || other < *this)
		return (true);
	else
		return (false);
}

bool	Fixed::operator!= (const Fixed &other) const
{
	if ((*this == other))
		return (false);
	else
		return (true);
}

/*. ===> Min/Max <=== .*/

Fixed&	Fixed::min(Fixed& f1, Fixed& f2)
{
	if (f1 <= f2)
		return (f1);
	else
		return (f2);
}

Fixed&	Fixed::max(Fixed& f1, Fixed& f2)
{
	if (f1 >= f2)
		return (f1);
	else
		return (f2);
}

const Fixed&	Fixed::min(const Fixed& f1, const Fixed& f2)
{
	if (f1 <= f2)
		return (f1);
	else
		return (f2);
}

const Fixed&	Fixed::max(const Fixed& f1, const Fixed& f2)
{
	if (f1 >= f2)
		return (f1);
	else
		return (f2);
}

/*. ===> Getter(s) & Setter(s) <=== .*/

void	Fixed::setRawBits(int const raw)
{
	this->raw_bits = raw;
	fixed_debug_messages("setRawBits member function called", ALLOW_FIXED_DEBUG);
}

int	Fixed::getRawBits() const
{
	fixed_debug_messages("getRawBits member function called", ALLOW_FIXED_DEBUG);
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

/*. ===> Arithmetic <=== .*/

Fixed	Fixed::operator+ (const Fixed& other) const
{
	Fixed	ret(*this);

	ret.raw_bits += other.raw_bits;
	return (ret);
}

Fixed	Fixed::operator+ (const float number) const
{
	return (*this + Fixed(number));
}

Fixed	Fixed::operator- (const Fixed& other) const
{
	Fixed	ret(*this);

	ret.raw_bits -= other.raw_bits;
	return (ret);
}

Fixed	Fixed::operator- (const float number) const
{
	return (*this - Fixed(number));
}

Fixed	Fixed::operator* (const Fixed& other) const
{
	Fixed	ret(*this);
	int64_t	temp;

	temp = ret.raw_bits * other.raw_bits;
	ret.raw_bits = (temp >> fract);
	return (ret);
}

Fixed	Fixed::operator* (const float number) const
{
	return (*this * Fixed(number));
}

Fixed	Fixed::operator/ (const Fixed& other) const
{
	Fixed	ret(*this);

	if (other.raw_bits == 0)
		return Fixed(0);
	ret.raw_bits = (ret.raw_bits << fract) / other.raw_bits;
	return (ret);
}

Fixed	Fixed::operator/ (const float number) const
{
	return (*this / Fixed(number));
}

Fixed&	Fixed::operator++()
{
		++raw_bits;
		return *this;
}

Fixed	Fixed::operator++(int)
{
		Fixed temp = *this;
		++(*this);
		return temp;
}

Fixed&	Fixed::operator--()
{
		--raw_bits;
		return *this;
}

Fixed	Fixed::operator--(int)
{
		Fixed temp = *this;
		--(*this);
		return temp;
}

/*. ===> i/o stream <=== .*/

std::ostream	&operator<< (std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

