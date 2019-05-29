//https://www.acmicpc.net/problem/4811
//4811_Â¾ÃÂ¾Ã 
//Â½ÃÂ°Â£ÃÃÂ°Ãº

#include<iostream>
#include<cstdio>

using namespace std;
int n;
long long ans[31][31];

long long solve(int w, int h) {
	if (w == 0 && h == 0) {
		return 1;
	}
	if (w > 0)
		solve(w - 1, h + 1);
	if (h > 0)
		solve(w, h - 1);
	return;
}

int main() {
	while (cin >> n) {
		if (n == 0)
			break;
		cout << solve(n, 0) << endl;
	}

	return 0;
}