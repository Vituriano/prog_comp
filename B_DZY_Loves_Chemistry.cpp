#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class DSU {
private:
    vector<int> parent;
    int num_components;

public:
    DSU(int n) {
        num_components = n;
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int i) {
        if (parent[i] == i) {
            return i;
        }
        return parent[i] = find(parent[i]);
    }

    void unite(int a, int b) {
        int root_a = find(a);
        int root_b = find(b);
        if (root_a != root_b) {
            parent[root_b] = root_a;
            num_components--;
        }
    }

    int get_num_components() {
        return num_components;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    DSU dsu(n);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        dsu.unite(u, v);
    }

    int num_components = dsu.get_num_components();
    long long doublings = n - num_components;

    long long max_danger = 1LL << doublings;

    cout << max_danger << "\n";

    return 0;
}
