#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

const int MAXN = 200005;
const ll INF = 2e9 + 7;

int n; 
vector<ll> initial_values(MAXN);
vector<ll> seg_tree(4 * MAXN);

void build(int v, int tl, int tr) {
    if (tl == tr) {
        seg_tree[v] = initial_values[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        seg_tree[v] = min(seg_tree[v * 2], seg_tree[v * 2 + 1]);
    }
}

void update(int v, int tl, int tr, int pos, ll new_val) {
    if (tl == tr) {
        seg_tree[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm) {
            update(v * 2, tl, tm, pos, new_val);
        } else {
            update(v * 2 + 1, tm + 1, tr, pos, new_val);
        }
        seg_tree[v] = min(seg_tree[v * 2], seg_tree[v * 2 + 1]);
    }
}

ll query(int v, int tl, int tr, int l, int r) {
    if (l > r) {
        return INF;
    }
    if (l == tl && r == tr) {
        return seg_tree[v];
    }
    int tm = (tl + tr) / 2;
    if (r <= tm) {
        return query(v * 2, tl, tm, l, r);
    }
    if (l > tm) {
        return query(v * 2 + 1, tm + 1, tr, l, r);
    }
    ll left_min = query(v * 2, tl, tm, l, tm);
    ll right_min = query(v * 2 + 1, tm + 1, tr, tm + 1, r);
    return min(left_min, right_min);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int q;
    cin >> n >> q;

    for (int i = 1; i <= n; ++i) {
        cin >> initial_values[i];
    }

    build(1, 1, n);

    for (int i = 0; i < q; ++i) {
        int type;
        cin >> type;
        if (type == 1) {
            int k;
            ll u;
            cin >> k >> u;
            update(1, 1, n, k, u);
        } else {
            int a, b;
            cin >> a >> b;
            cout << query(1, 1, n, a, b) << "\n";
        }
    }

    return 0;
}
