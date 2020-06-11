/*
Implementation of Insertion Sort in C++
Author - Sukrit Kapil
Date - 11 June 2020
*/

/*
Theory - 
The insertion sort algorithm works in this way - 
We take the second element and decide its position in the left sub-array, so that for each element we
pick, the left-subarray is always sorted
*/

#include <iostream>

using namespace std;

void insertion_sort(int* arr, int start, int end) {
    int current = start + 1;

    for(int i = current; i <= end; i++) {
        int k = i;
        int j = k - 1;
        while (arr[j] > arr[k] && k >= 1) {
            int temp = arr[j];
            arr[j] = arr[k];
            arr[k] = temp;

            k--;
            j = k - 1;
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

    cout << "Array after Quick Sort : \n";

    insertion_sort(arr, 0, sizeof(arr)/sizeof(int) - 1);

    for(int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

/*
Worst Case - O(n2) - Suppose, an array is in ascending order, and you want to sort it in descending order.
In this case, worst case complexity occurs.
Best Case - O(n) - When the array is already sorted, the outer loop runs for n number of times
whereas the inner loop does not run at all
Average - O(n2) - It occurs when the elements of an array are in jumbled order

Space Complexity - O(1)
*/