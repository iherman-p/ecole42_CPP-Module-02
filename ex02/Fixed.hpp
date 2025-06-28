/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 15:10:04 by iherman-          #+#    #+#             */
/*   Updated: 2025/06/28 17:35:59 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

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
		Fixed	&operator = (const Fixed &to_cpy);
		Fixed&	min(Fixed& f1, Fixed& f2);
		Fixed&	min(const Fixed& f1, const Fixed& f2);
		Fixed&	max(Fixed& f1, Fixed& f2);
		Fixed&	max(const Fixed& f1, const Fixed& f2);

		/* setters */
		void	setRawBits(int const raw);

		/* getters */
		float	toFloat() const;
		int		toInt() const;	
		int		getRawBits() const;
};

std::ostream	&operator << (std::ostream &out, const Fixed &fixed);

#endif // FIXED_HPP
