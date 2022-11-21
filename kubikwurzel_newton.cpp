#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double cubic_wurzel(double n, int *count_binar){
    *count_binar =0;
    if (n == 0 || n == 1)  return n ;
    else{
        double low = 1, high = n ;
        double middle;        
        while ( high - low > 1e-10 ){
            middle = (low + high)/ 2; 
            if (pow(middle, 3) < n ){
                low = middle;
            }
            else {
                high = middle ;
            }
            *count_binar += 1 ;     
        }
        return middle;    
    }
}

double newton_1(double n, int *count){
    *count =0 ;
    double x = 1.0 ;
    while (std::abs(x*x*x - n) > 1e-10)
    {
        x = (2*x + (n/ (x*x)))/3 ;
        *count +=1 ;
    }
    return x ;
}

double newton_2(double n, int *count){
    *count =0 ;
    double x = 1.0 ;
    while (std::abs(1- n/(x*x*x)) > 1e-10 )
    {
        x = x - (1- n * std::pow(x, -3))/(3 * n * std::pow(x, -4));
        *count +=1 ;
    }
    return x;   
}

void out(int n, int count, double (* func)(double n ,int *count)){
    double kubikwurzel = func(n, &count) ;  
    cout << "Kubikwurzel von " << n <<" = " ;
    cout << fixed << setprecision(16) << kubikwurzel << ", " ;
    cout << "Anzahl der Iteration = " << count << endl;  

}

int main(int argc, char *argv[])
{
    int n, count;
    cout << "ein natuerliche Zahl eingeben: ";
    cin >> n ;
    out(n , count, cubic_wurzel) ;
    out(n , count, newton_1)  ;  
    out(n , count, newton_2) ;
    return 0; 
}
