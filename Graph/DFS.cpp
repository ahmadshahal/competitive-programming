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
#define PI 3.14159265358979323846
#define endl "\n"
#define goFast() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
typedef long long ll;
using namespace std;

int n, m, visited[200200];
vector<int> myGraph[200200];

void dfs(int u)
{
    if (visited[u])
        return;
    visited[u] = 1;
    for (int v : myGraph[u])
        dfs(v);
}

void addEdge(int u, int v)
{
    myGraph[u].push_back(v);
    myGraph[v].push_back(u);
    return;
}

int main()
{
    int numberOfComponents = 0;
    n = 5;
    addEdge(1, 3);
    addEdge(5, 2);
    addEdge(2, 4);
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs(i);
            numberOfComponents++;
        }
    }
    cout << numberOfComponents;
}
