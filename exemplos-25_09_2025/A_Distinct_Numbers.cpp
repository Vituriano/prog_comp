#include <iostream>
#include <set>

using namespace std;

int main()
{

    int n;
    set<int> values;

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        values.insert(a);
    }

    cout << values.size();

    return 0;
}
