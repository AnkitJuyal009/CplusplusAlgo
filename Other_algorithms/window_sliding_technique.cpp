#include<iostream>
using namespace std;

//Window sliding technique is a technique in which we optimize our code from O(n^2) to O(n).
//In this, we have a problem to find the maximum sub-array sum in the whole array where we can use window sliding approach to solve the problem.

int maximum_sum(const int arr[], int n, int k) {

    int max_sum = 0;

    if(n < k) {
        cout << "K is greater than N";
        return -1;
    }

    for (int i = 0; i < k; ++i) {
        max_sum += arr[i];
    }

    int window_sum = max_sum;

    for (int i = k; i < n; ++i) {
        window_sum += arr[i] - arr[i-k];
        max_sum = max(max_sum, window_sum);
    }

    return max_sum;
}

int main() {
    int n, k;
    cin >> n >> k;
    int A[n];

    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    int result = maximum_sum(A, n, k);
    cout << result;
}

