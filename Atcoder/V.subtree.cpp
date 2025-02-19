#include <bits/stdc++.h>
#define int long long
using namespace std;

int mod;
vector<vector<int>> g;
vector<int> down, up;

void dfs_down(int cur, int par) {
    down[cur] = 1;
    for (auto x : g[cur]) {
        if (x == par) continue;
        dfs_down(x, cur);
        down[cur] = (down[cur] * (down[x] % mod)) % mod;
    }
    down[cur] = (down[cur] + 1) % mod; 
}

void dfs_up(int cur, int par) {
    int pre = 1;
    for (auto child : g[cur]) {
        if (child == par) continue;
        up[child] = pre % mod;
        pre = (pre * down[child]) % mod;
    }

    reverse(g[cur].begin(), g[cur].end());

    int suff = 1;
    for (auto child : g[cur]) {
        if (child == par) continue;
        up[child] = (up[child] * (suff % mod)) % mod;
        suff = (suff * down[child]) % mod;
    }

    for (int child : g[cur]) {
        if (child == par) continue;
        up[child] = (up[child] * up[cur]) % mod;
        up[child] = (up[child] + 1) % mod;
        dfs_up(child, cur);
    }
}

void solve() {
    int n;
    cin >> n >> mod;
    g.resize(n);
    up.resize(n, 1), down.resize(n, 1); 
    
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs_down(0, -1);
    dfs_up(0, -1);

    for (int i = 0; i < n; i++) {
        cout << ((down[i] - 1 + mod) % mod * up[i]) % mod << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
