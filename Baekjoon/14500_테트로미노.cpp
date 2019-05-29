// 14500_ÃÃÃÂ®Â·ÃÂ¹ÃÂ³Ã«

#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arr[501][501];
int check[501][501];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int mm = 0;

void solve(int x, int y, int cnt, int sum) {
	if (cnt == 4) {
		mm = max(sum, mm);
		return;
	}

	for (int d = 0; d < 4; d++) {
		int nx = x + dx[d];
		int ny = y + dy[d];
		if (check[nx][ny] == 0 && nx >= 0 && nx < N && ny >= 0 && ny < M) {
			check[nx][ny] = 1;
			solve(nx, ny, cnt + 1, sum + arr[nx][ny]);
			check[nx][ny] = 0;

			if (cnt == 2 && check[x][y] == 1) {
				check[nx][ny] = 1;
				solve(x, y, cnt + 1, sum + arr[nx][ny]);
				check[nx][ny] = 0;
			}

		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}
	int sum = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			check[i][j] = 1;
			solve(i, j, 1, arr[i][j]);
			check[i][j] = 0;
		}
	}

	cout << mm << endl;

	return 0;
}