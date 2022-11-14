#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int collatz_length( long long n ){
  // to do: Länge der Collatz Folge berechnen und zurückgeben
  // while loop 
  long long n_init = n;
  int k =1;
  while (n != 1 ){
    if (n >(SHRT_MAX-1) / 3){
      throw (n_init);
    }
    else{
      if (n % 2 ==1){
        n = 3 * n + 1 ;
        k += 1 ;
      }
      else{
        n = n/2;
        k += 1 ;
      }
    }
  }
  return k;  
}


int main(){
  int n_star = 1, max_length = 0;
  try{
    for (int n =1; n<= 1000000; n++){
      if (n > (SHRT_MAX-1) / 3 ){
        throw (n);
      }
      else{
        int tmp = collatz_length(n);
        if (tmp > max_length){ 
          max_length = tmp;
          n_star = n;
        }
      }
    } 
  }
  catch(long long num){
    cout << "Bei Zahl " << num << " genuegt der Datentyp short erstmals nicht mehr." << endl ;
  } 
  cout <<"In " << n_star << " beginnenden Collatz-Folge hat maximal Laenge: " << max_length << endl ;
  return 0;
 
}


