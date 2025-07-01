/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 15:11:30 by iherman-          #+#    #+#             */
/*   Updated: 2025/07/01 18:04:02 by iherman-         ###   ########.fr       */
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

/*. ===> Copy constructor <=== .*/

Fixed::Fixed(const Fixed &to_cpy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = to_cpy;
}

/*. ===> Destructor <=== .*/

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
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
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &to_cpy)
		this->raw_bits = to_cpy.getRawBits();
	return *this;
}

void	Fixed::setRawBits(int const raw)
{
	this->raw_bits = raw;
	std::cout << "setRawBits member function called" << std::endl;
}

/*///////////////////////////////////*/
//		Getters                      //
/*///////////////////////////////////*/

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

/* yeah... */

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

/*///////////////////////////////////*/
//		Misc                         //
/*///////////////////////////////////*/

std::ostream	&operator<< (std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

