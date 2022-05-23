#include<iostream>
using namespace std;

int main() {
	long long n;
	cin >> n;
	long long dp[101][10] = { 0 }; //N=1부터 시작이라 배열도 [1]부터 시작하려고 101개 할당
	long long sum = 0;

	// n = 1
	dp[1][0] = 0;
	for (int i = 1; i < 10; i++) {  //첫번째 경우는 0제외하고 1~9까지 다 1개씩 존재.
		dp[1][i] = 1; 
		sum += dp[1][i];
	}
	// n >= 2
	for (int i = 2; i <= n; i++) {
		sum = 0;
		for (int j = 0; j < 10; j++) {
			if (j == 0) {
				dp[i][j] = dp[i][j] + dp[i - 1][1]; // 0이 올때는 그 전 단계의 1이 왔을때 밖에 없음. 
			}
			else if (j == 9) {
				dp[i][j] += dp[i - 1][8]; //9가 올때는 전 단계의 8이 왔을때 밖에 없음.
			}
			else {
				dp[i][j] = dp[i - 1][j - 1] % 1000000000 + dp[i - 1][j + 1] % 1000000000; //나머지 경우는 전단계의 j-1과 전단계의 j+1일때 올 수 있음.
			}
			if (i == n) {
				sum += dp[i][j] % 1000000000;
			}
		}
	}
	
	cout << sum % 1000000000;

	return 0;
}