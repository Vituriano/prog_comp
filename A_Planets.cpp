#include <iostream>
#include <map>

using namespace std;

int main()
{

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i)
    {
        int n, c;
        map<long long, long long> planets;
        cin >> n >> c;
        for (int j = 0; j < n; ++j)
        {
            long long orbita;
            cin >> orbita;
            planets[orbita]++;
        }
        long long count = 0;
        for (const auto &planet : planets)
        {
            if (planet.second > 1 && planet.second >= c)
            {
                count += c;
            }
            else
            {
                count += planet.second;
            }
        }
        cout << count << "\n";
    }
    return 0;
}
