// https://www.acmicpc.net/problem/4811
// 4811_Â¾ÃÂ¾Ã 
// DP

#include<iostream>
#include<string> // stringÃÂ» Â¾Â²Â±Ã¢ ÃÂ§ÃÃ ÃÃ¬Â´Ãµ
#include<cstring>

using namespace std;

int n;
long long arr[32][32] = {0,};

long long solve(int w, int h) {
	if (w == 0) return 1;
	else if (w + h > n) return 0;
	else if (arr[w][h] > 0) return arr[w][h];
	else return arr[w][h] = solve(w-1, h) + solve(w, h+1);
}

int main() {
	while (cin >> n) {
		if (n == 0)
			break;
		memset(arr, 0, sizeof(arr));
		cout << solve(n - 1, 0) << endl;
	}

	return 0;
}