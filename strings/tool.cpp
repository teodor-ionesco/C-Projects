#include <iostream>
#include "headers/tools.h"

void _1()
{
	char tmp;
	
	std::cout << "Please input the desired character: ";
	std::cin >> tmp;
	
	std::cout << "\nConverted character: " << _t::chr(tmp) << "\n\n";
}

void _2()
{
	int tmp;
	
	std::cout << "Please input the desired character: ";
	std::cin >> tmp;
	
	std::cout << "\nConverted character: " << _t::chr(tmp) << "\n\n";
}

void _3()
{
	char tmp[256];
	int tmp2[256];
	
	std::cout << "Please input the desired string: ";
	std::cin >> tmp;
	
	_t::to_ascii(tmp, tmp2);
	_t::cout(tmp2);
	
	std::cout << "\n\n";
}

int choice;

int main()
{
	while(true)
	{
		std::cout << "What would you like to do?\n" 
					<< "(0) Exit\n"
					<< "(1) Convert char to ASCII code\n"
					<< "(2) Convert ASCII code to char\n"
					<< "(3) Convert string to ASCII code\n";
		std::cin >> choice;
		
		if(choice == 0)
			break;
		
		switch(choice)
		{			
			case 1:
			{
				_1();
				break;
			};
			
			case 2:
			{
				_2();
				break;
			}
			
			case 3:
			{
				_3();
				break;
			}
			
			default:
			{
				std::cout << "Please pick up a valid choice.\n";
				break;
			};
		}
	}
	
	std::cout << "\nBye bye!";
	
	return 0;
}