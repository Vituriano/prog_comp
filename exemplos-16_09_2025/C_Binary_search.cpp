#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int> &arr, int x)
{
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x)
        {
            return mid;
        }

        if (arr[mid] < x)
        {
            low = mid + 1;
        }

        if (arr[mid] > x)
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int N, Q;
    vector<int> array;

    cin >> N >> Q;

    for (int i = 0; i < N; ++i)
    {
        int a;
        cin >> a;
        array.push_back(a);
    }

    for (int i = 0; i < Q; ++i)
    {
        int query;
        cin >> query;
        cout << binarySearch(array, query) << '\n';
    }

    return 0;
}
