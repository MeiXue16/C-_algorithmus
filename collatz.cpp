#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int collatz_length( long long n ){
  // to do: Länge der Collatz Folge berechnen und zurückgeben
  // rekursion: 
  if (n == 1){
    return 1;
  }
  if (n % 2 ==1){
    return 2 + collatz_length( (3*n+1) / 2 ); 
  }
  else {
    return 1 + collatz_length(n/2); 
  }
}

int main(){
  
  int n_star = 1, max_length = 0;
  for (int n =1; n<= 1000000; n++){
    int tmp = collatz_length(n);
    if (tmp > max_length){ 
      max_length = tmp;
      n_star = n;
    }
  }
      
  cout <<"in " << n_star << " beginnenden Collatz-Folge hat maximal Laenge: " << max_length << endl ;
  return 0;
 
}


