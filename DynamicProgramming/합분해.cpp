#include<iostream>
using namespace std;

long long dp[201][201];  // dp[k][n] �迭 ����

int main() {
	int n, k;
	cin >> n >> k;  // n,k �Է�
	long long sum = 0;  // �����ܰ�(k-1)���� ���� �־��� n������ ���� ����ϱ� ����. 

	// k=1
	for (int i = 1; i < n + 1; i++) 
		dp[1][i] = 1;

	// k=2 ~ 
	for (int i = 2; i < k+1; i++) {      // i�� k, j�� n, m�� n������ �׻� dp[k-1][1]+dp[k-1][2]+...+dp[k-1][n]������ ���� ���ϱ� ���ؼ� loop ����
		for (int j = 1; j < n + 1; j++) {
			sum = 0;
			for (int m = 1; m < j+1; m++) {
				sum += dp[i-1][m]%1000000000;
			}
			dp[i][j] = (sum + 1) % 1000000000;  // +1�� �߰��Ǵ� ��� (0 ����� ��)
		}
	}

	cout << dp[k][n] % 1000000000;

	return 0;
}