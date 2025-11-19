#include <iostream>
#include <vector>
using namespace std;

const int N = 8;
char board[N][N];
int res = 0;
bool col[N], diag1[2*N-1], diag2[2*N-1];

void solve(int row) {
	if (row == N) {
		res++;
		return;
	}
	for (int c = 0; c < N; ++c) {
		if (board[row][c] == '*' || col[c] || diag1[row+c] || diag2[row-c+N-1]) continue;
		col[c] = diag1[row+c] = diag2[row-c+N-1] = true;
		solve(row+1);
		col[c] = diag1[row+c] = diag2[row-c+N-1] = false;
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	for (int i = 0; i < N; ++i)
		for (int j = 0; j < N; ++j)
			cin >> board[i][j];
	solve(0);
	cout << res << endl;
	return 0;
}
