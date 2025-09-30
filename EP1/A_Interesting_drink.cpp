#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(vector<int> &arr, int x)
{
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] <= x)
        {
            low = mid + 1;
        }

        if (arr[mid] > x)
        {
            high = mid - 1;
        }
    }
    return low == 0 && arr[0] <= x ? 1 : low;
}

int main()
{

    int shops, days;
    vector<int> prices, budgets;

    cin >> shops;
    for (int i = 0; i < shops; ++i)
    {
        int price;
        cin >> price;
        prices.push_back(price);
    }

    cin >> days;
    for (int i = 0; i < days; ++i)
    {
        int coins;
        cin >> coins;
        budgets.push_back(coins);
    }

    sort(prices.begin(), prices.end(), less<int>());

    for (int j = 0; j < days; ++j)
    {
        int storeCount = binarySearch(prices, budgets[j]);
        cout << storeCount << "\n";
    }

    return 0;
}
