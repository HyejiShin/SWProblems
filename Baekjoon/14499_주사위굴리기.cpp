// 14499_ÃÃÂ»Ã§ÃÂ§Â±Â¼Â¸Â®Â±Ã¢
#include <iostream>
#include <vector>
using namespace std;

int N, M;
int x, y, nx, ny;
int K;
int map[21][21];
int dx[5] = { 0, 0, 0, -1, 1 };
int dy[5] = { 0, 1, -1, 0, 0 };
int dice[7], ndice[7];
vector<int> k;
int dir;

int main() {
	cin >> N >> M >> x >> y >> K;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < K; i++) {
		int dir;
		cin >> dir;
		k.push_back(dir);
	}

	for (int i = 0; i < K; i++) {
		dir = k[i];
		nx = x + dx[dir];
		ny = y + dy[dir];

		if (nx < 0 || nx >= N || ny < 0 || ny >= M)
			continue;

		switch (dir) {
		case 1:
			ndice[1] = dice[4];
			ndice[2] = dice[2];
			ndice[3] = dice[1];
			ndice[4] = dice[6];
			ndice[5] = dice[5];
			ndice[6] = dice[3];
			break;
		case 2:
			ndice[1] = dice[3];
			ndice[2] = dice[2];
			ndice[3] = dice[6];
			ndice[4] = dice[1];
			ndice[5] = dice[5];
			ndice[6] = dice[4];
			break;
		case 3:
			ndice[1] = dice[5];
			ndice[2] = dice[1];
			ndice[3] = dice[3];
			ndice[4] = dice[4];
			ndice[5] = dice[6];
			ndice[6] = dice[2];
			break;
		case 4:
			ndice[1] = dice[2];
			ndice[2] = dice[6];
			ndice[3] = dice[3];
			ndice[4] = dice[4];
			ndice[5] = dice[1];
			ndice[6] = dice[5];
			break;
		}

		if (map[nx][ny] == 0)
			map[nx][ny] = ndice[6];
		else {
			ndice[6] = map[nx][ny];
			map[nx][ny] = 0;
		}

		for (int i = 1; i <= 6; i++)
			dice[i] = ndice[i];

		x = nx; y = ny;
		cout << dice[1] << endl;

	}
	return 0;
}