/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 15:10:04 by iherman-          #+#    #+#             */
/*   Updated: 2025/06/28 17:28:30 by iherman-         ###   ########.fr       */
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

		/* setters */
		void	setRawBits(int const raw);

		Fixed	&operator = (const Fixed &to_cpy);
	
		/* getters */
		float	toFloat() const;
		int		toInt() const;
		int		getRawBits() const;
};

std::ostream	&operator << (std::ostream &out, const Fixed &fixed);

#endif // FIXED_HPP
