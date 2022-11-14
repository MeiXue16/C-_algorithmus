#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    double a,b,c,p,q,delta,x1,x2;
    cout<<"koeffizienten geben: a=";
    cin>>a;

    cout<<"b=";
    cin>>b;

    cout<<"c=";
    cin>>c;

    p=b/a;
    q=c/a;
    delta=p*p-4*q;
    cout<<"die Koeffizienten der Normalform: p= "<< p<< " q= "<< q <<"\ndelta="<<delta<<endl;

    if(delta<0){
       cout<<"keine Loesung!"<<endl;
    }
    else if(delta == 0){
             x1=-p/2;
        cout<<"Es gibt eine Loesung: x1=x2="<< x1<<endl;
    }
   else {
    x1=(-p+sqrt(delta))/2;
    x2=(-p-sqrt(delta))/2;
     cout<<"Es gibt zwei Loesungen:\nx1= "<< x1<< "\n x2= "<< x2<<endl;
   }
    return 0;
}
