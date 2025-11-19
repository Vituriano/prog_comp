#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;

void dfs(int node) {
    visited[node] = true;
    
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);
    visited.resize(n + 1, false); 

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> component_leaders;

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            component_leaders.push_back(i);
            dfs(i);
        }
    }

    int roads_needed = component_leaders.size() - 1;
    cout << roads_needed << "\n";

    for (int i = 1; i < component_leaders.size(); ++i) {
        cout << component_leaders[0] << " " << component_leaders[i] << "\n";
    }

    return 0;
}


// #include <iostream>
// #include <vector>

// using namespace std;

// vector<vector<int>> adj;

// vector<bool> visited;

// void dfs(int node) {
//     visited[node] = true;
    
//     for (int neighbor : adj[node]) {
//         if (!visited[neighbor]) {
//             dfs(neighbor);
//         }
//     }
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int n, m;
//     cin >> n >> m;

//     adj.resize(n + 1);
//     visited.resize(n + 1, false); 

//     for (int i = 0; i < m; ++i) {
//         int a, b;
//         cin >> a >> b;
//         adj[a].push_back(b);
//         adj[b].push_back(a);
//     }

//     vector<int> component_leaders;

//     for (int i = 1; i <= n; ++i) {
//         if (!visited[i]) {
//             component_leaders.push_back(i);
//             dfs(i);
//         }
//     }

//     int roads_needed = component_leaders.size() - 1;
//     cout << roads_needed << "\n";

//     for (int i = 1; i < component_leaders.size(); ++i) {
//         cout << component_leaders[0] << " " << component_leaders[i] << "\n";
//     }

//     return 0;
// }
