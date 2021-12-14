#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


int fastestPower(int x, int y) {
    if(y == 0)
        return 1;
    if(y & 1)
        return x * fastestPower(x, y - 1);
    int z = fastestPower(x, y / 2);
    return z * z;
}


int main() {
    int x, y;
    cin >> x >> y;
    cout << fastestPower(x, y) << endl;
}