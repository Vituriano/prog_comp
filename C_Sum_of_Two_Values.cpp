#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    long long n, x;
    cin >> n >> x;
    map<long long, vector<long long>> values;
    for (long long i = 0; i < n; ++i)
    {
        long long v;
        cin >> v;
        values[v].push_back(i + 1);
    }

    for (const auto &v : values)
    {
        long long complement = x - v.first;
        if (values.find(complement) != values.end())
        {
            if (v.second[0] == values[complement][0])
            {
                cout << v.second[0] << " " << v.second[1] << "\n";
            }
            else
            {
                if (v.second[0] > values[complement][0])
                {
                    cout << values[complement][0] << " " << v.second[0] << "\n";
                }
                else
                {
                    cout << v.second[0] << " " << values[complement][0] << "\n";
                }
            }

            return 0;
        }
    }
    cout << "IMPOSSIBLE";

    return 0;
}
