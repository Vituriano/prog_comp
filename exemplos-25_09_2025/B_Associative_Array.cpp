#include <iostream>
#include <map>

using namespace std;

int main()
{
    // Aumentar a velocidade de entrada e saída
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int Q;
    cin >> Q;

    map<long long, long long> infinite_array;

    for (int i = 0; i < Q; ++i)
    {
        int type;
        cin >> type;

        if (type == 0)
        {
            long long k, v;
            cin >> k >> v;
            infinite_array[k] = v;
        }
        else if (type == 1)
        {
            long long k;
            cin >> k;

            auto it = infinite_array.find(k);

            if (it != infinite_array.end())
            {
                cout << it->second << "\n";
            }
            else
            {
                cout << 0 << "\n";
            }
        }
    }

    return 0;
}
