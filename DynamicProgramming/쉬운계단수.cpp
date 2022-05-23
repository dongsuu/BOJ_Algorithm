#include<iostream>
using namespace std;

int main() {
	long long n;
	cin >> n;
	long long dp[101][10] = { 0 }; //N=1���� �����̶� �迭�� [1]���� �����Ϸ��� 101�� �Ҵ�
	long long sum = 0;

	// n = 1
	dp[1][0] = 0;
	for (int i = 1; i < 10; i++) {  //ù��° ���� 0�����ϰ� 1~9���� �� 1���� ����.
		dp[1][i] = 1; 
		sum += dp[1][i];
	}
	// n >= 2
	for (int i = 2; i <= n; i++) {
		sum = 0;
		for (int j = 0; j < 10; j++) {
			if (j == 0) {
				dp[i][j] = dp[i][j] + dp[i - 1][1]; // 0�� �ö��� �� �� �ܰ��� 1�� ������ �ۿ� ����. 
			}
			else if (j == 9) {
				dp[i][j] += dp[i - 1][8]; //9�� �ö��� �� �ܰ��� 8�� ������ �ۿ� ����.
			}
			else {
				dp[i][j] = dp[i - 1][j - 1] % 1000000000 + dp[i - 1][j + 1] % 1000000000; //������ ���� ���ܰ��� j-1�� ���ܰ��� j+1�϶� �� �� ����.
			}
			if (i == n) {
				sum += dp[i][j] % 1000000000;
			}
		}
	}
	
	cout << sum % 1000000000;

	return 0;
}