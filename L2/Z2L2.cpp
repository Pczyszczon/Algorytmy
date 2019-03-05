#include <iostream>
#include <cstdlib>

using namespace std;

// n porównań, 
int maximum(int t[], int n){
    int x = t[--n];
    while (n--)
        if (t[n]>x) x=t[n];

    return x;
}

// O(2n+1)
int maximum_recursive(int t[], int n){
    if (n == 1)
        return t[0];
    int x = maks_r(t, n-1);
    if (t[n-1] > x)
        return t[n-1];
    return x;
}

// O(logn)
int maximum_recursive_2(int t[], int l, int r){
    if (r-l==1)  return t[l];
    int m=(l+r)/2;
    int u = maks_r2(t,l,m);
    int v = maks_r2(t,m,r);
    return u>v?u:v;
}



int main(){
    srand (time(NULL));
    const int N = 20;
    int array[N];
    
    for(int i=0;i<N;i++)
        array[i]= rand()%200+1;

    cout << maximum(array,N) << endl;
    cout << maximum_recursive(array,N) << endl;
    cout << maximum_recursive_2(array,0,N) << endl;
    return 0;
}
