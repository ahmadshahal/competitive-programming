#include <bits/stdc++.h>
#define debug(a) cout << #a << ": " << a << "\n"
#define debugLine() cout << "==============\n"
#define tick() cout << "Tick\n";
#define testCases() int t; cin >> t; while(t--)
#define all(a) a.begin(), a.end()
#define fillWith(a, b) memset(a, b, sizeof(a))
#define INF_32 1e9
#define INF_64 1e18
#define Mod 1000000007
#define endl "\n"
#define goFast() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef long long ll;
using namespace std;

#define int long long

int dp[100][100];

int combination(int n, int r)
{
    if(n == r || r == 0)
        return 1;
    if(dp[n][r] != -1)
        return dp[n][r];
    return dp[n][r] = combination(n - 1, r - 1) + combination(n - 1, r);
}

main()
{
    goFast();
    fillWith(dp, -1);
}