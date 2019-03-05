// O(Log n)

#include <iostream>

using namespace std;

int search(int array[], int left_item_index, int right_item_index, int x){
    while (left_item_index <= right_item_index){
        int middle_item_index = left_item_index + (right_item_index - left_item_index)/2;
 
        if (array[middle_item_index] == x)
            return middle_item_index;
 
        if (array[middle_item_index] < x)
            left_item_index = middle_item_index + 1;
         else
            right_item_index = middle_item_index - 1;
    }
 
    return -1;
}

int main(){
    int array[10] = {1, 2, 3, 4, 5, 6, 7};
    cout << search(array, 0, 6, 6) << endl;
    return 0;
}
 
