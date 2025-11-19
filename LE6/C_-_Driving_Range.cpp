#include <iostream>
#include <vector>
#include <algorithm> 
#include <numeric>   

using namespace std;

struct Edge {
    int u, v;
    int w;

    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

struct DSU {
    vector<int> parent;
    int num_components; 

    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
        num_components = n;
    }

    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }

    bool unite(int i, int j) {
        int root_i = find(i);
        int root_j = find(j);
        
        if (root_i != root_j) {
            parent[root_i] = root_j;
            num_components--;
            return true;
        }
        return false;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    
    while (cin >> n >> m && (n != 0 || m != 0)) {
        
        vector<Edge> edges;
        for (int i = 0; i < m; ++i) {
            int u, v, w;
            cin >> u >> v >> w; 
            edges.push_back({u, v, w});
        }

        sort(edges.begin(), edges.end());

        DSU dsu(n);
        int max_range_needed = 0;

        for (const auto& edge : edges) {
            if (dsu.unite(edge.u, edge.v)) {
                max_range_needed = edge.w;
            }
        }

        if (dsu.num_components > 1) {
            cout << "IMPOSSIBLE\n";
        } else {
            cout << max_range_needed << "\n";
        }
    }

    return 0;
}
