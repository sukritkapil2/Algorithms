/*
Implementation of Quick Sort in C++
Author - Sukrit Kapil
Date - 11 June 2020
*/

/*
Theory - 
1. Starting from the first index, compare the first and the second elements.If the first element 
is greater than the second element, they are swapped.
Now, compare the second and the third elements. Swap them if they are not in order.
The above process goes on until the last element.

2.The same process goes on for the remaining iterations. After each iteration, 
the largest element among the unsorted elements is placed at the end.

3. If at a point, no swapping occurs, we can stop the sorting process as it is already sorted.
*/

#include <iostream>

using namespace std;

int swap_occured = true;

void bubble_sort(int* arr, int start, int end) {
    while(swap_occured) {
        swap_occured = false;

        for(int i = start; i < end; i++) {
            int j = i + 1;
            if(arr[i] > arr[j]) {
                swap_occured = true;
                int temp;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main(){
    int arr[] = {12, 2, 13, 40, -5, 16};

    cout << "Initial Unsorted Array is : \n";
    
    for(int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Array after Bubble Sort : \n";

    bubble_sort(arr, 0, sizeof(arr)/sizeof(int) - 1);

    for(int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

/*
Worst Case - O(n^2) - Happens when the greatest or the least element is picked as the pivot
Best Case - O(n*log n) - It occurs when the pivot element is always the middle element or near to the middle element.
Average - O(n*log n)
*/