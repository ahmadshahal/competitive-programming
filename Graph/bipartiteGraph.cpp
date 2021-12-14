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

int n, m;
vector<int> myGraph[200005];
int color[200005];
bool isBipartite = true;

void dfsIsBipartite(int u, int c) // c is 0 initialy
{
    color[u] = c;
    for (int v : myGraph[u])
    {
        if(color[v] == -1)
            dfsIsBipartite(v, 1 - c); // 1 -> 0 or 0->1
        else
            if(color[u] == color[v])
                isBipartite = false;
    }
}

int main()
{
    goFast();
    cin >> n >> m;
    fillWith(color, -1);
    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        myGraph[x].push_back(y);
        myGraph[y].push_back(x);
    }
    dfsIsBipartite(1, 0);
    if(!isBipartite)
        return cout << "NO" << endl, 0;
    cout << "YES" << endl;
}