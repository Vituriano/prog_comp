#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canDivide(const vector<long long>& arr, int k, long long maxSum) {
	int cnt = 1;
	long long curr = 0;
	for (long long x : arr) {
		if (x > maxSum) return false;
		if (curr + x > maxSum) {
			cnt++;
			curr = x;
		} else {
			curr += x;
		}
	}
	return cnt <= k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n, k;
	cin >> n >> k;
	vector<long long> arr(n);
	for (int i = 0; i < n; ++i) cin >> arr[i];

	long long left = 1, right = 0;
	for (long long x : arr) right += x;
	long long answer = right;
	while (left <= right) {
		long long mid = left + (right - left) / 2;
		if (canDivide(arr, k, mid)) {
			answer = mid;
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}
	cout << answer << endl;
	return 0;
}
