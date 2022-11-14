#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Box {
public:
    // Default constructor
    Box() {}

    // 构造函数可以被声明为 inline, explicit, friend, or constexpr.
    // Initialize a Box with equal dimensions (i.e. a cube)
    explicit Box(int i) : m_width(i), m_length(i), m_height(i) // member init list
    {   int n =13;
        if (i>3){
            cout << i + n << endl ;
        }
        else{
            cout << i*n << endl ;
        }
            
    }

    // overload 重载constructor
    // Initialize a Box with custom dimensions
    Box(int width, int length, int height)
        : m_width(width), m_length(length), m_height(height)
    {}

    int Volume() { return m_width * m_length * m_height; }

private:
    // Will have value of 0 when default constructor is called.
    // If we didn't zero-init here, default constructor would
    // leave them uninitialized with garbage values.
    int m_width{ 0 };
    int m_length{ 0 };
    int m_height{ 0 };
};

int main(){
    Box box0 ;
    Box box1(3);
    Box box2{ 2, 3, 4 };
    Box box3( 2, 3, 4 );
    // Box box3; // C2512: no appropriate default constructor available
    cout << "box0.Volume: " << box0.Volume() << endl;
    cout << "box1.Volume: " << box1.Volume() << endl;
    cout << "box2.Volume: " << box2.Volume() << endl;  
    cout << "box3.Volume: " << box3.Volume() << endl; 
    cout << DBL_MAX; 
    return 0;
}
