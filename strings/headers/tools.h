#ifndef TOOLS_H
#define TOOLS_H

namespace _t 
{
	/*
	 *	Get string's length
	 */
	int length(char []);
	int length(int []);

	int length(char v[])
	{
		int length = 0;
		
		for(int i = 0; i >= 0; i++)
		{
			if(v[i] == '\0')
				break;
			else
				length++;
		}
		
		return ++length;
	}
	
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
		
		return ++length;
	}
	/* ***************** */
	
	/*
	 *	Convert string to ASCII code
	 *
	 *	@return pointer of type 'int'
	 */
	void to_ascii(char a[], int b[])
	{
		int length = _t::length(a);
		
		for(int i = 0; i <= length; i++)
			b[i] = (int)a[i];
	}
	
	/*
	 *	Copy one ASCII string in another. It can be of type 'int' or 'char'
	 */
	void copy(int [], int []);
	void copy(char [], char []);
	void copy(char [], char []);
	
	void copy(int a[], int b[])
	{
		int length = _t::length(a);
		
		for(int i = 0; i <= length; i++)
			b[i] = a[i];
		
		return;
	}
	
	void copy(char a[], char b[])
	{
		int length = _t::length(a);
		
		for(int i = 0; i <= length; i++)
			b[i] = a[i];
		
		return;
	}
	
	void copy(char a[], int b[])
	{
		int length = _t::length(a);
		
		for(int i = 0; i <= length; i++)
			b[i] = (int)a[i];
		
		return;
	}
	/* ***************** */
	
	/*
	 *	std::cout << string
	 */
	void cout(int []);
	void cout(char []);
	
	void cout(int v[])
	{
		int length = _t::length(v);
		
		for(int i = 0; i < length; i++)
			std::cout << v[i] << ' ';
		
		return;
	}
	
	void cout(char v[])
	{
		int length = _t::length(v);
		
		for(int i = 0; i < length; i++)
			std::cout << v[i] << ' ';
		
		return;
	}
	/* ***************** */
	
};

#endif /* TOOLS_H */

