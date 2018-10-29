#include <iostream>
#include "headers\tools.h"

int n_elements;

int main(int argc, char** argv)
{
    std::cout << "Please input the number of elements your list will have: ";    
    std::cin >> n_elements; n_elements++;

    int list[n_elements];
	_t::nullify(list, n_elements);

	std::cout << "Please input each element of your list: ";
	_t::cin(list, n_elements);
	
	_t::sort(list);
	std::cout << "List sorted in ascending order: " << std::endl; _t::cout(list);
	
	_t::sort(list, false);
	std::cout << "List sorted in descending order: " << std::endl; _t::cout(list);
	
	return 0;
}

