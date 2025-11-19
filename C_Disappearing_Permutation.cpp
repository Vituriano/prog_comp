#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void solve() {
    int n;
    cin >> n;
    
    vector<int> p(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }
    
    vector<int> d(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> d[i];
    }

    vector<bool> visited(n + 1, false);

    vector<int> cycle_id(n + 1, 0);

    vector<int> cycle_size;
    cycle_size.push_back(0);
    
    int current_cycle_idx = 0;

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            current_cycle_idx++; 
            int current_node = i;
            int count = 0;
            
            while (!visited[current_node]) {
                visited[current_node] = true;
                cycle_id[current_node] = current_cycle_idx; 
                count++; 
                current_node = p[current_node]; 
            }
            cycle_size.push_back(count);
        }
    }

    int happy_nodes = n;
    
    vector<bool> is_cycle_broken(current_cycle_idx + 1, false);
    
    for (int k = 1; k <= n; ++k) {
        int idx_to_delete = d[k];
        int c_id = cycle_id[idx_to_delete]; 

        if (!is_cycle_broken[c_id]) {
            is_cycle_broken[c_id] = true;
            happy_nodes -= cycle_size[c_id];
        }
        
        int ops = n - happy_nodes;
        cout << ops << (k == n ? "" : " ");
    }
    cout << "\n";
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
