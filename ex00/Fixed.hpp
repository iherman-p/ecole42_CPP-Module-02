/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 15:10:04 by iherman-          #+#    #+#             */
/*   Updated: 2025/08/11 17:23:18 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	private:
		int					raw_bits;
		const static int	fract;
	public:
		Fixed();
		Fixed(const Fixed &other);
		~Fixed();
		Fixed	&operator= (const Fixed &other);

		int		getRawBits() const;
		void	setRawBits(int const raw);
};

#endif // FIXED_HPP
