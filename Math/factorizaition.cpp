#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> factorization(ll x) { // O( sqrt (x) )
    vector<ll> v;
    for(ll i = 2; i * i <= x; i++) {
        while (x % i == 0) {
            x /= i;
            v.push_back(i);
        }
    }
    if(x > 1)
        v.push_back(x);
    return v;
}

int main() {
    vector<ll> v = factorization(1000000000000);
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
    return 0;
}
