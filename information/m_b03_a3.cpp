#include<iostream>

using namespace std;

int quer(int n){
    int sum=0,pro=1;
    while(n!=0){
        if(n>=10){
            sum += n%10;
            pro *= n%10;
        }
        else{
           sum += n;
           pro *= n;
        }

        n = n/10;
    }


    return sum+pro;
}

int main(){
    int k;
    for(int i=1; i<=100; i++){
        k=quer(i);
        if(i==k){
            cout<< i<<endl;
        }
    }
    return 0;

}
