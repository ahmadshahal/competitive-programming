#include <bits/stdc++.h>
#define debug(a) cout << #a << ": " << a << "\n"
#define debugLine() cout << "==============\n"
#define tick() cout << "Tick\n";
#define testCases() int t; cin >> t; while(t--)
#define all(a) a.begin(), a.end()
#define INF_32 1e9
#define INF_64 1e18
#define Mod 1000000007
#define endl "\n"
#define goFast() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef long long ll;
using namespace std;

// Problem Link: https://atcoder.jp/contests/dp/tasks/dp_a
 
int n;
int arr[100005];
int dp[100005];

int bruteForce(int i = 1)
{
    if(i == n)
        return 0;
    if(dp[i] != -1)
        return dp[i];
    int x1 = abs(arr[i] - arr[i + 1]) + bruteForce(i + 1);
    int x2 = 1e8;
    if(!(i + 2 > n))
        x2 = abs(arr[i] - arr[i + 2]) + bruteForce(i + 2);
    // debug(x1);
    // debug(x2);
    return dp[i] = min(x1, x2);
}

void path(int i = 1) // How to print the path dp took.
{
    if(i == n)
        return;
    int x = bruteForce(i);
    if(x == abs(arr[i] - arr[i + 1]) + bruteForce(i + 1)) // From which one it is comming from?
    {
        cout << i + 1 << " ";
        path(i + 1);
    }
    else if(x == abs(arr[i] - arr[i + 2]) + bruteForce(i + 2))
    {
        cout << i + 2 << " ";
        path(i + 2);
    }
}

int main()
{
    goFast();
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];
    bruteForce();
    cout << 1 << " ";
    path();
    // cout << bruteForce() << endl;
}