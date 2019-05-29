// https://www.acmicpc.net/problem/3184
// 3184_Â¾Ã§

#include<iostream>

using namespace std;

char map[251][251];
int check[251][251];
int R, C;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };
int sheep = 0, wolf = 0;
void solve(int x, int y, int cnt) {

	for (int d = 0; d < 4; d++) {
		int nx = x + dx[d];
		int ny = y + dy[d];
		if (nx < 0 || nx >= R || ny < 0 || ny >= C || map[nx][ny] == '#' || check[nx][ny] != 0)
			continue;
		check[nx][ny] = cnt;
		if (map[nx][ny] == 'o') sheep++;
		else if (map[nx][ny] == 'v') wolf++;
		solve(nx, ny, cnt);
	}
	return;
}
int main() {
	cin >> R >> C;

	// Â¿Ã¯ÃÂ¸Â¸Â® : -1
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == '#')
				check[i][j] = -1;
		}
	}
	int s = 0, w = 0; // ÃÃÃÂ¾ Â¼Ã¶
	int cnt = 1;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] != '#' && check[i][j] == 0) {
				sheep = 0; wolf = 0;
				check[i][j] = cnt;
				if (map[i][j] == 'o') sheep++;
				else if (map[i][j] == 'v') wolf++;
				solve(i, j, cnt);
				cnt++;
				if (sheep > wolf)
					s += sheep;
				else
					w += wolf;
			}
		}
	}

	cout << s << ' ' << w << endl;

	return 0;
}