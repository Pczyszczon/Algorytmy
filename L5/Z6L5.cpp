#include <iostream>

inline int partition (int n, int t[]){
  int k = -1;
  double x = t[n / 2];
  while (true){
      while (t[--n] > x);
      while (t[++k] < x);
      if (n > k){
          double y = t[k];
        t[k] = t[n];
        t[n] = y;
      }
      else
	    return k;
    }
}

int kty(int t[], int n, int k){
    if(n == 1 && k == 1)
        return t[0];

    int p = partition(n, t);
    if(p >= k)
        return kty(t, p, k);
    else
        return kty(t+p, n-p,  k-p);
}

int main(){
    int a[] = {5, 7, 3, 1};
    const int n = sizeof(a)/sizeof(a[0]);
    std::cout << kty(a, n, 1) << std::endl;
    std::cout << kty(a, n, 2) << std::endl;
    std::cout << kty(a, n, 3) << std::endl;
    std::cout << kty(a, n, 4) << std::endl;
}
