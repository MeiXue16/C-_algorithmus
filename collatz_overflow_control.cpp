#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int collatz_length( long long n ){
  // to do: Länge der Collatz Folge berechnen und zurückgeben
  // rekursion: 递归。 无法捕获序列元素溢出时，对应的起始值。
  if (n == 1){
    return 1;
  }
  if (n % 2 ==1){
    return 2 + collatz_length( (3*n+1) /2  ); 
  }
  else {
    return 1 + collatz_length(n/2); 
  }
}


int main(){
  
  int n_star = 1, max_length = 0;
  for (int n =1; n<= 1000000; n++){
    //只能捕获起始值的溢出
    try{
        if (n <= (SHRT_MAX-1) / 3 ){
            int tmp = collatz_length(n);
            if (tmp > max_length){ 
            max_length = tmp;
            n_star = n;
            }
        }
        else{
            throw (n);
        }
    }
    catch(int num){
        cout << "Bei Zahl " << num << " genuegt der Datentyp short erstmals nicht mehr." << endl ;
        break;
    }
  }    
  cout <<"In " << n_star << " beginnenden Collatz-Folge hat maximal Laenge: " << max_length << endl ;
  return 0;
 
}
