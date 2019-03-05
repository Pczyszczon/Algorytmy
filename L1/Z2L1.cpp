#include <cmath>
#include <iostream>

using namespace std;
double epsilon = 0.01;

double f(double x){
    return x*x-2*x;
}

double zero(double a, double b){
    double fa = f(a);
    double fb = f(b);
    double x0 = (a+b)/2;
    if (fa * fb > 0)
        return false;
    while (x0!=a || x0!=b){
        x0 = (a+b)/2;
        double f0 = f(x0);

        if (abs(f0) < epsilon)
            break;
        if (fa*f0 < 0)
            b = x0;
        else{
            a = x0;
            fa = f0;
        }
    }
    return x0;
}

int main(){
    cout << zero(0.12, 4.23) << endl;
    cout << zero(0.5, 10.121) << endl;
    cout << zero(1.12, 4.23) << endl;
    cout << zero(1.2136, 10.121) << endl;
    return 0;
}
