/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmorin <kmorin@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:40:10 by kmorin            #+#    #+#             */
/*   Updated: 2024/01/09 16:09:54 by kmorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

void	subject_test(void) {

	std::cout << MAGENTA << "\tSUBJECT TEST" << std::endl;

	MutantStack<int> mstack;

	mstack.push(5);//add 5 to the stack
	mstack.push(17);//add 17 to the stack
	//we have 5, 17

	std::cout << "first element : " << mstack.top() << std::endl;
	//the top element is 17

	mstack.pop();
	//remove the element at the top of the stack / last added element (17), only 5 left

	std::cout << "size: " << mstack.size() << std::endl;
	//the stack has a size of 1 since there is only the 5 left

	mstack.push(3);//add 3 to the stack
	mstack.push(5);//add 5 to the stack
	mstack.push(737);//add 737 to the stack
	//[...]
	mstack.push(0);//add 0 to the stack
	//we have 5, 3, 5, 737, 0

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;//increment the iterator, goes to the next element (2nd)
	--it;//decrement the iterator, goes to the previous element (back to 1st)

	std::cout << "Print all elements of the container: | ";
	while (it != ite)
	{
		std::cout << *it << " | ";
		++it;
	}
	std::stack<int> s(mstack);//create a new container of the same type, no error
	std::cout << std::endl;
}

void	list_test(void) {

	std::cout << YELLOW << "\tLIST TEST" << std::endl;

	std::list<int> l;

	l.push_back(5);
	l.push_back(17);

	std::cout << "first element: " << l.back() << std::endl;

	l.pop_back();

	std::cout << "size: " << l.size() << std::endl;

	l.push_back(3);
	l.push_back(5);
	l.push_back(737);
	//[...]
	l.push_back(0);

	std::list<int>::iterator it = l.begin();
	std::list<int>::iterator ite = l.end();

	++it;
	--it;

	std::cout << "Print all elements of the container: | ";
	while (it != ite)
	{
		std::cout << *it << " | ";
		++it;
	}
	std::list<int> lst(l);
	std::cout << std::endl;
}

void	vector_test(void) {

	std::cout << CYAN << "\tVECTOR TEST" << std::endl;

	std::vector<int> v;

	v.push_back(5);
	v.push_back(17);

	std::cout << "first element: " << v.back() << std::endl;

	v.pop_back();

	std::cout << "size: " << v.size() << std::endl;

	v.push_back(3);
	v.push_back(5);
	v.push_back(737);
	//[...]
	v.push_back(0);

	std::vector<int>::iterator it = v.begin();
	std::vector<int>::iterator ite = v.end();

	++it;
	--it;
	std::cout << "Print all elements of the container: | ";
	while (it != ite)
	{
		std::cout << *it << " | ";
		++it;
	}
	std::vector<int> vec(v);
	std::cout << std::endl;
}

int main(void) {

	std::cout << std::endl;

	subject_test();
	std::cout << std::endl << COLOR(std::string(60, '='), WHITE) << std::endl << std::endl;
	list_test();
	std::cout << std::endl << COLOR(std::string(60, '='), WHITE) << std::endl << std::endl;
	vector_test();

	std::cout << std::endl;

	return 0;
}
