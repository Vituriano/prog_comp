#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    int W;

    cin >> N >> W;

    vector<long long> dp(W + 1, 0);

    for (int i = 0; i < N; ++i)
    {
        int w;
        long long v;
        cin >> w >> v;

        for (int j = W; j >= w; --j)
        {
            dp[j] = max(dp[j], v + dp[j - w]);
        }
    }
    cout << dp[W] << endl;

    return 0;
}
