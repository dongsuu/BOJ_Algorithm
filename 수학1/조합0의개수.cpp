#include<iostream>
using namespace std;

int main() {
	long long n, m;
	long long five = 0;
	long long two = 0;
	cin >> n >> m;

	for (long long i = 5; i <= n; i*=5) {
		five += n / i;
	}
	for (long long i = 5; i <= m; i*=5) {
		five -= m / i;
	}
	for (long long i = 5; i <= n - m; i *= 5) {
		five -= (n - m) / i;
	}
	
	for (long long i = 2; i <= n; i *= 2) {
		two += n / i;
	}
	for (long long i = 2; i <= m; i *= 2) {
		two -= m / i;
	}
	for (long long i = 2; i <= n - m; i *= 2) {
		two -= (n - m) / i;
	}
	long long result = five > two ? two : five;
	cout << result;
	return 0;
}