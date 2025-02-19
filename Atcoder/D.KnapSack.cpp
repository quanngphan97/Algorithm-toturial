#include <bits/stdc++.h>
using namespace std;
#define int long long
const int oo = 1e18;

int knapSack(int idx, int val, int n, int w, vector<pair<int, int>>& item, vector<vector<int>>& dp) {
    if (idx == n) return 0;
    if (dp[idx][val] != -1) return dp[idx][val];

    int &ans = dp[idx][val];
    ans = knapSack(idx + 1, val, n, w, item, dp);
    if (val + item[idx].first <= w) {
        ans = max(ans, item[idx].second + knapSack(idx + 1, val + item[idx].first, n, w, item, dp));
    }
    return ans;
}

void solve() {
    int n, w;
    cin >> n >> w;
    vector<pair<int, int>> item(n);
    for (int i = 0; i < n; i++) {
        cin >> item[i].first >> item[i].second;
    }
    vector<vector<int>> dp(n, vector<int>(w + 1, -1));
    cout << knapSack(0, 0, n, w, item, dp) << endl;
}


int32_t main() {
    ios::sync_with_stdio(false); 
    cin.tie(nullptr);

    solve();

    return 0;
}
