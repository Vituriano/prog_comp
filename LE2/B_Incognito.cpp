#include <iostream>
#include <string>
#include <map>

using namespace std;

void solve() {
    int n;
    cin >> n;

    map<string, int> categories;
    for (int i = 0; i < n; ++i) {
        string name, category;
        cin >> name >> category;
        categories[category]++;
    }

    long long result = 1;
    for (auto const& [category, count] : categories) {
        result *= (count + 1);
    }
    
    result -= 1;

    cout << result << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test_cases;
    cin >> test_cases;
    while (test_cases--) {
        solve();
    }

    return 0;
}
