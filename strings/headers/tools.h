#ifndef TOOLS_H
#define TOOLS_H

namespace _t 
{
	int length(char []);
	int length(int []);
	
	int chr(char);
	char chr(int);
	
	void copy(int [], int []);
	void copy(char [], char []);
	void copy(char [], char []);
	
	void to_ascii(char [], int []);
	void to_string(int [], char []);
	
	void cout(int []);
	void cout(char []);
	
	void to_zero(char [], int);
	void to_zero(int [], int);

	/*
	 *	Get string's length
	 */	
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
	 */
	void to_ascii(char a[], int b[])
	{
		int length = _t::length(a);
		
		for(int i = 0; i <= length; i++)
			b[i] = (int)a[i];
		
		return;
	}
	
	/*
	 *	Convert ASCII code to string
	 */
	void to_string(int a[], char b[])
	{
		int length = _t::length(a);
		
		for(int i = 0; i <= length; i++)
			b[i] = a[i];
		
		return;
	}
	
	/*
	 *	Copy one ASCII string in another. It can be of type 'int' or 'char'
	 */
	void copy(int a[], int b[])
	{
		int length = _t::length(a);
		
		for(int i = 0; i <= length; i++)
			b[i] = (char)a[i];
		
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
	
	/*
	 *	Swap between char and ASCII code
	 */
	int chr(char a)
	{
		return (int)a;
	}
	
	char chr(int a)
	{
		return (char)a;
	}
	
	/*
	 *	Set all array's items to 0
	 */
	void to_zero(char v[], int size)
	{
		for(int i = 0; i < size; i++)
			v[i] = (char)('\0');
	}
	
	void to_zero(int v[], int size)
	{
		for(int i = 0; i < size; i++)
			v[i] = 0;
	}
	
};

#endif /* TOOLS_H */

