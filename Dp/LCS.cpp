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

string x1, x2;
int dp[3005][3005]; 

int LCS(int i = 0, int j = 0)
{
    if(i == x1.size() || j == x2.size())
        return 0;
    if(dp[i][j] != -1)
        return dp[i][j];
    int call1 = 0, call2 = 0, call3 = 0;
    if(x1[i] == x2[j])
        return dp[i][j] = call1 = 1 + LCS(i + 1, j + 1);
    call2 = LCS(i + 1, j);
    call3 = LCS(i, j + 1);
    return dp[i][j] = max(call2, call3);
}

void path(int i = 0, int j = 0)
{
    if(i == x1.size() || j == x2.size())
        return;
    int call = LCS(i, j);
    if(x1[i] == x2[j])
    {
        cout << x1[i];
        path(i + 1, j + 1);
        return;
    }
    if(call == LCS(i + 1, j))
        path(i + 1, j);
    else
        path(i, j + 1);
}

int main()
{
    goFast();
    memset(dp, -1, sizeof(dp));
    cin >> x1 >> x2;
    path();
}