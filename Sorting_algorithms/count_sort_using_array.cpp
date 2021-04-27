#include<iostream>
#include <algorithm>

using namespace std;

void count_sort(int arr[], int len)
{
    int largest = arr[0];

    //This loop is for getting the largest element from the array.
    for (int i = 0; i < len; ++i) {
        if(largest < arr[i])
           largest = arr[i];
    }

    int count[10] = {0};

    //This loop is for getting the count of elements present in original array.
    for (int i = 0; i < len; ++i) {
        count[arr[i]]++;
    }

    //This loop is for prefix sum array as we have to get the correct index position by adding the count of previous element.
    for (int i = 1; i <= largest; ++i) {
        count[i] += count[i-1];
    }

    for (int i = 0; i < largest; ++i) {
        cout << count[i] <<" ";
    }
    cout<<'\n';

    int output[len];

    //This loop is for
    for (int i = 0; i < len; ++i) {
        output[--count[arr[i]]] = arr[i];
    }

    for (int i = 0; i < len; ++i) {
        arr[i] = output[i];
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

    count_sort(A, n);
    printArray(A, n);

}




