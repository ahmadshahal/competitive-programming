#include <bits/stdc++.h>
using namespace std;
#define ll long long


int gcd(int a, int b) { // O( log (a * b) )
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) { // O( log (a * b) )
    return (a / gcd(a, b)) * b;
}

int main() {
    // Or use __gcd()
}
