#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e15;

class Range {
public:
    int l, a;
    Range(int l, int a) {
        this->l = l;
        this->a = a;
    }
};

class SegmentTree {
public:
    int n;
    vector<int> seg, lazy;
    
    void init(int _n) {
        n = _n;
        seg.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
    }
    
    void push_lazy(int idx, int start, int end) {
        if (lazy[idx] != 0) {
            seg[idx] += lazy[idx];
            if (start != end) {
                lazy[2 * idx + 1] += lazy[idx];
                lazy[2 * idx + 2] += lazy[idx];
            }
            lazy[idx] = 0;
        }
    }
    
    void update_range(int start, int end, int idx, int l, int r, int val) {
        push_lazy(idx, start, end);
        
        // Không giao nhau
        if (start > r || end < l) return;
        
        // Giao hoàn toàn
        if (start >= l && end <= r) {
            lazy[idx] += val;
            push_lazy(idx, start, end);
            return;
        }
        
        int mid = (start + end) / 2;
        update_range(start, mid, 2 * idx + 1, l, r, val);
        update_range(mid + 1, end, 2 * idx + 2, l, r, val);
        seg[idx] = max(seg[2 * idx + 1], seg[2 * idx + 2]);
    }
    
    int query_range(int start, int end, int idx, int l, int r) {
        push_lazy(idx, start, end);
        
        if (start > r || end < l) return -INF;
        
        if (start >= l && end <= r) return seg[idx];
        
        int mid = (start + end) / 2;
        int leftAns = query_range(start, mid, 2 * idx + 1, l, r);
        int rightAns = query_range(mid + 1, end, 2 * idx + 2, l, r);
        return max(leftAns, rightAns);
    }
    
    int query(int l, int r) {
        return query_range(0, n - 1, 0, l, r);
    }
    
    void update(int l, int r, int val) {
        update_range(0, n - 1, 0, l, r, val);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> addEvent(n + 2);
    vector<vector<Range>> removeEvent(n + 2);
    
    for (int i = 0; i < m; i++){
        int l, r, a;
        cin >> l >> r >> a;
        addEvent[l].push_back(a);
        removeEvent[r + 1].push_back(Range(l, a));
    }
    
    SegmentTree tree;
    tree.init(n + 1);
    
    int ans = 0;
    for (int i = 1; i <= n; i++){
        for (auto x : addEvent[i]){
            tree.update(0, i - 1, x);
        }
        for (auto rEvent : removeEvent[i]){
            tree.update(0, rEvent.l - 1, -rEvent.a);
        }
        
        int cur_dp = tree.query(0, i - 1);
        tree.update(i, i, cur_dp);
        ans = max(ans, cur_dp);
    }
    
    cout << ans << "\n";
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
