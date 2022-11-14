#include<string>
#include<iostream>
using namespace std;
void entschluss(string &s){
    string re;
    for(int i=0; i<s.length()&& s[i]!=' '; i++){
        if(s[i]=='('&& s[i+1]=='a'&&s[i+2]=='t'&&s[i+3]==')'){
            re+='@';
            i=i+3;
        }
        else if(s[i]=='('&& s[i+1]=='d'&&s[i+2]=='o'&&s[i+3]=='t'&&s[i+4]==')'){
            re+='.';
            i=i+4;
        }
        else if(s[i]=='('&& s[i+1]=='m'&&s[i+2]=='i'&&s[i+3]=='n'&&s[i+4]=='u'&&s[i+5]=='s'&&s[i+6]==')'){
            re+='-';
            i=i+6;
        }
        else
            re+=s[i];
    }
    cout<< re <<endl;
}
int main(){
    string s;
    cin>>s;
    entschluss(s);
}

