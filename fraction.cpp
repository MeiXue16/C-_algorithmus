#include <stdexcept>
#include <cmath>
#include <iostream>
#include<algorithm>

using namespace std;

class Fraction {
    //access specifier
    public:
        using inttype =long long;
        
        //constructor
        //初始化_numerator和_denominator，将参数n传递给_numerator，参数d传递给_denominator
        Fraction(inttype n, inttype d): _numerator(n), _denominator(d){
            if (d <1){ error_zero();}
        }

        // overload constructor
        Fraction(double k):frac(k){
            // 求k的小数点后的值num，z.B. k= -3.567 => num = 0.567
            inttype k_int = static_cast<inttype>(k), count = 0, den , num_int= 0; 
            double num, num2;
            
            if (k<0) {
                num = k_int -k;
            }
            else{
                num = k - k_int;
            }
            num2 = num ;
            // 当 num <0.01, 直接输出整数部分k_int
            if ( num < 0.01 && num >=0.005){
                cout << "fraction der double variable "<< k << " ist " << "1/100" << endl ;
            }
            else if (num < 0.005){
                cout << "fraction der double variable "<< k << " ist " << 0 << endl ;
            }
            else{
                // 求小数位数， 这部分很容易overflow溢出, 因为double类型的值例如：3.14，double的表示为 3.140000000000000124
                double tmp = num ;
                while (tmp != 0 && count <=16){
                    num *= 10 ;
                    tmp = num - static_cast<inttype>(num);
                    count +=1 ;
                }
                //将小数部分转换为 num_int / den 的分数形式
                den = pow(10, count) ;
                num_int = num ;
                // cout << "den=" << den << ", num = "<< num_int << endl; 

                // simplify num_int / den
                simplify(den, num_int);
                // cout << "den=" << den << ", num = "<< num_int << endl; 

                // 限制分母最大为100
                if (den <=100){
                    cout << "fraction der double variable "<< k << " ist "<< k_int * den + (k>0 ? num_int : -num_int) <<'/' << den << endl  ;
                }
                else{
                    while( den >100 ){                                               
                            if (num_int % 2 == 0){
                                if (diff_d(num2, num_int, den)){
                                    den += 1 ;
                                }
                                else{den -= 1 ; }                                 
                            }
                            else{
                                if (diff(num2, num_int, den)){
                                    num_int += 1 ;
                                }
                                else{num_int -= 1 ; }                               
                            }
                            // cout << "den=" << den << ", num = "<< num_int << endl; 
                            simplify(den, num_int);
                            // cout << "den=" << den << ", num = "<< num_int << endl;      
                    }
                    cout << "fraction der double variable "<< k << " ist "<< k_int * den + (k>0 ? num_int : -num_int) <<'/' << den << endl ;
                }
            }   
        }

        void simplify(inttype &d, inttype &n){
                inttype common =__gcd(d, n);
                d = d/common ;
                n = n/common ;
        }

        bool diff_d(double num, inttype n,inttype d){
            bool a = fabs( num- static_cast<double>(n )/(d+1) ) < fabs( num- static_cast<double>(n)/ (d-1) );
            return a ;
        }

        bool diff(double num, inttype n,inttype d){
            bool a = fabs( num- static_cast<double>(n+1)/d ) < fabs( num- static_cast<double>(n -1)/d );
            return a ;
        }

        inttype numerator() const{
            return _numerator ;
        }
        inttype denominator() const{
            return _denominator ;
        }

        // method/ function defined inside the class
        // replaces n/d by d/n
        void reciprocal(){
            if (numerator()== 0){
                error_zero();
            }
            else{
                // 交换分子和分母
                std::swap(_numerator, _denominator);
                if (denominator() < 0){
                    _numerator = -_numerator ;
                    _denominator = -_denominator ;
                }
            }
        }

        // overload 重载运算符 <
        bool operator < (const Fraction & x) const{
            // 返回一个bool值，判断 n* d_x < n_x * d 为 true/false
            // d_x 指 x的分母， n_x 指 x的分子, n_x/ d_x = x (实际上就是判断 n/d < x)
            return numerator()* x.denominator() < x.numerator() *denominator();
        }

        // overload 重载运算符 +
        Fraction operator +(const Fraction & x) const{
            // 重载加法运算符， 计算 n/d + n_x/ d_x 
            // 返回构造器， 参数n为 n* d_x + n_x * d, 参数d为 d * d_x
            return Fraction(numerator() * x.denominator() + x.numerator( )* denominator() , 
                            denominator() * x.denominator()) ;
        }
    
    private: 
        //私有属性
        inttype _numerator ;
        inttype _denominator ;
        double frac ;
        
        //私有方法
        void error_zero(){
            // 抛出异常
            throw runtime_error("Denominator < 1 not allowed in Fraction .");
        }
};


int main(){
    
    Fraction frac1(3.14);
    Fraction frac2(33.14578);
    Fraction frac3(50.337891123);
    Fraction frac4(-50.337891123);
    Fraction frac5(0.048048048048);
    Fraction frac6(3.175);
    return 0;
}