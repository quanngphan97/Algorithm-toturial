#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;
const int oo = 1e18;

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    vector<int> cost(1 << n);
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            for (int k = j+1; k < n; k++) {
                if ((i & (1 << j)) && (i & (1 << k))) {
                    cost[i] += a[j][k];
                }
            }
        }
    }

    vector<int> dp(1 << n);
    for (int i = 0; i < (1 << n); i++) {
        int j = ((1 << n) - 1) ^ i;
        for (int k = j; k > 0; k = (k - 1) & j) {
            dp[i ^ k] = max(dp[i ^ k], dp[i] + cost[k]);
        }
    }

    cout << dp[(1 << n) - 1] << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
