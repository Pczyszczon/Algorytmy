#include <iostream>
#include <cmath>
#include <vector>

using namespace std;



int main(){
    int x,k, cyfra,licznik;
    cyfra=licznik=0;
    vector<int> vec;
    cout << "wprowadz liczbe" << endl;
    cin >> x;
    // a)
    int n_digits = floor(log10(x)+1);
    cout << "ilość cyfr: " << n_digits << endl;
    
    cout << "która od końca? (od 0) " << endl;
    cin >> k;
    
    do{
        cyfra = x%10;
        vec.push_back(cyfra);
        x/=10;
    }while(x!=0);
    
    // b)
    cout << vec[k] << endl;
    return 0;
}
