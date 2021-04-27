#include<iostream>
#include <algorithm>
#include <vector>

using namespace std;

void count_sort(vector<int>& arr)
{
    int max = *max_element(arr.begin(), arr.end());
    int min = *min_element(arr.begin(), arr.end());
    int range = max - min + 1;

    vector<int> count(range), output(arr.size());
    for (int i = 0; i < arr.size(); i++)
        count[arr[i] - min]++;

    for (int x: count)
        cout<<x<<" ";

    cout<<'\n';


    for (int i = 1; i < count.size(); i++)
        count[i] += count[i - 1];

    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i] - min] - 1] = arr[i];
        count[arr[i] - min]--;
    }

    for (int i = 0; i < arr.size(); i++)
        arr[i] = output[i];
}

void printArray(vector<int>& arr)
{
    for (int i : arr)
        cout << i << " ";
    cout << "\n";
}

int main() {

    int n;
    int input;
    cin >> n;
    vector<int> A;

    for (int i = 0; i < n; ++i) {
        cin >> input;
        A.push_back(input);
    }

    count_sort(A);
    printArray(A);

}



