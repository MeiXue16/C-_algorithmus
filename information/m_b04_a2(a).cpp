#include<string>
#include<iostream>
using namespace std;
void verschluss(string &s){
    string re;
    for(int i=0; i<s.length()&& s[i]!=' '; i++){
        if(s[i]=='@') re+= "(at)";
        else if(s[i]=='.') re+="(dot)";
        else if(s[i]=='-') re+="(minus)";
        else re+=s[i];
    }
    cout<< re <<endl;
}

int main(){
    string s;
    cin>>s;
    verschluss(s);
}
