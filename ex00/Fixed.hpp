/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 15:10:04 by iherman-          #+#    #+#             */
/*   Updated: 2025/06/28 17:28:34 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Fixed
{
	private:
		int					raw_bits;
		const static int	fract;
	public:
		Fixed();
		Fixed(const Fixed &original);
		~Fixed();
		Fixed	&operator= (const Fixed &original);
		int		getRawBits() const;
		void	setRawBits(int const raw);
};

/*A default constructor that initializes the fixed-point number value to 0.
◦ A copy constructor.
◦ A copy assignment operator overload.
◦ A destructor.
◦ A member function int getRawBits( void ) const;
that returns the raw value of the fixed-point value.
◦ A member function void setRawBits( int const raw );
that sets the raw value of the fixed-point number.*/