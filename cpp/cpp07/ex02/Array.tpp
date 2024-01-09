/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 13:27:13 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 16:07:50 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

/* ************************************************************************** */
/*                            CANONICAL FUNCTIONS                             */
/* ************************************************************************** */

template <typename T>
Array<T>::Array(void) : _array(NULL), _len(0) {

	if (SHOWMSG)
		std::cout << COLOR("Array ", BLUE) << COLOR("Default constructor called", GREEN) << std::endl;
}

template <typename T>
Array<T>::Array(const Array& src) : _array(new T[src._len]), _len(src._len) {

	for (unsigned int i = 0; i < _len; i++)
		_array[i] = src._array[i];

	if (SHOWMSG)
		std::cout << COLOR("Array ", BLUE) << COLOR("Copy constructor called", GREEN) << std::endl;
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array& rhs) {

	if (this != &rhs) {
		delete [] _array;
		_len = rhs._len;
		_array = new T[_len];
		for (unsigned int i = 0; i < _len; i++)
			_array[i] = rhs._array[i];
	}

	if (SHOWMSG)
		std::cout << COLOR("Array ", BLUE) << COLOR("Assignation operator called", GREEN) << std::endl;

	return (*this);
}

template <typename T>
Array<T>::~Array(void) {

	delete [] this->_array;

	if (SHOWMSG)
		std::cout << COLOR("Array ", BLUE) << COLOR("Default destructor called", RED) << std::endl;
}

/* ************************************************************************** */
/*                           PARAMETRIC CONSTRUCTOR                           */
/* ************************************************************************** */

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _len(n) {

	if (SHOWMSG)
		std::cout << COLOR("Array ", BLUE) << COLOR("Parametric constructor called", GREEN) << std::endl;
}

/* ************************************************************************** */
/*                               MEMBER FUNCTIONS                             */
/* ************************************************************************** */

template <typename T>
T&	Array<T>::operator[](unsigned int n) {

	if (n >= _len)
		throw (OutOfBoundsException());
	return (_array[n]);
}

template <typename T>
unsigned int	Array<T>::size(void) const {

	return (_len);
}

/* ************************************************************************** */
/*                              EXCEPTION CLASS                               */
/* ************************************************************************** */

template <typename T>
const char*	Array<T>::OutOfBoundsException::what() const throw() {

	return (RED "Index is out of bounds" RESET);
}
