#include<iostream>
using namespace std;

long long dp[201][201];  // dp[k][n] 배열 선언

int main() {
	int n, k;
	cin >> n >> k;  // n,k 입력
	long long sum = 0;  // 이전단계(k-1)에서 현재 주어진 n까지의 합을 계산하기 위함. 

	// k=1
	for (int i = 1; i < n + 1; i++) 
		dp[1][i] = 1;

	// k=2 ~ 
	for (int i = 2; i < k+1; i++) {      // i는 k, j는 n, m은 n에따라 항상 dp[k-1][1]+dp[k-1][2]+...+dp[k-1][n]까지의 합을 구하기 위해서 loop 돌림
		for (int j = 1; j < n + 1; j++) {
			sum = 0;
			for (int m = 1; m < j+1; m++) {
				sum += dp[i-1][m]%1000000000;
			}
			dp[i][j] = (sum + 1) % 1000000000;  // +1은 추가되는 경우 (0 사용한 것)
		}
	}

	cout << dp[k][n] % 1000000000;

	return 0;
}