/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 15:10:04 by iherman-          #+#    #+#             */
/*   Updated: 2025/07/03 15:07:51 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# ifndef ALLOW_FIXED_DEBUG
#  define ALLOW_FIXED_DEBUG 1
# endif

#include <ostream>

class Fixed
{
	private:
		int					raw_bits;
		const static int	fract;
	public:
		Fixed();
		Fixed(const int number);
		Fixed(const float number);
		Fixed(const Fixed &to_cpy);
		~Fixed();

		/* comparison */
		bool	operator< (const Fixed &other) const;
		bool	operator== (const Fixed &other) const;
		bool	operator<= (const Fixed &other) const;
		bool	operator>= (const Fixed &other) const;
		bool	operator!= (const Fixed &other) const;
		static Fixed&		min(Fixed& f1, Fixed& f2);
		static Fixed&		max(Fixed& f1, Fixed& f2);
		static const Fixed&	min(const Fixed& f1, const Fixed& f2);
		static const Fixed&	max(const Fixed& f1, const Fixed& f2);

		/* setters */
		Fixed	&operator= (const Fixed &to_cpy);
		void	setRawBits(int const raw);

		/* getters */
		float	toFloat() const;
		int		toInt() const;	
		int		getRawBits() const;

		/* arithmetic operators */
		Fixed	operator+ (const Fixed& other) const;
		Fixed	operator+ (const float number) const;
		
		Fixed	operator- (const Fixed& other) const;
		Fixed	operator- (const float number) const;
		
		Fixed	operator* (const Fixed& other) const;
		Fixed	operator* (const float number) const;

		Fixed	operator/ (const Fixed& other) const;
		Fixed	operator/ (const float number) const;

		Fixed&	operator++();
		Fixed	operator++(int);

};

std::ostream	&operator<< (std::ostream &out, const Fixed &fixed);

#endif // FIXED_HPP
