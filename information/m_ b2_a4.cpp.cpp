#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
    int ma,num,rat,i=1;
    cout<<"Maximum geben: ";
    cin>>ma;

    num = rand()%(ma+1);
    cout<< "eine ganze Zahl raten: ";
    cin>>rat;

    while(rat!=num)
    {

        if(rat> num){
            cout<<"die zu suchende Zahl < deine eingabe!"<<endl;
        }
        else {
            cout<<"die zu suchende Zahl > deine eingabe!"<<endl;
        }
        cout<< "eine ganze Zahl raten: ";
        cin>>rat;
        i = i+1;
    }
    cout<<"Herzliche Gl¨¹ckw¨¹nsche! Du hast es erraten!\n"<<"Anzahl der Versuche: "<<i<<endl;

    return 0;
}
