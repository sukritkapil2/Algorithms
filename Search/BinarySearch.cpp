#include <algorithm>
#include <iostream>

using namespace std;

int binary_search_impl(int arr[], int size, int x) {
    int low = 0;
    int high = size;
    while(low <= high) {
        int mid = (low + high)/2;

        if(arr[mid] == x) return mid;
        else if(arr[mid] < x) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[7] = {12, 87, 14, 18, 20, -56, -10};
    
    //sort the array
    sort(arr, arr+7);
    //new array -> -56, -10, 12, 14, 18, 20, 87

    cout << binary_search_impl(arr, 7, 87) << endl;

    return 0;
}