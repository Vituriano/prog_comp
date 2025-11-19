#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<long long> a(n);
		long long sum = 0;
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			sum += a[i];
		}
		if (n == 1) {
			cout << "-1\n";
			continue;
		}
		sort(a.begin(), a.end());
		long long richest = a[n-1];
		long long left = 0, right = 2e12, answer = -1;
		while (left <= right) {
			long long x = (left + right) / 2;
			long long new_sum = sum + x;
			double avg = new_sum * 1.0 / n;
			double unhappy_threshold = avg / 2.0;
			int unhappy = 0;
			for (int i = 0; i < n-1; ++i) {
				if (a[i] < unhappy_threshold) ++unhappy;
			}
			if (richest + x < unhappy_threshold) ++unhappy;
			if (unhappy > n / 2) {
				answer = x;
				right = x - 1;
			} else {
				left = x + 1;
			}
		}
		cout << answer << "\n";
	}
	return 0;
}
