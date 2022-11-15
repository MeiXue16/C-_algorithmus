#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double cubic_wurzel(int n, int precision){
    if (n == 0 || n == 1) return n;
    double low = 1, high = n ;
    double middle = (low + high)/ 2; 
    double epsilon = pow(10, -precision) ;
    // 当 (估计值的三次方 - 实际值)的绝对值 > 10^(-16)
    while ( abs(pow(middle, 3) - n) >= epsilon ){
        if (pow(middle, 3) < n ){
            low = middle;
        }
        else {
            high = middle ;
        }
        middle = (low + high)/ 2; 
    }
    return middle ;
}

int main()
{
    int n, pre ;
    cout << "ein natuerliche Zahl eingeben: ";
    cin >> n ;
    cout << "precision geben: ";
    cin >> pre ;
    double kubikwurzel = cubic_wurzel(n, pre) ; 
    cout << "Kubikwurzel von "<< n << " ist " ;                                                        
    cout << fixed << setprecision(pre) << kubikwurzel;             
    return 0; 
}