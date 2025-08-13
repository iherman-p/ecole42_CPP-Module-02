/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 15:10:04 by iherman-          #+#    #+#             */
/*   Updated: 2025/08/11 17:23:42 by iherman-         ###   ########.fr       */
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
		Fixed(const Fixed &other);
		~Fixed();
		Fixed	&operator = (const Fixed &other);

		void	setRawBits(int const raw);
	
		int		getRawBits() const;

		float	toFloat() const;
		int		toInt() const;
};

std::ostream	&operator << (std::ostream &out, const Fixed &fixed);

#endif // FIXED_HPP
