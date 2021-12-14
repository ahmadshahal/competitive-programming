#include <bits/stdc++.h>
using namespace std;

int parent[200200], sizee[200200], n, numberOfComponents = n;

int root(int x)
{
    if (x == parent[x])
        return x;
    return parent[x] = root(parent[x]);
}

void Union(int x, int y)
{
    int rx = root(x);
    int ry = root(y);
    if (rx != ry)
    {
        cout << x << "<--->" << y << endl;
        parent[rx] = ry;
        sizee[ry] += sizee[rx];
        numberOfComponents--;
    }
}

int main()
{
    n = 10;
    numberOfComponents = n;
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        sizee[i] = 1;
    }
    Union(3, 5);
    Union(1, 2);
    Union(5, 1);
    Union(3, 2);
    cout << sizee[root(10)] << " " << sizee[root(1)] << " " << sizee[root(3)];
    return 0;
}
