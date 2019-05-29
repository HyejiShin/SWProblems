// https://www.acmicpc.net/problem/1600
// 1600_Â¸Â»ÃÃ ÂµÃÂ°Ã­ÃÃ Â¿Ã¸Â¼Ã¾ÃÃ
// ÃÃÂ¼ÃÂ°Âª Â±Â¸ÃÃÂ´Ã Â¹Â®ÃÂ¦ÃÃÂ¹ÃÂ·Ã bfs
// Â¸ÃÂ¸Ã°Â¸Â® ÃÃÂ°Ãº--> ÃÂ¶Â°ÃÂ¹Â® ÃÃÂ³Âª Â´Ãµ ÃÃÂ°Â¡ --> visited[][][]

#include <iostream>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

struct Info {
	int x, y, k, cnt;
};
int K, W, H, ans;
int arr[205][205], v[205][205][31];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int ddx[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int ddy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
bool flag = false;

void bfs(int x, int y, int k, int cnt) {
	queue<Info> q;
	q.push({ x, y, k, cnt});
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int k = q.front().k;
		int cnt = q.front().cnt;
		q.pop();

		if (x == H - 1 && y == W - 1) {
			flag = true;
			ans = cnt;
			break;
		}

		if (k > 0) { // Â¸Â»Â·Ã ÃÃÂµÂ¿
			for (int i = 0; i < 8; i++) {
				int nx = x + ddx[i];
				int ny = y + ddy[i];
				if (nx < 0 || nx >= H || ny < 0 || ny >= W || arr[nx][ny] == 1 || v[nx][ny][k-1] == 1)
					continue;
				v[nx][ny][k - 1] = 1;
				q.push({nx, ny, k-1, cnt+1});
			}
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= H || ny < 0 || ny >= W || arr[nx][ny] == 1 || v[nx][ny][k] == 1)
				continue;
			v[nx][ny][k] = 1;
			q.push({ nx, ny, k, cnt + 1 });
		}
	}
}


int main() {
	cin >> K;
	cin >> W >> H;

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cin >> arr[i][j];
		}
	}

	bfs(0, 0, K, 0);
	if (flag == false)
		ans = -1;
	cout << ans << endl;
	return 0;
}