#include <iostream>

using namespace std;

void printArray(int* arr,int n = 0){
    for(size_t i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << std::endl;
}

int getMax(int arr[], int n){
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void countSort(int arr[], int n, int exp){
    int output[n], i, count[10] = {0};
    
    // Count the number of times each digit occurred at (exp)th place in every input.
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
    
    // Calculating their cumulative count.
    for (i = 1; i < 10; i++)
        count[i] += count[i-1];
    
    // Inserting values according to the digit '(arr[i] / exp) % 10' fetched into count[(arr[i] / exp) % 10].
    for (i = n - 1; i >= 0; i--){
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

// Sort arr[] of size n using Radix Sort.
void radixsort(int arr[], int n){
    int exp, m;
    m = getMax(arr, n);
    
    // Calling countSort() for digit at (exp)th place in every input.
    for (exp = 1; m/exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

int main()
{
    int a[] = {1, 34, 123, 321, 421, 432, 132, 543, 651, 91, 32, 987, 910, 643, 641,
        12, 342, 498, 987, 965, 122, 121, 431, 350
    };
    const int n = sizeof(a)/sizeof(a[0]);
    
    printArray(a,n);
    radixsort(a, n);
    printArray(a,n);
    return 0;
}
