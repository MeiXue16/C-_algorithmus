// matrix.cpp (Implementation of Class Matrix, for storing a matrix whose entries are integers.)

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include "matrix.h"
#include <stack>
#include <string.h>
#include <bits/stdc++.h>

using namespace std;
Matrix::Matrix(int num_rows,
               int num_columns,
               entry_type init_value):
_entries(num_rows, std::vector<int>(num_columns, init_value)) {}

void Matrix::print()
{
   std::cout << "A " << num_rows() << " x " << num_columns() << "-matrix:" <<std::endl;
   for (int row_idx = 0; row_idx < num_rows(); ++row_idx)
   {
      for (int column_idx = 0; column_idx < num_columns(); ++column_idx)
      {
         std::cout << _entries[row_idx][column_idx] << " ";
      }
      std::cout << std::endl;
   }
}

int Matrix::num_rows()
{
   return _entries.size();
}

int Matrix::num_columns()
{
   if (_entries.size() == 0)
   {
      return 0;
   }
   return _entries[0].size();
}

void Matrix::set_entry(int row_idx, int column_idx, entry_type entry)
{
   if (row_idx >= 0 and row_idx < num_rows() and column_idx >= 0 and column_idx < num_columns()) 
   {  
      _entries[row_idx][column_idx] = entry; 
   }
   else
   { 
      throw std::runtime_error("Index outside range of matrix.");
   }
}

Matrix ReadInMatrix(char * arg)
{
   std::string filename = arg;

   std::ifstream file(filename);
   if (not file)
   {
      throw std::runtime_error("No Data found!");
   }
   std::string line;
   std::getline(file, line);

   int num_rows, num_columns;

   std::stringstream ss(line);

   ss >> num_rows >> num_columns;
   if (not ss)
   {
      throw std::runtime_error("Wrong format: no row and column number in the beginning!");
   }

   Matrix matrix(num_rows, num_columns, 0);

   int row_idx = 0, column_idx = 0;

   while (std::getline(file, line))
   {
      entry_type entry;
      std::stringstream ss(line);
      while (ss)
      {
         ss >> entry;
         if (ss) 
         {
            matrix.set_entry(row_idx,column_idx, entry);
            ++column_idx;
         }
      }
      if (column_idx != num_columns) { throw std::runtime_error("Row has wrong format.");};
      column_idx = 0;
      ++row_idx;
   }
   if (row_idx != num_rows) { throw std::runtime_error("Wrong number of rows.");};
 
   return matrix;
}






// int matrix[1024][1024], dfnum[1024], n, scc, count=0 ;
// int flag[1024] ;
// //从任意一个点开始深搜，得到图的一个最晚完成时间的排序
// void dfs(int cur){
//    flag[cur] =true ;
//    for(int i = 1; i <= n; i++){
//       // k->i kanten exsitieren und i nicht besucht wurden
//       if(matrix[cur][i] && !flag[i]){
//          dfs(i);
//       }
//    }
//    dfnum[++count] =cur ;
// }
// // 第二次深搜，从最晚完成的一个点开始搜索并染色
// void dfs2(int cur){
//    flag[cur] =1 ;
  
//    for(int i = 1; i <= n ; i++){
//       // Greifen Sie auf die symmetrische Matrix der ursprünglichen Matrix zu
//       if(matrix[i][cur] && !flag[i]){
//          dfs2(i);
         
//       }
//    }
// }

// void kosaraju(){
//    int i ,j ;
//    // first DFS search
//    memset(flag, 0, sizeof(flag));
//    for(i = 1; i<= n; i++){
//       if(!flag[i]){
//          dfs(i);
//       }
//    }
//    memset(flag, 0, sizeof(flag));
//    //second DFS
//    for(i= n; i>=1; i--){
      
//       if(!flag[dfnum[i]]){
//          scc++;
//          dfs2(dfnum[i]);
//          cout << dfnum[i] << ' ';
       
//       }
//    }
//    cout << endl << "found: "<< scc << endl ;
// }





const int MAXV = 1024;
int g[MAXV][MAXV], vis[MAXV], id[MAXV], n,  scc;

vector<int> S ;
// stack<int>S;
void dfs(int k)
{
   if(vis[k]) return ;
   vis[k] = 1;
   for(int i=0; i<n; ++i){
      if(g[k][i] && !vis[i])
         dfs(i);
   }
   S.push_back(k);
   // dfn[k] = cnt++ ;                 //记录第cnt个出栈的顶点为k 
}
void dfs2(int k)
{
   if(id[k]) return ;
   id[k] = scc;             //本次DFS染色的点，都属于同一个scc，用num数组做记录
   cout << k << "=>";
   for(int i=0; i<n; ++i)
      if(g[i][k] && !id[i]){              //注意我们访问的原矩阵的对称矩阵 
         dfs2(i);
      }
}
void kosaraju(int n)
{
   scc =0;
   S.clear();
   memset(id, 0x00, sizeof id);
   memset(vis, 0x00, sizeof vis);
   for(int i=0; i < n; ++i) {
      if(!vis[i] ){
         dfs(i);
      }
   }
             //DFS求得拓扑排序  
    /*    我们本需对原图的边反向，但由于我们使用邻接矩阵储存图，所以反向的图的邻接矩阵 
     即原图邻接矩阵的对角线对称矩阵，所以我们什么都不用做，只需访问对称矩阵即可*/ 
   for(int i=n-1; i>=0; --i){
      if(!id[S[i]]){           //按照拓扑序进行第二次DFS 
         scc++;     
         dfs2(S[i]);       
      }    
   }
   cout<<endl << "Found: "<<scc <<endl;
}


int main ()
{
   //  if(count != 2)
   //  {
   //      std::cout << "Please enter only one filename." << std::endl;
   //      return 1;    
   //  }

   Matrix matrix1 = ReadInMatrix("./Instanz_4");

   matrix1.print();  

   // cout << matrix.num_rows() << endl;

   // anzahl der vertex
   const int maxv = matrix1.num_rows();
   n = maxv ;
   for(int i =0 ; i< maxv; i++){
      for(int j= 0; j< maxv; j++){
         g[i][j] =matrix1._entries[i][j];
      }
   }
   
   kosaraju(n);

   return 0;
}