#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n, m;
vector<string> grid;
vector<vector<bool>> visited;

void dfs(int r, int c) {
    if (r < 0 || r >= n) {
        return;
    }
    if (c < 0 || c >= m) {
        return;
    }
    if (grid[r][c] == '#') {
        return;
    }
    if (visited[r][c]) {
        return;
    }
    
    visited[r][c] = true;
    
    dfs(r + 1, c);
    dfs(r - 1, c);
    dfs(r, c + 1);
    dfs(r, c - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    grid.resize(n);
    visited.resize(n, vector<bool>(m, false));

    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
    }

    int room_count = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == '.' && !visited[i][j]) {
                room_count++;
                dfs(i, j);
            }
        }
    }

    cout << room_count << "\n";

    return 0;
}


// #include <iostream>
// #include <vector>
// #include <string>

// using namespace std;

// int n, m;
// vector<string> grid;
// vector<vector<bool>> visited;

// void dfs(int r, int c) {
//     if (r < 0 || r >= n) {
//         return;
//     }
//     if (c < 0 || c >= m) {
//         return;
//     }
//     if (grid[r][c] == '#') {
//         return;
//     }
//     if (visited[r][c]) {
//         return;
//     }
    
//     visited[r][c] = true;
    
//     dfs(r + 1, c);
//     dfs(r - 1, c);
//     dfs(r, c + 1);
//     dfs(r, c - 1);
// }

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     cin >> n >> m;

//     grid.resize(n);
//     visited.resize(n, vector<bool>(m, false));

//     for (int i = 0; i < n; ++i) {
//         cin >> grid[i];
//     }

//     int room_count = 0;

//     for (int i = 0; i < n; ++i) {
//         for (int j = 0; j < m; ++j) {
            
//             if (grid[i][j] == '.' && !visited[i][j]) {
//                 room_count++;
                
//                 dfs(i, j);
//             }
//         }
//     }

//     cout << room_count << "\n";

//     return 0;
// }
