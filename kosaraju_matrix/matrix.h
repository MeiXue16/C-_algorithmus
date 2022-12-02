// matrix.h (Declaration of Class Matrix)

#include<iostream>
#include<fstream>
#include<vector>

using entry_type = int;


class Matrix
{

public:
   Matrix(int num_rows,
          int num_columns,
          entry_type init_value);

   void print();
   int num_rows();
   int num_columns();
   void set_entry(int row_idx, int column_idx, entry_type entry);


   std::vector< std::vector<entry_type> > _entries;
};

Matrix ReadInMatrix(char * arg);

