#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double cubic_wurzel(int n){
    if (n == 0 || n == 1) return n;
    double low = 1, high = n ;
    double middle; 
    
    while ( high - low > 1e-15 ){
        middle = (low + high)/ 2; 
        if (pow(middle, 3) < n ){
            low = middle;
        }
        else {
            high = middle ;
        } 
    }
    return middle ;
}

int main()
{
    int n;
    cout << "ein natuerliche Zahl eingeben: ";
    cin >> n ;
    double kubikwurzel = cubic_wurzel(n) ; 
    cout << "Kubikwurzel von "<< n << " ist " ;                                                        
    cout << fixed << setprecision(16) << kubikwurzel;             
    return 0; 
}