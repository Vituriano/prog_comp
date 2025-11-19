#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<int> h(N);
    for (int i = 0; i < N; i++)
    {
        cin >> h[i];
    }

    vector<int> dp(N, INF);
    dp[0] = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 1; j <= K && i + j < N; j++)
        {
            dp[i + j] = min(dp[i + j], dp[i] + abs(h[i] - h[i + j]));
        }
    }

    cout << dp[N - 1] << endl;

    return 0;
}
