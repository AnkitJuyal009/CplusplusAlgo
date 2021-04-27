#include<iostream>
using namespace std;

//Insertion sort is a sorting algorithm where we just make a key and compare it with the previous element.
// If it is smaller than the previous element then we swap it until it reaches its correct position.
//Else we just iterate to another element in the array.

//Time complexity => O(n^2) in average and worst case and O(N) in best case
//NOTE : Insertion sort is way quicker and efficient than MergeSort and QuickSort when n is very small.

void insertionSort(int arr[], int len) {

    int key,i,j;

    for(i = 1; i < len; ++i) {
        key = arr[i];
        j = i-1;

        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
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

    insertionSort(A, n);
    printArray(A, n);

}


