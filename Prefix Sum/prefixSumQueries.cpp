#include <bits/stdc++.h>
#define endl "\n"
#define debug(a) cout << #a << ": " << a << endl
#define debugLine() cout << "==============" << endl
#define tick() cout << "Tick" << endl
#define testCases() int t; cin >> t; while(t--)
#define all(a) a.begin(), a.end()
#define fillWith(a, b) memset(a, b, sizeof(a))
#define Mod 1000000007
#define goFast() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define files(x) freopen(x, "r", stdin)
typedef long long ll;
using namespace std;

int arr[100005];
int pre[100005];

int main()
{
    goFast();
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    while (q--){
        int l, r;
        cin >> l >> r;
        int value;
        cin >> value;
        pre[l] += value;
        pre[r + 1] -= value;
    }
    for (int i = 1; i < n; i++)
        pre[i] += pre[i - 1];
    for (int i = 0; i < n; i++)
        arr[i] += pre[i];
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";   
}

