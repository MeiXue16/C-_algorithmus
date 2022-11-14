#include<iostream>

using namespace std;

int d2b(int n){
    int b = n%2;
    for(int i=10; n!=0; i*=10){
        n = n/2;
        b = b + (n%2)*i ;
    }
    return b;
}
int main(){
    int n,bi;
    cout<<"Geben eine Dezimalzahl ein: ";
    cin>> n;
    if(n<0) cout<<"keine Ergebnis!"<<endl;
    else{
        bi= d2b(n);
        cout<<"binaere Darstellung: "<< bi <<endl;
    }

    return 0;
}
