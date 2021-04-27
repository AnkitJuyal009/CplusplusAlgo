#include<iostream>
using namespace std;

//Quick Sort is the sorting algorithm that also uses dived and conquer approach.
// In this we make an element in array a pivot and then we just sort it using this pivot element.
//We uses partition function that will return the index of the pivot element after it went to its correct position
//quickSort function recursively sort the arrays divided through pivot element that we got from partition function.

//Time Complexity => O(nlogn) in best and average case and in worst case its O(n^2).
int partition(int arr[], int left, int right) {

    //we took last element as pivot element.
    int pi = arr[right];
    int i = left - 1;

    for (int j = left; j < right; ++j) {
        if(arr[j] < pi) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[right]);
    return i+1;
}

void quickSort(int arr[], int start, int end) {

    if(start < end) {
        int pivot = partition(arr, start, end);
        quickSort(arr, start, pivot - 1);
        quickSort(arr, pivot + 1, end);
    }
}



void printArray(int arr[], int len) {

    for (int i = 0; i < len; ++i) {
        cout << arr[i] << " ";
    }

}



int main() {

    int n;
    cin >> n;
    int A[n];

    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    quickSort(A,0,n-1);
    printArray(A, n);
}

