#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> divisors(ll x) { // O( sqrt (x) )
    vector<ll> v;
    for (ll i = 1; i * i <= x; i++) {
        if (x % i == 0) {
            v.push_back(i);
            if (i != x / i)
                v.push_back(x / i);
        }
    }
    sort(v.begin(), v.end());
    return v;
}

int main() {
    vector<ll> v = divisors(1024040300570);
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
    return 0;
}
