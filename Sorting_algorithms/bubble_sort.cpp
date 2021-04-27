#include<iostream>
using namespace std;

//Bubble sort is a sorting algorithms in which
// we swap adjacent elements if the previous element is greater than the next element.

//Time Complexity => O(n^2)
//NOTE : Bubble sort is the simplest algorithm.

void bubble_sort(int arr[], int len) {

    int i,j;

    for (i = 0; i < len-1; ++i) {

        for(j = 0; j < len-i; ++j) {
            if(arr[j] > arr[j+1])
                swap(arr[j],arr[j+1]);
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

    bubble_sort(A, n);
    printArray(A, n);

}


