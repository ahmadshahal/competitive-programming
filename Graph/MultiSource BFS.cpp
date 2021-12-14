#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> adj[200200];

void addEdge(int u, int v)
{
    // Undirected
    adj[u].push_back(v);
    adj[v].push_back(u);
    return;
}

vector<int> Bfs(vector<int> start)
{
    queue<int> q;
    vector<int> Distance(n + 1, 1e8);
    for (int s : start)
    {
        q.push(s);
        Distance[s] = 0;
    }
    while (!q.empty())
    {
        int parent = q.front();
        q.pop();
        for (int son : adj[parent])
        {
            if (Distance[son] > Distance[parent] + 1)
            {
                Distance[son] = Distance[parent] + 1;
                q.push(son);
            }
        }
    }
    return Distance;
}
int main()
{
    n = 11;
    addEdge(3, 5);
    addEdge(5, 2);
    addEdge(2, 4);
    addEdge(6, 1);
    addEdge(1, 3);
    addEdge(3, 6);
    addEdge(7, 6);
    addEdge(4, 9);
    addEdge(9, 7);
    addEdge(10, 7);
    vector<int> sorces = {1, 2, 3};
    vector<int> Dist = Bfs(sorces);
    for (int i = 1; i <= n; i++)
    {
        if (Dist[i] == 1e8)
            cout << "There is no path \n";
        else
            cout << "The Shortest Path from " << i << " to one of {1,2,3} is " << Dist[i] << endl;
    }
    return 0;
}
