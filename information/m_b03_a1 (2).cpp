#include<iostream>
#include<cmath>

using namespace std;

double calcPi(double precision){
    double p=0;
    for(int n=0;(double)4/(2*n+1)>=precision;n++)
      {
          if (n%2==0) p=p+(double)4/(2*n+1);
          else p=p-(double)4/(2*n+1);
      }
      return p;
}

int main(){
    double precision, pi ,fehler;
    cout<<"Geben Sie die Genauigkeit ein: ";
    cin>> precision;
    pi= calcPi(precision);
    fehler = pi- M_PI;
    cout<<"der berechneten Wert: "<< pi << "\nder Fehler: "<< fehler<<endl;
    return 0;
}
