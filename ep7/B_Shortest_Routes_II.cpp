#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;
const ll INF = 1e18;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m, q;
    std::cin >> n >> m >> q;

    std::vector<std::vector<ll>> dist(n + 1, std::vector<ll>(n + 1, INF));

    for (int i = 1; i <= n; ++i) {
        dist[i][i] = 0;
    }

    for (int i = 0; i < m; ++i) {
        int a, b;
        ll c;
        std::cin >> a >> b >> c;
        dist[a][b] = std::min(dist[a][b], c);
        dist[b][a] = std::min(dist[b][a], c);
    }

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int i = 0; i < q; ++i) {
        int a, b;
        std::cin >> a >> b;

        ll d = dist[a][b];
        
        if (d == INF) {
            std::cout << -1 << "\n";
        } else {
            std::cout << d << "\n";
        }
    }

    return 0;
}
