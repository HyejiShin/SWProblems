// https://www.acmicpc.net/problem/2290
// LCD Test

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int s;
string n;

void print1() {
	for (int i = 0; i < s + 2; i++) {
		cout << ' ';
	}
}

void print2() {
	cout << ' ';
	for (int i = 0; i < s; i++) {
		cout << '-';
	}
	cout << ' ';
}

void print3() {
	for (int i = 0; i < s + 1; i++) {
		cout << ' ';
	}
	cout << '|';
}

void print4() {
	cout << '|';
	for (int i = 0; i < s + 1; i++) {
		cout << ' ';
	}
}

void print5() {
	cout << '|';
	for (int i = 0; i < s; i++) {
		cout << ' ';
	}
	cout << '|';
}
void solve(int line, int j) {
	if (line == 0) {
		if (n[j] == '1' || n[j] == '4') {
			print1();
		}
		else {
			print2();
		}
	}
	else if (line == 1) {
		if (n[j] == '1' || n[j] == '2' || n[j] == '3' || n[j] == '7') {
			print3();
		}
		else if (n[j] == '5' || n[j] == '6') {
			print4();
		}
		else {
			print5();
		}
	}
	else if (line == 2) {
		if (n[j] == '1' || n[j] == '7' || n[j] == '0') {
			print1();
		}
		else {
			print2();
		}
	}
	else if (line == 3) {
		if (n[j] == '1' || n[j] == '3' || n[j] == '4' || n[j] == '5' || n[j] == '7' || n[j] == '9') {
			print3();
		}
		else if (n[j] == '2') {
			print4();
		}
		else {
			print5();
		}
	}

	else if (line == 4) {
		if (n[j] == '1' || n[j] == '4' || n[j] == '7') {
			print1();
		}
		else{
			print2();
		}
	}
	return;
}

int main() {
	cin >> s;
	cin >> n;

	for (int i = 0; i < 5; i++) {
		if (i == 1 || i == 3) {
			for (int k = 0; k < s; k++) {
				for (int j = 0; j < n.length(); j++) {
					solve(i, j);
					cout << ' ';
				}
				cout << endl;
			}
		}
		else {
			for (int j = 0; j < n.length(); j++) {
				solve(i, j);
				cout << ' ';
			}
			cout << endl;
		}
	}
	return 0;
}
