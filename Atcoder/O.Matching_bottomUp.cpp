#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;


void solve() {
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }           

    vector<int> dp(1 << n, 0);
    dp[0] = 1; 
    for(int mask = 0; mask < ((1<<n) -1); mask++) {
        int man = __builtin_popcount(mask);
        for(int i = 0; i < n; i++) {
            if (v[man][i] && !(mask & (1 << i))) {
                dp[mask ^ (1 << i)] += dp[mask];
                dp[mask ^ (1 << i)] %= mod;
            }
        }
    }
    cout << dp[(1<<n) -1] << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
