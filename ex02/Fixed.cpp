/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 15:11:30 by iherman-          #+#    #+#             */
/*   Updated: 2025/07/03 15:34:42 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

const int Fixed::fract = 8;

/*///////////////////////////////////*/
//		Con/Destructors              //
/*///////////////////////////////////*/

/*. ===> Constructors <=== .*/

static void	fixed_debug_messages(std::string message, bool allowed)
{
	if (allowed)
		std::cout << message << std::endl;
}

Fixed::Fixed()
{
	fixed_debug_messages("Default constructor called", ALLOW_FIXED_DEBUG);
	this->raw_bits = 0;
}

Fixed::Fixed(const int number)
{
	fixed_debug_messages("Int constructor called", ALLOW_FIXED_DEBUG);
	raw_bits = (number * (1 << fract));
}

Fixed::Fixed(const float number)
{
	fixed_debug_messages("Float constructor called", ALLOW_FIXED_DEBUG);
	raw_bits = int(roundf(number * (1 << fract)));
}

/*. ===> Copy constructor <=== .*/

Fixed::Fixed(const Fixed &to_cpy)
{
	fixed_debug_messages("Copy constructor called", ALLOW_FIXED_DEBUG);
	*this = to_cpy;
}

/*. ===> Destructor <=== .*/

Fixed::~Fixed()
{
	fixed_debug_messages("Destructor called", ALLOW_FIXED_DEBUG);
}

/*///////////////////////////////////*/
//		Comparison                   //
/*///////////////////////////////////*/

/*. ===> Comparison operators <=== .*/

bool	Fixed::operator< (const Fixed &other) const
{
	return (this->raw_bits < other.raw_bits);
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

/*///////////////////////////////////*/
//		Setters                      //
/*///////////////////////////////////*/

Fixed &Fixed::operator= (const Fixed &to_cpy)
{
	fixed_debug_messages("Copy assignment operator called", ALLOW_FIXED_DEBUG);
	if (this != &to_cpy)
		this->raw_bits = to_cpy.getRawBits();
	return *this;
}

void	Fixed::setRawBits(int const raw)
{
	this->raw_bits = raw;
	fixed_debug_messages("setRawBits member function called", ALLOW_FIXED_DEBUG);
}

/*///////////////////////////////////*/
//		Getters                      //
/*///////////////////////////////////*/

int	Fixed::getRawBits() const
{
	fixed_debug_messages("getRawBits member function called", ALLOW_FIXED_DEBUG);
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

/*///////////////////////////////////*/
//		Arithmetic operators         //
/*///////////////////////////////////*/

/* + */

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

/* - */

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

/* * */

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

/* / */

Fixed	Fixed::operator/ (const Fixed& other) const
{
	Fixed	ret(*this);

	ret.raw_bits = (ret.raw_bits << fract) / other.raw_bits;
	return (ret);
}

Fixed	Fixed::operator/ (const float number) const
{
	return (*this / Fixed(number));
}

/* increment */

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


/*///////////////////////////////////*/
//		Misc                         //
/*///////////////////////////////////*/

std::ostream	&operator<< (std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

