// https://www.acmicpc.net/problem/16198
// 16198_Â¿Â¡Â³ÃÃÃ¶ Â¸Ã°ÃÂ¸Â±Ã¢

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Info {
	int num;
	int check;
};
int N, mmax = 0, temp = 0;
vector<Info> list;

void solve(int idx, int cnt) {
	if (cnt == N-2) {
		//cout << temp << endl;
		mmax = max(temp, mmax);
		return;
	}

	for (int i = 1; i < N - 1; i++) {
		if (list[i].check == 0) {
			int s = i, e = i;
			list[i].check = 1;
			while (list[s].check != 0) {
				s--;
			}
			while (list[e].check != 0) {
				e++;
			}
			temp += list[s].num * list[e].num;
			solve(i, cnt + 1);
			temp -= list[s].num * list[e].num;
			list[i].check = 0;
		}
	}
	return;
}

int main() {
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		list.push_back({a, 0});
	}

	for (int i = 1; i < N-1; i++) {
		list[i].check = 1;
		temp += list[i - 1].num * list[i + 1].num;
		//cout << temp << endl;
		solve(i, 1);
		temp -= list[i - 1].num * list[i + 1].num;
		list[i].check = 0;
	}

	cout << mmax << endl;
	
	return 0;
}