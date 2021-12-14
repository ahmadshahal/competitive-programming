#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n;
vector<ll> Distance[1010];
vector<pair<ll, int>> MyGraph[1010];

void addEdge(int u, int v, ll w)
{
    // Undirected and Weighted
    MyGraph[u].push_back({w, v}); // first w then v
    MyGraph[v].push_back({w, u}); // first w then u
    return;
}

vector<ll> Dijkstra(int source)
{
    priority_queue<pair<ll, int>> q;
    vector<ll> Dist(n + 1, 1e18);
    Dist[source] = 0;
    q.push({Dist[source], source});
    while (!q.empty())
    {
        pair<ll, int> Top = q.top();
        q.pop();
        int Parent = Top.second;
        ll DistParent = (-1) * Top.first;
        if (DistParent > Dist[Parent])
            continue; // Very Important
        for (auto PairSon : MyGraph[Parent])
        {
            int son = PairSon.second;
            ll Weight = PairSon.first;
            if (DistParent + Weight < Dist[son])
            {
                Dist[son] = DistParent + Weight;
                q.push({(-1) * Dist[son], son}); //first Dist then son
            }
        }
    }
    return Dist;
}

int main()
{
    n = 5;

    addEdge(1, 3, 2);
    addEdge(1, 2, 2);
    addEdge(2, 4, 3);
    addEdge(4, 5, 8);
    addEdge(1, 4, 6);

    for (int i = 1; i <= n; i++)
        Distance[i] = Dijkstra(i);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (Distance[i][j] == 1e18)
                cout << "There is no path form " << i << " to " << j << endl;
            else
                cout << "Shortest Path from " << i << " to " << j << " is " << Distance[i][j] << endl;
        }
        cout << "\n--------------\n";
    }
    return 0;
}
