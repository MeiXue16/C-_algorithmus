#include<iostream>
#include<cmath>

using namespace std;

void binom(int m){
    int n= m*2+1;
    int a[m+1][n];
     for(int i=0; i<m+1; i++){
        for(int j=0; j<n; j++){
            a[i][j]=0;
        }
     }
    for(int i=0; i<m+1; i++){
        a[i][m-i]=1;
        a[i][m+i]=1;
    }
    for(int i=2; i<m+1; i++){
        for(int j=2; j<n-1; j++){
            a[i][j]=a[i-1][j-1]+a[i-1][j+1];
        }
    }
    for(int i=0; i<m+1; i++){
        for(int j=0; j<n; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
}
int main(){
    int m;
    cout<<"m = ";
    cin>>m;
    binom(m);
    return 0;
}
