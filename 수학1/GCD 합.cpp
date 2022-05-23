#include<iostream>
using namespace std;

long long GCD(long long a, long long b) {
	if (b == 0)
		return a;

	return GCD(b, a % b);
}

int main() {
	int t_case;
	cin >> t_case;
	while (t_case--) {
		int n;
		long long result = 0;

		cin >> n;
		int *arr = new int[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		for (int i = 0; i < n-1; i++) {
			for (int j = i+1; j < n; j++) {
				result += GCD(arr[i], arr[j]);
			}
		}
		cout << result << '\n';
	}
	return 0;
}