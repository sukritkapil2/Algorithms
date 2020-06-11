/*
Implementation of Selection Sort in C++
Author - Sukrit Kapil
Date - 11 June 2020
*/

/*
Theory - 
Start from the first element, then iterate over the array till the end, to find the minimum element.
Then place it in the starting. Then repeat from the second element, till n minimum elements have been placed.
*/

#include <iostream>

using namespace std;

void selection_sort(int* arr, int start, int end) {
    for(int i = 0; i < end; i++) {
        int min_index = i;
        for(int j = i + 1; j <= end; j++) {
            if(arr[min_index] > arr[j]) {
                min_index = j;
            }
        }
        int temp = arr[min_index];
        arr[min_index] = arr[i];
        arr[i] = temp;
    }
}

int main(){
    int arr[] = {12, 2, 13, 40, -5, 16};

    cout << "Initial Unsorted Array is : \n";
    
    for(int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Array after Selection Sort : \n";

    selection_sort(arr, 0, sizeof(arr)/sizeof(int) - 1);

    for(int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

/*
Worst Case - O(n^2) - If we want to sort in ascending order and the array is in descending order then, the worst case occurs.
Best Case - O(n2) - It occurs when the array is already sorted
Average - O(n2) - It occurs when the elements of the array are in jumbled order 

Space Complexity - O(1)
*/