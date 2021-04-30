#include<iostream>
#include <cstring>

using namespace std;

//KMP algorithm is based on preprocessing the pattern.

//In this algorithm, there is an observation of a prefix  that is also a suffix.
//Example => pat = [a,b,c,d,a,b,c]
//the prefix sub-array = a,ab,abc,abcd etc.
//Also the suffix sub-array = c,bc,abc,dabc;
//So as we can see there is 'abc' who is present in prefix array as well as suffix array.

//We compute lps array by just iterating and checking if the previous one is equal
// and if they are equal we just add 1 to the current one.

//Similarly in kmp pattern search function we also did same thing.

void compute_lps(char *pat, int m, int *lps) {

    int len = 0;
    lps[0] = 0;

    int i = 1;

    while(i < m) {
        if(pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if(len != 0) {
                len = lps[len-1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void kmp_pattern_search(char *txt, char *pat, int m, int n) {

    int lps[m];

    compute_lps(pat, m, lps);

    int i = 0;
    int j = 0;
    while(i < n) {
        if(pat[j] == txt[i]) {
            i++;
            j++;
        }
        if(j == m) {
            cout << "Pattern at index " << i-j <<'\n';
            j = lps[j-1];
        }
        else if(i < n && pat[j] != txt[i]) {
            if(j != 0)
                j = lps[j-1];
            else
                i++;
        }
    }
}

int main() {

    char txt[] ="ABABABA";
    char pat[] = "ABA";
    int m = sizeof(pat)/sizeof(*pat);
    int n = sizeof(txt)/sizeof(*txt);

    kmp_pattern_search(txt, pat, m, n);
}


