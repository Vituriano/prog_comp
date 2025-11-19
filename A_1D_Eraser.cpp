#include <iostream>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int operations = 0;
    for (int i = 0; i < n;)
    {
        if (s[i] == 'B')
        {
            operations++;
            i += k;
        }
        else
        {
            i++;
        }
    }

    cout << operations << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
