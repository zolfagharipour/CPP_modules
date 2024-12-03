/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyFind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 16:29:47 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/08/16 14:47:31 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
typename T::const_iterator	easyFind( T& intContainer, int toFind )
{
	typename T::const_iterator	it;
	it = std::find(intContainer.begin(), intContainer.end(), toFind);
	if (it == intContainer.end())
		throw NotFoundException();
	return (it);
}

template <typename T>
const typename T::const_iterator	easyFind( const T& intContainer, int toFind )
{
	typename T::const_iterator	it;
	it = std::find(intContainer.begin(), intContainer.end(), toFind);
	if (it == intContainer.end())
		throw NotFoundException();
	return (it);
}
