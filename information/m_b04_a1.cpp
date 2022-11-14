#include<vector>
#include<iostream>
using namespace std;
int left(int n){
    int le;
    le = n/10;
    return le;
}
int right(int n){
    int r;
    r = n%10;
    return r;
}
bool Valid(int n){
    bool f;
    if(n>=0 && n<=6) f = true;
    else
        f = false;
    return f;
}
bool Valid(vector<int> v){
    bool f = true;
    for(int i=0; i < v.size()-1; i++){
        if(right(v[i]) != left(v[i+1])){
            f = false;
        }
    }
    return f;
}
void enterVector(vector<int> &v){
    for(int i=0; i< v.size(); i++){
        cout<<"Dominostein"<< i+1 << ":" ;
        cin>>v[i];
    }
}
void printVector( vector<int> &v){
     for(int i=0; i< v.size(); i++){
        cout<< v[i]<<" ";
     }
     cout<< endl;
}
int main(){
    vector<int> v(4);
    enterVector(v);
    bool k = Valid(v);
    int j=0;
    while(Valid(right(v[j]))==true || Valid(left(v[j]))==true){
        j+=1;
    }
    if(j== v.size()) cout<<"kein ungueltiger Wert. :)\n";

    for(int i=0; i< v.size(); i++){
          if(Valid(right(v[i]))==false || Valid(left(v[i]))==false){
            cout<<v[i]<<"ist ungueltiger Wert.\n";
          }
    }

    if(k ==true)
        cout<<"immer gleiche Punktzahlen nebeneinander liegen. :)\n";
    else
        cout<<"Es gibt ungleiche Punktzahlen nebeneinander liegen. :(\n";
    if(j== v.size() && k ==true)
        printVector(v);
}



