#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool prime[500];

void sieveOfEratosthenes(int n) {
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
}

int main() {
    int n = 100;
    memset(prime, true, n + 5); // Fills the array with true.
    sieveOfEratosthenes(n);
}
