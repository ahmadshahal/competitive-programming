#include <bits/stdc++.h>
#define endl "\n"
#define debug(a) cout << #a << ": " << a << endl
#define debugLine() cout << "==============" << endl
#define tick() cout << "Tick" << endl
#define testCases() int t; cin >> t; while(t--)
#define all(a) a.begin(), a.end()
#define fillWith(a, b) memset(a, b, sizeof(a))
#define Mod 1000000007
#define goFast() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define files(x) freopen(x, "r", stdin)
typedef long long ll;
using namespace std;

int n;
int seg[200005 * 4], lazy[200005 * 4];

void checkLazy(int p, int L, int R)
{
    if(lazy[p])
    {
        seg[p] += lazy[p];
        if(L != R)
        {
            lazy[2 * p] += lazy[p];
            lazy[2 * p + 1] += lazy[p];
        }
        lazy[p] = 0;
    }
}

void update(int l, int r, int newValue, int p = 1, int L = 1, int R = n)
{
    checkLazy(p, L, R);

    if(L >= l && R <= r)
    {
        seg[p] += newValue;

        if(L != R)
        {
            lazy[2 * p] += newValue;
            lazy[2 * p + 1] += newValue;
        }
        return;
    }

    if(L > r || R < l)
        return;
    int Mid = (L + R) / 2;
    update(l, r, newValue, 2 * p, L, Mid);
    update(l, r, newValue, 2 * p + 1, Mid + 1, R);

    seg[p] = seg[2 * p] + seg[2 * p + 1];
}

int getQRY(int l, int r, int p = 1, int L = 1, int R = n)
{
    checkLazy(p, L, R);

    if (L >= l && R <= r)
        return seg[p];
    if(L > r || R < l)
        return 0;
    int Mid = (L + R) / 2;
    return getQRY(l, r, 2 * p, L, Mid) + getQRY(l, r, 2 * p + 1, Mid + 1, R);
}

int main()
{
    goFast();
}