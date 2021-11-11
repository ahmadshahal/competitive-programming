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

#define int long long

string L, R; // Left - Right Strings.
int N; // Size of the longer string.
const int MAX = 1e6;

int dp[MAX][2][2]; // Memo array, initially {-1}.

int bruteForce(int i = 0, bool smaller = 0, bool greater = 0) {
    // Termination condition.
    if(i == N) {
        return 1;
    }
    // Retrieving solution if calculated.
    if(dp[i][smaller][greater] != -1) {
        return dp[i][smaller][greater];
    }
    int call = 0;
    // Calculating the range of valid numbers per digit (Not exceeding R and not being smaller than L).
    char l = (greater ? '0' : L[i]);
    char r = (smaller ? '9' : R[i]);
    for(char j = l; j <= r; j++) {
        call += bruteForce(i + 1, smaller ? smaller : j < R[i], greater ? greater : j > L[i]);
    }
    // Saving the solution and returning the value.
    return dp[i][smaller][greater] = call;
}

main() {
    goFast();
    cin >> L >> R;
    // initializing the memo array with -1 by using memset function, check the defines above.
    fillWith(dp, -1);
    N = R.size();
    // Making the strings sizes equal by adding leading zeros to the smaller string.
    /*
        Ex: L = "123", R = "12345"
        L = "32100" -> "00123"
    */
    int dif = R.size() - L.size();
    reverse(all(L));
    for(int i = 0; i < dif; i++) {
        L += '0';
    }
    reverse(all(L));
    cout << bruteForce() << endl;
}