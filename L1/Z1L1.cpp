#include <iostream>

using namespace std;

double power(int x, int n){
    double result = 1;
    if (n<0) return 1/power(x,-n);
    while (n > 0){
        if (n%2 == 0){
            x = x*x;
            n = n/2;
        }
        else{
            result = result*x;
            n--;
        }
    }
    return result;
}

double power_recursion(int x, int n){
    if (n<0) return 1/power_recursion(x,-n);
    else if (n==0) return 1;
    else if (n==1) return x;
    else if (n%2==0) return power_recursion(x*x,n/2);
    else if (n%2==1) return x*power_recursion(x*x, (n-1)/2);
}


int main(){
    cout << "Iterative - Recursion" << endl;
    cout << power(2,2) << " - " << power_recursion(2,2) << endl;
    cout << power(6,1) << " - " << power_recursion(6,1) << endl;
    cout << power(5,3) << " - " << power_recursion(5,3) << endl;
    cout << power(2,-3) << " - " << power_recursion(2,-3) << endl;

    return 0;
}
