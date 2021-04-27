#include <iostream>
using namespace std;

void heapify(int arr[], int size, int i) {

    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if(left < size && arr[left] > arr[largest])
        largest = left;

    if(right < size && arr[right] > arr[largest])
        largest = right;

    if(largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, size, largest);
    }


}

void heapSort(int arr[], int len) {

    int index = (len - 1)/2;

    for (int i = index; i >= 0; --i) {
        heapify(arr, len, i);
    }

    for (int i = len-1; i > 0; --i) {
        swap(arr[0], arr[i]);

        heapify(arr, i, 0);
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

    heapSort(A, n);
    printArray(A, n);
}


