#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <tuple>

using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    vector<string> S(H);
    for (int i = 0; i < H; ++i) {
        cin >> S[i];
    }

    string target = "snuke";

    if (S[0][0] != target[0]) {
        cout << "No" << endl;
        return 0;
    }

    vector<vector<vector<bool>>> visited(H, vector<vector<bool>>(W, vector<bool>(5, false)));

    queue<tuple<int, int, int>> q;

    q.push({0, 0, 0});
    visited[0][0][0] = true;

    int dr[] = {0, 0, 1, -1};
    int dc[] = {1, -1, 0, 0};

    while (!q.empty()) {
        auto [r, c, k] = q.front();
        q.pop();

        int next_k = (k + 1) % 5;
        char next_char = target[next_k];

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nr >= H || nc < 0 || nc >= W) {
                continue;
            }

            if (S[nr][nc] != next_char) {
                continue;
            }

            if (visited[nr][nc][next_k]) {
                continue;
            }

            visited[nr][nc][next_k] = true;
            q.push({nr, nc, next_k});
        }
    }

    bool reached = false;
    for (int k = 0; k < 5; ++k) {
        if (visited[H - 1][W - 1][k]) {
            reached = true;
            break;
        }
    }

    if (reached) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
