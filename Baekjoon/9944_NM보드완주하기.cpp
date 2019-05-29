// https://www.acmicpc.net/problem/9944
// 9944_N*M ÂºÂ¸ÂµÃ¥ Â¿ÃÃÃÃÃÂ±Ã¢

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <limits.h>

using namespace std;

int map[31][31];
int visited[31][31];
int N, M, cnt, ans;
char c;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

void solve(int x, int y, int turn, int cnt) {
	//  Â¸ÃÃÃº ÃÂ¾Â·Ã¡ÃÂ¶Â°ÃÂºÃÃÃ ÃÂ®ÃÃ
	if (cnt == 0) {
		if (ans > turn)
			ans = turn;
		return;
	}

	visited[x][y] = 1;
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];

		if (nx < 0 || nx >= N || ny < 0 || ny >= M || map[nx][ny] == 1 || visited[nx][ny] == 1)
			continue;

		int move = 0;

		while (1) {
			if (nx < 0 || nx >= N || ny < 0 || ny >= M || map[nx][ny] == 1 || visited[nx][ny] == 1)
				break;
			visited[nx][ny] = 1;
			nx += dx[k];
			ny += dy[k];
			move++;
		}

		nx -= dx[k];
		ny -= dy[k];
		solve(nx, ny, turn + 1, cnt - move);

		while (1) {
			if (nx == x && ny == y)
				break;
			visited[nx][ny] = 0;
			nx -= dx[k];
			ny -= dy[k];
		}
	}

	visited[x][y] = 0;
}

int main() {
	int tc = 1;
	while (cin >> N >> M) {
		cnt = N * M;
		ans = cnt;
		memset(visited, 0, sizeof(visited));

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> c;
				if (c == '*') {
					map[i][j] = 1;
					cnt--;
				}
				else if (c == '.')
					map[i][j] = 0;
			}
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] == 0) {
					solve(i, j, 0, cnt - 1);
				}
			}
		}

		if (ans == N * M)
			ans = -1;
		cout << "Case " << tc << ": " << ans << endl;
		tc++;
	}
	return 0;
}