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
vector<int> myGraph[200200];
bool visited[200];

void addEdge(int u, int v)
{
    // Undirected
    myGraph[u].push_back(v);
    myGraph[v].push_back(u);
    return;
}

vector<int> BFSshortestPath(int start)
{
    queue<int> q;
    vector<int> distance(n + 1, 1e8);
    q.push(start);
    distance[start] = 0;
    while (!q.empty())
    {
        int parent = q.front();
        q.pop();
        for (int son : myGraph[parent])
        {
            if (distance[son] > distance[parent] + 1)
            {
                distance[son] = distance[parent] + 1;
                q.push(son);
            }
        }
    }
    return distance;
}

void BFS(int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;
    while(!q.empty())
    {
        int s = q.front();
        q.pop();
        for(int v : myGraph[s])
        {
            if(!visited[v])
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

int main()
{
    n = 7;
    addEdge(3, 5);
    addEdge(5, 2);
    addEdge(2, 4);
    addEdge(6, 1);
    addEdge(1, 3);
    addEdge(3, 6);
    int source = 2;
    vector<int> Dist = BFSshortestPath(source);
    for (int i = 1; i <= n; i++)
    {
        if (Dist[i] == 1e8)
            cout << "There is no path from " << source << " to " << i << endl;
        else
            cout << "The length from " << source << " to " << i << " is " << Dist[i] << endl;
    }
    return 0;
}
