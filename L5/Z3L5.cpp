#include <iostream>
#include <math.h>

using namespace std;

void printArray(int* arr,int n = 0){
    for(size_t i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << std::endl;
}

void counting_sort(int t[], int n, int c){
    int output[n];
    int i, count[10] = {0};
    int exp = pow(10,c);

    // liczenie wystąpień
    for (i = 0; i < n; i++)
        count[ (t[i]/exp)%10 ]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // zapełnianie output
    for (i = n - 1; i >= 0; i--){
        output[count[ (t[i]/exp)%10 ] - 1] = t[i];
        count[ (t[i]/exp)%10 ]--;
    }

    // final
    for (i = 0; i < n; i++)
        t[i] = output[i];
}

int main(){
    int t[] = {91,82,73,64,55,46,38,77,69,50};
    int n = sizeof(t)/sizeof(*t);
    printArray(t,n);
    counting_sort(t,n,1);
    printArray(t,n);
    return 0;
}
