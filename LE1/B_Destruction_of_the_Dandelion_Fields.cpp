#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <functional>
#include <cmath> 

void solve() {
    int n;
    std::cin >> n;

    std::vector<long long> odds;
    std::vector<long long> evens;

    for (int i = 0; i < n; ++i) {
        long long a;
        std::cin >> a;
        if (a % 2 != 0) {
            odds.push_back(a);
        } else {
            evens.push_back(a);
        }
    }

    if (odds.empty()) {
        std::cout << 0 << std::endl;
        return;
    }

    long long total_dandelions = 0;
    for (long long val : evens) {
        total_dandelions += val;
    }
    
    std::sort(odds.begin(), odds.end(), std::greater<long long>());

    int num_odds_to_cut = ceil(odds.size() / 2.0);

    for (int i = 0; i < num_odds_to_cut; ++i) {
        total_dandelions += odds[i];
    }

    std::cout << total_dandelions << std::endl;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
