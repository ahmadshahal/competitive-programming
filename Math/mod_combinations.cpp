#include <bits/stdc++.h>
#define Mod 1000000007 
#define goFast() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef long long ll;
using namespace std;

int fa[500005];

int mul(int x, int y) {
    return (ll) x * y % Mod;
}

int sum(int x, int y) {
    if ((x += y) >= Mod)
        x -= Mod;
    return x;
}

int sub(int x, int y) {
    if ((x -= y) < 0)
        x += Mod;
    return x;
}

int po(int x, int y) {
    if (!y)
        return 1;
    if (y & 1)
        return mul(x, po(x, y - 1));
    int z = po(x, y / 2);
    return mul(z, z);
}

int inv(int x) {
    return po(x, Mod - 2);
}

int C(int x, int y) {
    if (y > x)
        return 0;
    return mul(mul(fa[x], inv(fa[y])), inv(fa[x - y]));
}

int main() {
    goFast();
    fa[0] = 1;
    for (int i = 1; i <= 5e5; i++)
        fa[i] = mul(fa[i - 1], i);
}