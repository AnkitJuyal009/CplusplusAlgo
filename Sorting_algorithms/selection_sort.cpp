#include<iostream>
using namespace std;

//Selection sort is the sorting algorithm in which we find the minimum element in the array and swap it in the beginning.

//Time Complexity =>O(n^2)
// NOTE : selection sort generally performs worse than insertion sort.

void selection_sort(int arr[], int len) {

    int min_index, i,j;

    for(i = 0; i < len - 1; ++i) {
        for (j = i+1; j < len; ++j) {
            if(arr[j] < arr[i])
                swap(arr[j],arr[i]);
        }
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

    selection_sort(A, n);
    printArray(A, n);

}
