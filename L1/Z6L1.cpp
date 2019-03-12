#include <iostream>

using namespace std;

struct pairr{
    int min;
    int max;
};

pairr maxmin(int array[], int n){
    pairr result;
    int i;

    if (n%2 == 0){
        if (array[0]>array[1]){
            result.max = array[0];
            result.min = array[1];
        }
        else{
            result.max = array[1];
            result.min = array[0];
        }
        i=2;
    }
    else{
        result.min = array[0];
        result.max = array[0];
        i=1;
    }
    
    while (i < n-1){
        if (array[i] >array[i+1]){
            if(array[i] > result.max)        
                result.max = array[i];
            if(array[i+1] < result.min)          
                result.min = array[i+1];        
        } 
        else{
            if (array[i+1] > result.max)        
                result.max = array[i+1];
            if (array[i] < result.min)          
                result.min = array[i];        
        }        
        i += 2;
    }
    return result;
}

int main(){
    int array[] = {20,12,6,7,5,23};
    pairr result = maxmin(array, 6);
    cout << "minimum: " << result.min << " maximum: " << result.max << endl;
    return 0;
}
