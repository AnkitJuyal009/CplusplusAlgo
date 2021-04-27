#include<iostream>
using namespace std;

//Merge Sort is the sorting algorithm which uses divide and conquer approach.
//In this algorithm, we first try to solve sub problems and then combine the sub problems.
//We create a mergeSort function which recursively sort the subarrays and merge function helps to merge and sort the subaarays.
//In merge function, we first make two temporary arrays of length n1 which is from start to mid and n2 which is from mid+1 to end
//then we compare the values in two temp arrays by making pointer to each array and if its small then we add it to the output array
//at last we just add remaining values from temp arrays (if any there) to output array.

//Time Complexity => O(nlogn) in all cases.

void merge(int arr[], int left, int mid, int right) {

    int n1 = mid - left + 1;
    int n2 = right - mid;

    int leftArr[n1];
    int rightArr[n2];

    for (int i = 0; i < n1; ++i) {
        leftArr[i] = arr[left+i];
    }

    for (int i = 0; i < n2; ++i) {
        rightArr[i] = arr[mid+1+i];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while(i < n1 && j < n2) {
        if(leftArr[i] > rightArr[j]) {
            arr[k] = rightArr[j];
            k++;
            j++;
        }

        else if(leftArr[i] < rightArr[j]) {
            arr[k] = leftArr[i];
            k++;
            i++;
        }
    }

    while(i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while(j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }

}

void mergeSort(int arr[], int start, int end) {

    if(start < end) {

        int mid = (start+end)/2;

        mergeSort(arr,start,mid);
        mergeSort(arr,mid+1,end);

        merge(arr,start,mid,end);
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

    mergeSort(A,0,n-1);
    printArray(A, n);
}

