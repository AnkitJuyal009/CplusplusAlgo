#include<iostream>
#include <cstring>

#define d 256

using namespace std;

//Rabin karp algorithm is a pattern searching algorithm that uses hash values.
//Basic idea is to use a hash code to avoid checking pattern in the string.

//In this we match hash values of the substring of txt and pat and check if they are equal or not.
//If they are equal then we just compare character by character and if not we just leave it.

//So its is better than naive pattern search as in there we use hash values that tells to go forward or not,
// whereas in naive pattern search we have to compare it if its not worth it.

// how to get those HASH VALUES for each alphabet

//First thing if use our own hashcode like a -> 1, b -> 2, c -> 3... and goes on. There is some issue in this procedure.
//lets take an example
//txt = [b,a,e,c,c,b] = in this if we group it with length 3 as pat, the codes are 8 and 8 and they are equal also(by hashcodes), so we compare each character then.
//pat = [a,c,d] = this will be equal to 1 + 3 + 4 = 8
//comparing each character again and again.. will give me worst case scenario i.e O(n*m).

//So to avoid this we use unique hash codes
//lets say pat = [a,c,b] = we can write this as 1,3,2 => pat[1]* 10^2 + pat[3] * 10^1 + pat[2] * 10^0 here 10 is the unique codes that we have taken from a to j.
//so for whole alphabets we take 256 (a-z, A-Z, 0-9)
//also we mod as we get large no that exceeds our datatype.



//Time Complexity => O(n + m)

void rabin_karp(char *txt, char *pat, int q) {

    int N = strlen(txt);
    int M = strlen(pat);
    int i,j;
    int t = 0;
    int p = 0;
    int h = 1;

    //we are generating
    for (i = 0; i < M-1; ++i) {
        h = (h * d) % q;
    }

    for (i = 0; i < M; ++i) {
        t = (t * d + txt[i]) % q;
        p = (p * d + pat[i]) % q;
    }

    for (i = 0; i < N-M+1; ++i) {
        
        if(p == t) {
            for (j = 0; j < M; ++j) {
                if(txt[i+j] != pat[j])
                    break;
            }
            if(j == M)
                cout << "Pattern at index " << i <<'\n';
        }
        if ( i < N-M )
        {
            t = (d*(t - txt[i]*h) + txt[i+M])%q;

            // We might get negative value of t, converting it to positive
            if (t < 0)
                t = (t + q);
        }

    }
}

int main() {

    char txt[] = "ABABABAABBB";
    char pat[] = "ABA";

    rabin_karp(txt, pat, 101);
}



