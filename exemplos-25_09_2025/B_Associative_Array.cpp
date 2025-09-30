#include <iostream>
#include <set>
#include <vector>

using namespace std;

int query(vector<int> &a)
{


    return 0;
}

int main()
{
    int q;

    cin >> q;

    for (int i = 0; i < q; ++i)
    {
        vector<int> a;
        int value;
        cin >> value;
        a.push_back(value);
        cout << query(a) << "\n";
    }

    return 0;
}
