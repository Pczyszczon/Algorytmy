#include <iostream>
#include <vector>

using namespace std;

// wykonujemy ilość mnożeń równą stopniu wielomianu n

double horner(double factors[], int n,  double x){
    double result = factors[0];
    for (int i=1; i<=n - 1; i++)
        result = result * x + factors[i];

    return result;
}

int main(){
    const int n = 5;
    double factors[n] = {4, 2, 3, 0, 1};
    cout << horner(factors, n, 2) << endl;

    return 0;
}
