/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SortVector.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzolfagh <mzolfagh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 12:55:59 by mzolfagh          #+#    #+#             */
/*   Updated: 2024/08/26 15:37:35 by mzolfagh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

std::vector< std::vector<int> >*	PmergeMe::_bottomRecursion( std::vector< std::vector<int> >& motherSet )
{
	int		tmp;
	if (motherSet[0].size() == 2 && motherSet[0][0] > motherSet[0][1])
	{
		_comparisons++;
		for (unsigned int i = 0; i < motherSet.size(); i++)
		{
			tmp = motherSet[i][0];
			motherSet[i][0] = motherSet[i][1];
			motherSet[i][1] = tmp;
		}
	}
	return(&motherSet);
}

std::vector< std::vector<int> >*	PmergeMe::_divide( std::vector< std::vector<int> >& motherSet)
{
	std::vector< std::vector<int> >*	newSet = new std::vector< std::vector<int> >;
	std::vector<int>				tmpSet;
	int								remainder;

	newSet->resize(pow(2, (_depth + 1)));

	for (unsigned int i = 0; i < motherSet[0].size() - 1; i += 2)
	{
		_comparisons++;
		if (motherSet[0][i] >= motherSet[0][i + 1])
		{
			for (unsigned int j = 0; j < motherSet.size(); j++)
			{
				(*newSet)[j * 2].push_back(motherSet[j][i]);
				(*newSet)[(j * 2) + 1].push_back(motherSet[j][i + 1]);
			}
		}
		else
		{
			for (unsigned int j = 0; j < motherSet.size(); j++)
			{
				(*newSet)[(j * 2) + 1].push_back(motherSet[j][i]);
				(*newSet)[j * 2].push_back(motherSet[j][i + 1]);
			}
		}
	}
	
	remainder = (motherSet[0].size() / 2) * 2;
	for (unsigned int i = 0; i < motherSet.size(); i++)
	{
		for (unsigned int j = remainder; j < motherSet[i].size(); j++)
			(*newSet)[(i * 2) + 1].push_back(motherSet[i][j]);
	}
	delete &motherSet;
	if ((*newSet)[0].size() < 3)
		return (_bottomRecursion(*newSet));
	_depth++;
	return(_divide(*newSet));
}

int	PmergeMe::_binaryInsert( std::vector<int>& sortedVector, int upperBound, int nbr )
{
	int	lowerBound = 0;
	int	mid = 0;
	int	comp = 0;

	while( lowerBound <= upperBound)
	{

		mid = lowerBound + (upperBound - lowerBound) / 2;
		_comparisons++;
		comp++;
		if (sortedVector[mid] == nbr)
		{
			sortedVector.insert(sortedVector.begin() + mid + 1, nbr);
			return (mid + 1);
		}
		else if (sortedVector[mid] < nbr)
			lowerBound = mid + 1;
		else
			upperBound = mid - 1;
	}
	sortedVector.insert(sortedVector.begin() + lowerBound, nbr);
	return(lowerBound);
}

void	PmergeMe::_createJakob( unsigned int size )
{
	unsigned int	i = size;
	_jakobsThal.clear();
	for (unsigned int k = 1 ; i <= size; k++)
	{
		i = (pow(2, k + 1) + (pow(-1, k))) / 3;
		if (i < size)
			_jakobsThal.push_back(i - 1);
		else
		{
			_jakobsThal.push_back(size - 1);
			return ;
		}
	}
}

std::vector< std::vector<int> >*	PmergeMe::_conquer( std::vector< std::vector<int> >& motherSet )
{
	std::vector< std::vector<int> >*	newSet = new std::vector< std::vector<int> >;
	unsigned int						insert;
	unsigned int						x = 1;
	unsigned int						lenCorrection;

	for (unsigned int i = 1; i < motherSet.size(); i += 2)
		motherSet[i - 1].insert(motherSet[i - 1].begin(), motherSet[i][0]);
	
	_createJakob(motherSet[1].size());
	for (unsigned int i = 1; i < _jakobsThal.size(); i ++)
	{
		lenCorrection = 0;
		for (unsigned int k = _jakobsThal[i]; k > _jakobsThal[i - 1]; k--)
		{
			insert = _binaryInsert(motherSet[0], k + x - lenCorrection - 1, motherSet[1][k]);
			for (unsigned int j = 2; j < motherSet.size(); j += 2)
				motherSet[j].insert(motherSet[j].begin() + insert, motherSet[j + 1][k]);
			if (insert >= k + x - lenCorrection)
				lenCorrection++;
			x++;
		}
	}

	for (unsigned int i = 3; i < motherSet.size(); i += 2)
	{
		for (unsigned int j = motherSet[1].size(); j < motherSet[i].size(); j ++)
			motherSet[i - 1].push_back(motherSet[i][j]);
	}

	for (unsigned int i = 0; i < motherSet.size(); i += 2)
		(*newSet).push_back(motherSet[i]);

	delete &motherSet;
	if ((*newSet).size() == 1)
		return (newSet);
	return (_conquer(*newSet));
}

void	PmergeMe::_printMother( std::vector< std::vector<int> > motherSet )
{
	for (unsigned int i = 0; i < motherSet.size(); i++)
	{
		for (unsigned int j = 0; j < motherSet[i].size(); j++)
			std::cout << motherSet[i][j] << " ";
		std::cout << std::endl;
	}
}

void	PmergeMe::_isItSorted(const std::vector<int>& vec)
{
	for (unsigned int i = 0; i < vec.size() - 1; i++)
	{
		if (vec[i] > vec[i + 1])
		{
			std::cout << "NOT SORTED" << std::endl;
			return ;
		}
	}
	std::cout << "SORTED" << std::endl;
}

std::vector< std::vector<int> >*	PmergeMe::_sort( void )
{
	std::vector< std::vector<int> >*	motherSet = new std::vector< std::vector<int> >;

	(*motherSet).push_back(_data);
	motherSet = _divide(*motherSet);
	motherSet = _conquer(*motherSet);
	// _isItSorted((*motherSet)[0]);
	return (motherSet);
}

