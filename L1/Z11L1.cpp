#include <iostream>
#include <math.h>

using namespace std;

void sito_erastotenesa(bool prime[], int n){
    prime[0] = prime[1] = false;
    for(int i = 2; pow(i,2) < n; ++i){
        if(prime[i]){
            for(int j = i*2; j < n; j +=i)
                prime[j] = false;
        }
    }
}

int main(){
    const int n = 20;
    bool primes[n+1] = {};
    memset(primes, true, sizeof(primes));
    sito_erastotenesa(primes, n);

    for (int i=0; i<n; i++)
        if(primes[i]) cout << i << endl;

    return 0;
}
