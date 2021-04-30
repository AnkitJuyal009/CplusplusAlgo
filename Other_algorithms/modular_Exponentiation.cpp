#include<iostream>
using namespace std;
#define ll long long

//find x power y in O(logy)
//It can be overflow so use modulo
// for
// (ab) mod p = ( (a mod p) (b mod p) ) mod p
//For example a = 50,  b = 100, p = 13
//50  mod 13  = 11
//100 mod 13  = 9
//
//(50 * 100) mod 13 = ( (50 mod 13) * (100 mod 13) ) mod 13
//or (5000) mod 13 = ( 11 * 9 ) mod 13
//or 8 = 8

int fastPower(ll x, unsigned y, int p) {

    int res = 1;

    x = x % p;

    if(x == 0) return 0;

    while(y > 0) {
        if (y & 1) {
            res = (res * x) % p;
        }
            y = y >> 1;
            x = (x * x) % p;
    }
    return res;
}

int main() {
    int number, power, modulo;
    cin >> number >> power >> modulo;

   int result = fastPower(number, power, modulo);

   cout << result;

}

