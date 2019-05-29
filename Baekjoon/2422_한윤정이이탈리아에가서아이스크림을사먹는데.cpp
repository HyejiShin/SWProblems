// https://www.acmicpc.net/problem/2422
// 2422_ÃÃÃÂ±ÃÂ¤ÃÃ ÃÃÃÂ»Â¸Â®Â¾ÃÂ¿Â¡ Â°Â¡Â¼Â­ Â¾ÃÃÃÂ½ÂºÃÂ©Â¸Â²ÃÂ» Â»Ã§Â¸ÃÂ´ÃÂµÂ¥

#include <iostream>
#include <vector>

using namespace std;

int N, M, cnt = 0, first;
int ice[201][201] = { 0, };

void solve(int idx, int count) {
	if (count == 3) {
		cnt++;
		return;
	}
	for (int i = idx + 1; i <= N; i++) {
		if (ice[idx][i] == 0) {
			if(count == 2 && ice[first][i] == 0)
				solve(i, count + 1);
			else if(count < 2)
				solve(i, count + 1);
		}
	}
	return;
}

int main() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		ice[i][i] = 1;
	}

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		ice[a][b] = 1; // Â°Â°ÃÃ Â¸ÃÃÂ¸Â¸Ã© Â¾ÃÂµÃÂ´Ã ÃÂ¶ÃÃ
		ice[b][a] = 1;
	}

	for (int i = 1; i <= N; i++) {
		first = i;
		solve(i, 1);
	}

	cout << cnt << endl;

	return 0;
}