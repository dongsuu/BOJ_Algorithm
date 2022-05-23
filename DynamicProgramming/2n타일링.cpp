#include<iostream>
using namespace std;
long long memo[1000] = { 0 };

long long two_n_tiling(long long n) {
	for (int i = 3; i <= n; i++) {
		memo[i] = (memo[i - 1] + memo[i - 2]) % 10007;
	}
	return memo[n];
}
int main() {
	memo[1] = 1;
	memo[2] = 2;
	long long n;
	cin >> n;
	cout << two_n_tiling(n);
	return 0;
}