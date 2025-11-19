#include <iostream>
#include <vector>

using ll = long long;

std::vector<ll> bit;
int n; 

void update(int k, ll delta) {
    for (; k <= n; k += k & -k) {
        bit[k] += delta;
    }
}

ll query(int k) {
    ll sum = 0;
    for (; k > 0; k -= k & -k) {
        sum += bit[k];
    }
    return sum;
}

ll range_sum(int a, int b) {
    return query(b) - query(a - 1);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int q;
    std::cin >> n >> q;

    bit.resize(n + 1, 0);
    
    std::vector<ll> initial_array(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        std::cin >> initial_array[i];
        update(i, initial_array[i]);
    }

    for (int i = 0; i < q; ++i) {
        int type;
        std::cin >> type;
        if (type == 1) {
            int k;
            ll u;
            std::cin >> k >> u;
            
            ll delta = u - initial_array[k];
            update(k, delta);
            
            initial_array[k] = u;

        } else {
            int a, b;
            std::cin >> a >> b;
            std::cout << range_sum(a, b) << "\n";
        }
    }

    return 0;
}
