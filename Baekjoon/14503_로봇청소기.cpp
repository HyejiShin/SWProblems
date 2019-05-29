// https://www.acmicpc.net/problem/14503
// 14503_Â·ÃÂºÂ¿ÃÂ»Â¼ÃÂ±Ã¢

#include <iostream>

using namespace std;

int N, M;
int x, y, d, ans = 0;
int map[51][51];
int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
bool flag = false;

void solve(int x, int y, int d) {
	if (flag == false && map[x][y] == 0) {
		map[x][y] = 2;
		ans++;
	}

	for (int k = 1; k <= 4; k++) {
		int nx = x + dx[(d - k + 4) % 4];
		int ny = y + dy[(d - k + 4) % 4];


		if (map[nx][ny] == 0 && nx >= 0 && nx < N && ny >= 0 && ny < M) {
			solve(nx, ny, (d - k + 4) % 4);
			return;
		}
	}

	int nx = x + dx[(d + 2) % 4];
	int ny = y + dy[(d + 2) % 4];
	if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
		if (map[nx][ny] == 0 || map[nx][ny] == 2)
			solve(nx, ny, d);
		else if (map[nx][ny] == 1) {
			flag = true;
			return;
		}
	}
	return;
}

int main() {
	cin >> N >> M;
	cin >> x >> y >> d;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	solve(x, y, d);
	cout << ans << endl;
	return 0;
}