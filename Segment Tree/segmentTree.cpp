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

int n;
int arr[100005];
int segment[4 * 100005];

void Build(int p = 1, int L = 1, int R = n)
{
    if (L == R)
    {
        segment[p] = arr[L];
        return;
    }
    int Mid = (L + R) / 2;
    Build(2 * p, L, Mid);
    Build(2 * p + 1, Mid + 1, R);
    segment[p] = segment[2 * p] + segment[2 * p + 1];
}

int getQRY(int l, int r, int p = 1, int L = 1, int R = n)
{
    if (l > R || L > r)
        return 0; // Neutral
    if (l <= L && r >= R)
        return segment[p];
    int Mid = (L + R) / 2;
    return getQRY(l, r, 2 * p, L, Mid) + getQRY(l, r, 2 * p + 1, Mid + 1, R);
}

void update(int pos, int newValue, int p = 1, int L = 1, int R = n)
{
    if (L == R)
    {
        segment[p] = newValue;
        return;
    }
    int Mid = (L + R) / 2;
    if (pos <= Mid)
        update(pos, newValue, p * 2, L, Mid);
    else
        update(pos, newValue, p * 2 + 1, Mid + 1, R);
    segment[p] = segment[p * 2] + segment[p * 2 + 1];
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    Build();
    cout << getQRY(2, 3) << endl;
    update(3, 5);
    cout << getQRY(2, 3) << endl;
}