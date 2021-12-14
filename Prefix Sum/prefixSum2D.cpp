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

const int N = 101;

// *: Contains the the prefix sum of each element in 2D.
int prefixSum[N][N]; // !: Initialized with zeros.

// *: Calculates the sum of the rectangle with the given indexes.
int sumQuery(int i, int j, int k, int l)
{
    return prefixSum[k][l] - prefixSum[i - 1][l] - prefixSum[k][j - 1] + prefixSum[i - 1][j - 1];
}

int main()
{
    goFast();
    int n;
    cin >> n;
    
    //*: Taking input.
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> prefixSum[i][j];
    
    // *: Accumulating rows.
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            prefixSum[i][j] += prefixSum[i][j - 1];

    // *: Accumulating Columns.
    for(int j = 1; j <= n; j++)
        for(int i = 1; i <= n; i++)
            prefixSum[i][j] += prefixSum[i - 1][j];

    // *: Generating 4 points for the rectangle and saving the maximum sum.
    int maxi = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            for(int k = i + 1; k <= n; k++)
                for(int l = j + 1; l <= n; l++)
                    maxi = max(maxi, sumQuery(i, j, k, l));

    cout << maxi << endl;
}