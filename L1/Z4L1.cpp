#include <iostream>
#include <cmath>

using namespace std;

double P(int k, int n, double p){
    double q = 1-p; 
    double p_q = p/q;
    double bit = pow(q,n);
    double result = bit;

    for (int i=1; i<k; ++i){
        bit *= ((n+1-i)*p_q)/i;
        result += bit;
    }
    return result;
}


int main(){
    cout << P(10, 20, 0.75) << endl;
    return 0;
}
