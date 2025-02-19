#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9 + 7;


int cal(int n, int mask, vector<vector<int>> &v, vector<int> &dp) {
    if (mask == 0) return 1;

    if (dp[mask] != -1) return dp[mask];


    int idx = __builtin_popcount(mask) - 1;
    int &ans = dp[mask];
    ans = 0;

    for (int j = 0; j < n; j++) {
        if ((mask & (1 << j)) && v[idx][j] == 1) {
            ans += cal(n, mask ^ (1 << j), v, dp);
            ans %= mod;
        }
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }

    vector<int> dp(1 << n, -1);

    cout << cal(n, (1 << n) - 1, v, dp) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
