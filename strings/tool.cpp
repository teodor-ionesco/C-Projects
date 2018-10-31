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

void _4()
{
	char tmp[512];
	int tmp2[256]; _t::to_zero(tmp2, 256);
	char tmp3[256]; _t::to_zero(tmp3, 265);
	
	std::cout << "Please input the desired numbers separated by commas ',': ";
	std::cin >> tmp; 
	
	tmp[_t::length(tmp)] = '\0';
	tmp[_t::length(tmp)-1] = '\0';
	
	for(int i = 0, k = 0; i <= _t::length(tmp); i++)
	{
		if(tmp[i] >= 48 && tmp[i] <= 57)
		{
			tmp2[k] = tmp2[k] * 10 + tmp[i]-'0';}
		else if(tmp[i] == ',')
			k++;
	}
	
	_t::to_string(tmp2, tmp3);
	_t::cout(tmp3);

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
					<< "(3) Convert string to ASCII code\n"
					<< "(4) Convert ASCII string to string\n";
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
			
			case 4:
			{
				_4();
				break;
			};
			
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