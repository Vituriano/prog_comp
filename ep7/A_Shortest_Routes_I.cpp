#include <iostream>
#include <vector>
#include <queue> 
#include <utility> 

using ll = long long;
const ll INF = 1e18;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<std::pair<int, int>>> adj(n + 1);

    for (int i = 0; i < m; ++i) {
        int a, b, c;
        std::cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    std::vector<ll> dist(n + 1, INF);
    std::priority_queue<std::pair<ll, int>, 
                        std::vector<std::pair<ll, int>>, 
                        std::greater<std::pair<ll, int>>> pq;

    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        ll d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) {
            continue;
        }

        for (auto& edge : adj[u]) {
            int v = edge.first;  
            int w = edge.second; 

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        std::cout << dist[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
