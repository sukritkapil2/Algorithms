/*
Implementation of Quick Sort in C++
Author - Sukrit Kapil
Date - 11 June 2020
*/

/*
Theory - 
1. A pointer is fixed at the pivot element. The pivot element is compared with the elements beginning from the first index. 
If the element greater than the pivot element is reached, a second pointer is set for that element.

2.Now, the pivot element is compared with the other elements (a third pointer). If an element smaller than the pivot element is reached,
the smaller element is swapped with the greater element found earlier.

3.The process goes on until the second last element is reached.
Finally, the pivot element is swapped with the second pointer. 
*/

#include <iostream>

using namespace std;

int partition(int* arr, int start, int end) {
    int pivot_index = end;
    int store_index = start - 1;
    int temp;

    for(int i = store_index + 1; i < end; i++) {
        if(arr[i] <= arr[pivot_index]) {
            store_index++;
            temp = arr[store_index];
            arr[store_index] = arr[i];
            arr[i] = temp;
        }
    }
    temp = arr[pivot_index];
    arr[pivot_index] = arr[store_index+1];
    arr[store_index+1] = temp;

    return store_index + 1;
}

void quicksort(int* arr, int start, int end) {
    if(start <  end) {
        int pivot_index = partition(arr, start, end);
        quicksort(arr, start, pivot_index - 1);
        quicksort(arr, pivot_index + 1, end);
    }
}

int main(){
    int arr[] = {12, 2, 13, 40, -5, 16};

    cout << "Initial Unsorted Array is : \n";
    
    for(int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Array after Quick Sort : \n";

    quicksort(arr, 0, sizeof(arr)/sizeof(int) - 1);

    for(int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

/*
Worst Case - O(n^2) - Happens when the greatest or the least element is picked as the pivot
Best Case - O(n*log n) - It occurs when the pivot element is always the middle element or near to the middle element.
Average - O(n*log n)

Space Complexity - O(log n)
*/