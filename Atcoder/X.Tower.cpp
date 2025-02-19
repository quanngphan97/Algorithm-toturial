#include <bits/stdc++.h>
using namespace std;
#define int long long
const int oo = 1e18;
const int max_s = 1e4;

struct info {
    int w,s,v;
};

int cal(int idx, int val, int n, vector<info> &item, vector<vector<int>> &dp) {
    if (idx == n || val > max_s) return 0;
    
    if (dp[idx][val] != -1) return dp[idx][val];

    int &ans  = dp[idx][val];
    ans = cal(idx+1,val,n,item,dp);

    if (val <= item[idx].s) {
        ans = max(ans, item[idx].v + cal(idx+1, val + item[idx].w, n, item, dp));
    }

    return ans;
}
void solve() {
    int n; cin >> n;
    vector<info> item(n);
    for(int i = 0; i < n; i++) {
        cin >> item[i].w >> item[i].s >> item[i].v;
    }

    sort(item.begin(), item.end(), [](info a, info b) { 
        return a.w + a.s < b.w + b.s;
    });

    vector<vector<int>> dp(n,vector<int>(max_s + 10,-1));
    cout << cal(0,0,n,item,dp) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
