namespace String
{
    char* Explode(const char* delim, const char* string) 
    {
        unsigned short int len_delim = Misc::len(delim);
        unsigned short int len_string = Misc::len(string);
        char tmp[len_string][len_string];
        
        for(short int i = 0; i < len_string; i++)
        {
            for(short int j = 0; j < len_string; j++)
                tmp[i][j] = 0;    
        }
        
        short int count = 0;
        short int track = 0;
        for(short int i = 0; i < len_string; i++)
        {
            if(count != 0)
            {  
                --count;
                continue;
            }
            
            for(short int j = 0; j < (len_delim - 1); j++)
            {
                if(string[i+j] == delim[j])
                    ++count;
                else
                    --count;
            }
            
            if(count == (len_delim - 1))
            {
                for(short int j = track, k = 0; j < i; j++, k++)
                {
                    tmp[i][k] = string[j];
                    
                	std::cout << "string[" << j << "]: " << string[j] << '\n';
                	std::cout << "tmp[" << i << "][" << j << "]: " << tmp[i][j] << '\n';
                }
                
                track = i + count;
            }
            else
                count = 0;
        }
        
        //for(short int i = track, k = 0; i < len_string; i++, k++)
          //  tmp[(len_string - 1)][k] = string[i];
            
        /*count = 1;
        for(short int i = 0, k = 0; i < len_string; i++)
        {
            if(tmp[i][0] != 0)
                ++count;
        }

        char (*tmp_array)[64] = new char[count+1][64];
        for(short int i = 0; i < count; i++)
        {
            for(short int j = 0; j < len_string; j++)
                tmp_array[i][j] = 0;
        }
        
        for(short int i = 0, k = 0; i < len_string; i++)
        {
            if(tmp[i][0] != 0)
            {
                Misc::concat(tmp_array[k], tmp[i]);
                ++k;
            }
        }*/
        
        for(short int i = 0; i < len_string; i++)
        {
			if(tmp[i][0] != 0)
            	std::cout << tmp[i] << '\n';
        }
        
        //std::cout << tmp[11][2];
    }   
}
