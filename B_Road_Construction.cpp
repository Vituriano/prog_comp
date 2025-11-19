#include <iostream>
#include <vector>
#include <numeric> 
#include <algorithm>

using namespace std;

vector<int> parent;
vector<int> sz;

int find_set(int i) {
    if (parent[i] == i) {
        return i;
    }
    return parent[i] = find_set(parent[i]);
}

bool unite_sets(int a, int b, int& numComponents, int& maxSize) {
    a = find_set(a);
    b = find_set(b);

    if (a != b) {
        if (sz[a] < sz[b]) {
            swap(a, b);
        }
        parent[b] = a;
        sz[a] += sz[b];

        maxSize = max(maxSize, sz[a]);

        numComponents--;
        return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    parent.resize(n + 1);
    iota(parent.begin(), parent.end(), 0); 
    
    sz.assign(n + 1, 1);

    int numberOfComponents = n;
    int maxSize = 1;           

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;

        unite_sets(u, v, numberOfComponents, maxSize);

        cout << numberOfComponents << " " << maxSize << "\n";
    }

    return 0;
}
