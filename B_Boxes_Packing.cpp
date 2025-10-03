#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    long long n;
    map<long long, long long> values;
    cin >> n;

    for (long long i = 0; i < n; ++i)
    {
        long long box;
        cin >> box;
        values[box]++;
    }
    long long count = 0;
    for (long long i = 1; i < values.size() - 1; ++i)
    {
        if (values[i - 1] > values[i])
        {
            count += values[i];
            values[i - 1] -= values[i];
        } else {
            count += values[i - 1];
            values[i - 1] = 0;
        }
    }

    cout << count  << "\n";

    return 0;
}

// 2 1 1

