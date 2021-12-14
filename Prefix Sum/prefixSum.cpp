#include <bits/stdc++.h>
#define debug(a) cout << "Debugging: " << a << "\n"
#define debugLine() cout << "==============\n"
#define goFast() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef long long ll;
using namespace std;


int n;
int arr[500005];
ll prefixSum[500005];

// !: ZERO - BASED
void generatePrefixSumArray()
{
    for(int i = 0; i < n; i++)
        prefixSum[i] = (i == 0) ? arr[i] : arr[i] + prefixSum[i - 1];
}

ll getPrefixSumQRY(int L, int R)
{
    if(L == 0)
        return prefixSum[R];
    return prefixSum[R] - prefixSum[L - 1];
}

int main()
{
    goFast();
    n = 10;
    for(int i = 0; i < n; i++)
        arr[i] = i + 1;
    // arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
    generatePrefixSumArray();
    for(int i = 0; i < n; i++)
        cout << prefixSum[i] << " "; // 1 3 6 10 15 21 28 36 45 55 
    cout << "\n";
    cout << getPrefixSumQRY(3, 5) << "\n"; // 15
}