// https://www.acmicpc.net/problem/12872
// 12872_ÃÃÂ·Â¹ÃÃÂ¸Â®Â½ÂºÃÂ®
// variable range check!!

#include <iostream>

using namespace std;

int N, M, P;
int mod = 1e9 + 7;
long long dp[101][101];

int main() {
	cin >> N >> M >> P;

	// Â¸Ã°ÂµÃ§ Â³Ã«Â·Â¡Â¸Â¦ ÃÃÂ°Â¡ÃÃÂ¾Ã ÃÃ
	if (N > P) {
		cout << '0' << endl;
		return 0;
	}

	dp[0][0] = 1;

	for (int i = 1; i <= P; i++) {
		for (int j = 1; j <= N; j++) {
			dp[i][j] += dp[i - 1][j - 1] * (N - (j - 1));
			dp[i][j] %= mod;
			if (j > M) {
				dp[i][j] += dp[i - 1][j] * (j - M);
				dp[i][j] %= mod;
			}
		}
	}
	cout << dp[P][N] << endl;

	return 0;
}