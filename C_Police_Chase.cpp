#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_N = 501;

int n, m;
int capacity[MAX_N][MAX_N];
vector<pair<int, int>> original_edges;
int parent[MAX_N];

bool bfs(int s, int t)
{
    for (int i = 1; i <= n; ++i)
    {
        parent[i] = 0;
    }

    queue<int> q;
    q.push(s);
    parent[s] = -1;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v = 1; v <= n; ++v)
        {
            if (parent[v] == 0 && capacity[u][v] > 0)
            {
                parent[v] = u;
                q.push(v);
                if (v == t)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            capacity[i][j] = 0;
        }
    }

    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        capacity[a][b] = 1;
        capacity[b][a] = 1;
        original_edges.push_back({a, b});
    }

    int source = 1;
    int sink = n;
    int max_flow = 0;

    while (bfs(source, sink))
    {
        max_flow++;

        int v = sink;
        while (v != source)
        {
            int u = parent[v];
            capacity[u][v]--;
            capacity[v][u]++;
            v = u;
        }
    }

    vector<bool> reachable(n + 1, false);
    queue<int> q;

    q.push(source);
    reachable[source] = true;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v = 1; v <= n; ++v)
        {
            if (!reachable[v] && capacity[u][v] > 0)
            {
                reachable[v] = true;
                q.push(v);
            }
        }
    }

    vector<pair<int, int>> cut_edges;
    for (const auto &edge : original_edges)
    {
        int u = edge.first;
        int v = edge.second;
        if (reachable[u] != reachable[v])
        {
            cut_edges.push_back(edge);
        }
    }

    cout << cut_edges.size() << endl;
    for (const auto &edge : cut_edges)
    {
        cout << edge.first << " " << edge.second << endl;
    }

    return 0;
}
