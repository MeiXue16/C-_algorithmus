// readmatrix.cpp (read an integer matrix from a file and output it via cout)

#include<iostream>
#include"matrix.h"

int main (int count, char ** args)
{
    if(count != 2)
    {
        std::cout << "Please enter only one filename." << std::endl;
        return 1;    
    }

    Matrix matrix = ReadInMatrix(args[1]);

    matrix.print();  
     
    return 0;
}
 
