#ifndef TOOLS_H
#define TOOLS_H

namespace _t
{
	/*  Get list's length until '0' is reached
	 *  List is of type 'int'
	 *  Param: (list)
	 */
	int length(int v[])
	{
		int length = 0;

		for(int i = 0; i >= 0; i++)
		{
			if(v[i] == 0)
				break;
			else
				length++;
		}

		return length;
	}
    
	/*
	 *	Sort a list
	 *	Param: (list, asc/desc)
	 */
	void sort(int v[], bool asc = true)
	{
		int length = _t::length(v);
		int aux = 0;

		if(asc == true)
		{
			for(int i = 0; i < length-1; i++)
			{
				for(int j = i+1; j < length; j++)
				{
					if(v[i] > v[j])
					{
						aux = v[i];
						v[i] = v[j];
						v[j] = aux;
					}
				}
			}
		}
		else
		{
			for(int i = length; i > 0; i--)
			{
				for(int j = i-1; j >= 0; j--)
				{
					if(v[i] > v[j])
					{
						aux = v[i];
						v[i] = v[j];
						v[j] = aux;
					}
				}
			}
		}
	}
	
	/*
	 *	std::cin >> list
	 */
	void cin(int v[], int &length)
	{
		for(int i = 0; i < length-1; i++)
			std::cin >> v[i];
		
		v[length-1] = 0;
	}
	
	/*
	 *	Nullify list
	 */
	void nullify(int v[], int &length)
	{
		for(int i = 0; i < length-1; i++)
			v[i] = 1;
		
		v[length-1] = 0;
	}
	
	/*
	 *	std::cout >> list
	 */
	void cout(int v[])
	{
		int length = _t::length(v);
		
		for(int i = 0; i < length; i++)
			std::cout << v[i] << ' ';
	}

};

#endif /* TOOLS_H */

