#include<iostream>
#include <cstring>

using namespace std;

//Naive pattern searching algorithm is the algorithm in which we find the pattern in the whole txt and printing out the starting index of it.
//It uses Window Sliding technique.

//Time Complexity => O(n) in best case where we get the first character of pattern is not there in txt.
//O(m * (n-m-1)) in worst case where all characters are matching in txt and also where all characters are matching except the last character.
//where (n - m - 1) is no of windows and m is the window size.

void pattern_search(char *txt, char *pat) {

    int n = strlen(txt);
    int m = strlen(pat);

    for (int i = 0; i < n-m+1; ++i) {
        int j;
        for (j = 0; j < m; ++j) {
            if(txt[i+j] != pat[j])
                break;
        }
        if(j == m) {
            cout << "Pattern at index " << i <<'\n';
        }
    }
}

int main() {

    char txt[] = "ABABABAABBB";
    char pat[] = "ABA";

    pattern_search(txt, pat);
}

