// https://www.acmicpc.net/problem/10026
// 10026_ÃÃ»Â·ÃÂ»Ã¶Â¾Ã 

#include <iostream>
#include <cstring>

using namespace std;

int N, ans1 = 0, ans2 = 0;
char arr[101][101];
int check[101][101];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

void solve2(int x, int y, int cnt) {
	for (int d = 0; d < 4; d++) {
		int nx = x + dx[d];
		int ny = y + dy[d];
		if (nx < 0 || nx >= N || ny < 0 || ny >= N ) {
			continue;
		}
		if (arr[x][y] == 'R' || arr[x][y] == 'G') {
			if (check[nx][ny] == 0 && (arr[nx][ny] =='R' || arr[nx][ny] == 'G')) {
				check[nx][ny] = cnt;
				solve2(nx, ny, cnt);
			}
		}
		else if (arr[x][y] == 'B') {
			if (check[nx][ny] == 0 && arr[nx][ny] == 'B') {
				check[nx][ny] = cnt;
				solve2(nx, ny, cnt);
			}
		}
	}	
	return;
}

void solve1(int x, int y, int cnt) {
	for (int d = 0; d < 4; d++) {
		int nx = x + dx[d];
		int ny = y + dy[d];
		if (nx < 0 || nx >= N || ny < 0 || ny >= N || arr[x][y] != arr[nx][ny]) {
			continue;
		}
		if (check[nx][ny] == 0 && arr[nx][ny] == arr[x][y]) {
			check[nx][ny] = cnt;
			solve1(nx, ny, cnt);
		}
	}
	return;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (check[i][j] == 0) {
				ans1++;
				solve1(i, j, ans1);
			}
		}
	}

	memset(check, 0, sizeof(check));
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (check[i][j] == 0) {
				ans2++;
				solve2(i, j, ans2);
			}

		}
	}

	cout << ans1 << ' ' << ans2 << endl;
	return 0;
}