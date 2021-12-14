// Written By Grapeee: https://codeforces.com/profile/Grapeee

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int x = 10, y = 6;
    cout << x << " And " << y << " is " << (x & y) << endl; // 1 only when 1,1 and 0 otherwise
    cout << x << " Or " << y << " is " << (x | y) << endl;  // 0 only when 0,0 and 1 otherwise
    cout << x << " Xor " << y << " is " << (x ^ y) << endl; // 1 when (1,0 or 0,1) and 0 otherwise

    cout << (2 << 3) << endl;  // (2) * (2 * 2 * 2)
    cout << (1 << 3) << endl;  // (1) * (2 * 2 * 2)
    cout << (24 >> 1) << endl; // (24) / (2)
    cout << (24 >> 2) << endl; // (24) / (2 * 2)
    cout << (1 << 0) << endl;  // (1)
    cout << (5 >> 0) << endl;  // (5)

    if ((x & (1 << 3)) != 0)
        cout << "The Third Bit of x is on\n";
    else
        cout << "The Third Bit of x is off\n";

    // turn the ith bit
    int a = 3;
    // in binary 000011
    a |= (1 << 2);
    // ------->  000111
    cout << a << endl;

    // turn off the same bit
    a ^= (1 << 2);
    cout << a << endl;

    // OR -- > On
    // Xor -- > Off (only if it is was on)
}
