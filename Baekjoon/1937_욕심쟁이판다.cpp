// https://www.acmicpc.net/problem/1937
// 1937_Â¿Ã¥Â½ÃÃÃ¯ÃÃ ÃÃÂ´Ã_Â½ÃÂ°Â£ÃÃÂ°Ãº

#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>

using namespace std;

int N;
int mmax = 0;
int d[501][501] = { 0, };
int map[501][501] = { 0, };
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

void solve(int x, int y) {
	int val = 0;
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx < 0 || nx >= N || ny < 0 || ny >= N || map[nx][ny] <= map[x][y] )
			continue;
		if (d[nx][ny] == 0)
			solve(nx, ny);
		val = max(val, d[nx][ny]);
	}
	d[x][y] = val + 1;
	mmax = max(mmax, d[x][y]);
	return;
}

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (d[i][j] == 0) {
				solve(i, j);
			}
		}
	}

	cout << mmax << endl;
	return 0;
}
