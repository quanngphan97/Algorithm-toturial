#include <bits/stdc++.h>
using namespace std;
#define int long long
const int oo = 1e18;

int solve(int idx, int v, vector<pair<int, int>>& item, vector<vector<int>>& dp) {
    if (v == 0) return 0;
    if (idx == 0) return (v <= 0 ? 0 : oo);
    if (dp[idx][v] != -1) return dp[idx][v];

    int weight = item[idx - 1].first;
    int value = item[idx - 1].second;

    int ans = solve(idx - 1, v, item, dp);

    if (v >= value) {
        ans = min(ans, solve(idx - 1, v - value, item, dp) + weight);
    }

    return dp[idx][v] = ans;
}

int knapSack(int max_v, int n, int w, vector<pair<int, int>>& item) {
    vector<vector<int>> dp(n + 1, vector<int>(max_v + 1, -1));

    int ans = 0;
    for (int v = 1; v <= max_v; v++) {
        if (solve(n, v, item, dp) <= w) {
            ans = v;
        }
    }
    return ans;
}

void solve() {
    int n, w;
    cin >> n >> w;

    int max_v = 0;
    vector<pair<int, int>> item(n);
    for (int i = 0; i < n; i++) {
        cin >> item[i].first >> item[i].second;
        max_v += item[i].second;
    }

    cout << knapSack(max_v, n, w, item) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
