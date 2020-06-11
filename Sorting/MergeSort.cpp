/*
Implementation of Merge Sort in C++
Author - Sukrit Kapil
Date - 11 June 2020
*/

/*
Theory - 
The MergeSort function repeatedly divides the array into two halves until we reach a stage 
where we try to perform MergeSort on a subarray of size 1.
After that, the merge function comes into play and combines the sorted arrays into larger arrays until the whole array is merged.
*/

#include <iostream>

using namespace std;

void merge(int* arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2], index1 = 0, index2 = 0;

    for(int i = left; i <= mid; i++) {
        L[index1] = arr[i];
        index1++;
    }

    for(int i = mid + 1; i <= right; i++) {
        R[index2] = arr[i];
        index2++;
    }

    index1 = 0, index2 = 0;
    int k = left;

    while(index1 < n1 && index2 < n2) {
        if(L[index1] <= R[index2]) {
            arr[k] = L[index1];
            index1++;
        }
        else {
            arr[k] = R[index2];
            index2++;
        }
        k++;
    }

    while (index1 < n1) {
        arr[k] = L[index1];
        index1++;
        k++;
    }
    while (index2 < n2) {
        arr[k] = R[index2];
        index2++;
        k++;
    }
}

void merge_sort(int* arr, int start, int end) {
    if (start < end) {
        int mid = start + (end - start)/2;
        
        merge_sort(arr, start, mid);
        merge_sort(arr, mid + 1, end);

        merge(arr, start, mid, end);
    }
}

int main(){
    int arr[] = {12, 2, 13, 40, -5, 16};

    cout << "Initial Unsorted Array is : \n";
    
    for(int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Array after Merge Sort : \n";

    merge_sort(arr, 0, sizeof(arr)/sizeof(int) - 1);

    for(int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

/*
Worst Case - O(n*log n)
Best Case - O(n*log n)
Average - O(n*log n)

Space Complexity - O(n)
*/