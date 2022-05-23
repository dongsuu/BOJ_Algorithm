#include<iostream>
using namespace std;
long long GCD(long long a, long long b) {
	if (b == 0)
		return a;
	else
		return GCD(b, a % b);
}

int main() {
	long long n, s;
	long long result;
	cin >> n >> s;
	long long* arr = new long long[n];
	long long* temp = new long long[n];

	for (long long i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (long long i = 0; i < n; i++) {
		if (s - arr[i] > 0)
			temp[i] = s - arr[i];
		else
			temp[i] = arr[i] - s;
	}
	if (n == 1)
		cout << temp[0];
	else {
		for (long long i = 0; i < n-1; i++) {
			if (i == 0)
				result = GCD(temp[i], temp[i + 1]);

			else
				result = GCD(result, temp[i + 1]);
		}
		cout << result;
	}

	return 0;
}