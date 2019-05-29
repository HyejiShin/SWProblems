// https://www.acmicpc.net/problem/15683
// 15683_Â°Â¨Â½Ã

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

struct Info {
	int num;
	int x, y;
};
int N, M, mmax = 0;
int arr[9][9];
int temp[9][9];
vector<Info> cctv;
int zero = 0;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

void check(int dir, int x, int y) {
	int nx = x, ny = y;
	while (true) {
		nx += dx[dir];
		ny += dy[dir];
		if (nx < 0 || nx >= N || ny < 0 || ny >= M)
			break;
		if (temp[nx][ny] == 0)
			temp[nx][ny] = 7;
		else if (temp[nx][ny] == 6)
			break;
		else if (temp[nx][ny] >= 1 && temp[nx][ny] <= 5)
			continue;
	}
	return;
}

void solve(int idx) {
	// ÃÂ¾Â·Ã¡ ÃÂ¶Â°Ã
	if (idx == cctv.size()) {
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (temp[i][j] == 7)
					cnt++;
			}
		}
		mmax = max(mmax, cnt);
		return;
	}
	int x = cctv[idx].x;
	int y = cctv[idx].y;

	int ttemp[9][9] = { 0, };
	memcpy(ttemp, temp, sizeof(temp));
	
	int num = cctv[idx].num;
	switch (num) {
	case 1:
		for (int d = 0; d < 4; d++) {
			check(d, x, y);
			solve(idx + 1);
			memcpy(temp, ttemp, sizeof(ttemp));
		}
		break;
	case 2:
		for (int d = 0; d < 2; d++) {
			if (d == 0) {
				check(0, x, y);
				check(2, x, y);
			}
			else if (d == 1) {
				check(1, x, y);
				check(3, x, y);
			}
			solve(idx + 1);
			memcpy(temp, ttemp, sizeof(ttemp));
		}
		break;
	case 3:
		for (int d = 0; d < 4; d++) {
			if (d == 0) {
				check(0, x, y);
				check(3, x, y);
			}
			else if (d == 1) {
				check(0, x, y);
				check(1, x, y);
			}
			else if (d == 2) {
				check(1, x, y);
				check(2, x, y);
			}
			else if (d == 3) {
				check(2, x, y);
				check(3, x, y);
			}
			solve(idx + 1);
			memcpy(temp, ttemp, sizeof(ttemp));
		}
		break;
	case 4:
		for (int d = 0; d < 4; d++) {
			if (d == 0) {
				check(0, x, y);
				check(2, x, y);
				check(3, x, y);
			}
			else if (d == 1) {
				check(0, x, y);
				check(1, x, y);
				check(3, x, y);
			}
			else if (d == 2) {
				check(0, x, y);
				check(1, x, y);
				check(2, x, y);
			}
			else if (d == 3) {
				check(1, x, y);
				check(2, x, y);
				check(3, x, y);
			}
			solve(idx + 1);
			memcpy(temp, ttemp, sizeof(ttemp));
		}
		break;
	case 5:
		check(0, x, y);
		check(1, x, y);
		check(2, x, y);
		check(3, x, y);
		solve(idx + 1);
		memcpy(temp, ttemp, sizeof(ttemp));
		break;
	}
	return;
}
int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] >= 1 && arr[i][j] <= 5) {
				cctv.push_back({ arr[i][j], i, j });
			}
			if (arr[i][j] == 0)
				zero++;
		}
	}

	memcpy(temp, arr, sizeof(arr));

	solve(0);

	cout << zero - mmax << endl;
	return 0;
}