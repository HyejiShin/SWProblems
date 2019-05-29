// https://www.acmicpc.net/problem/3085
// 3085_Â»Ã§ÃÃÂ°ÃÃÃ

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N, mmax = 0;
char arr[51][51];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

void maxCount() {

	for (int i = 0; i < N; i++) {
		int cnt = 1;
		for (int j = 0; j < N - 1; j++) {
			if (arr[i][j] != arr[i][j + 1]) {
				mmax = max(mmax, cnt);
				cnt = 1;
			}
			else {
				cnt++;
				if (j == N - 2)
					mmax = max(mmax, cnt);
			}
		}
		mmax = max(mmax, cnt);
	}

	for (int i = 0; i < N; i++) {
		int cnt = 1;
		for (int j = 0; j < N - 1; j++) {
			if (arr[j][i] != arr[j + 1][i]) {
				mmax = max(mmax, cnt);
				cnt = 1;
			}
			else {
				cnt++;
				if (j == N - 2)
					mmax = max(mmax, cnt);
			}
		}
		mmax = max(mmax, cnt);
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
			int x = i, y = j;
			for (int d = 0; d < 4; d++) {
				int nx = x + dx[d];
				int ny = y + dy[d];

				if (nx < 0 || nx >= N || ny < 0 || ny >= N)
					continue;

				if (arr[x][y] != arr[nx][ny]) {
					char c = arr[x][y];
					arr[x][y] = arr[nx][ny];
					arr[nx][ny] = c;

					maxCount();

					arr[nx][ny] = arr[x][y];
					arr[x][y] = c;
				}

			}
		}
	}

	cout << mmax << endl;
	return 0;
}