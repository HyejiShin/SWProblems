// https://www.acmicpc.net/problem/2163
// 2163_ÃÃÃÃÂ¸Â´ ÃÃÂ¸Â£Â±Ã¢

#include <iostream>

using namespace std;

int N, M, ans = 0;

int main() {
	cin >> N >> M;
	if (N >= M) {
		ans += N - 1;
		ans += (M-1) * N;
	}
	else if (N < M) {
		ans += M - 1;
		ans += M * (N - 1);
	}
	cout << ans << endl;
	// cout << N*M-1 << endl;
	return 0;
}