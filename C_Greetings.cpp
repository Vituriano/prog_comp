#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct FenwickTree {
    vector<int> bit;
    int size;

    FenwickTree(int n) {
        size = n;
        bit.assign(n + 1, 0);
    }

    void update(int idx, int delta) {
        for (; idx <= size; idx += idx & -idx) {
            bit[idx] += delta;
        }
    }

    int query(int idx) {
        int sum = 0;
        for (; idx > 0; idx -= idx & -idx) {
            sum += bit[idx];
        }
        return sum;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> people(n);
    vector<int> b_coords;
    
    for (int i = 0; i < n; ++i) {
        cin >> people[i].first >> people[i].second;
        b_coords.push_back(people[i].second);
    }

    sort(b_coords.begin(), b_coords.end());
    b_coords.erase(unique(b_coords.begin(), b_coords.end()), b_coords.end());

    auto get_compressed_rank = [&](int val) {
        return lower_bound(b_coords.begin(), b_coords.end(), val) - b_coords.begin() + 1;
    };

    sort(people.begin(), people.end(), [](const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.first > p2.first;
    });

    long long total_greetings = 0;
    FenwickTree ft(b_coords.size());

    for (const auto& p : people) {
        int b = p.second;
        int compressed_b_rank = get_compressed_rank(b);

        total_greetings += ft.query(compressed_b_rank - 1);

        ft.update(compressed_b_rank, 1);
    }

    cout << total_greetings << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; 
    while (t--) {
        solve();
    }

    return 0;
}
