#include<iostream>
using namespace std;
int memo[1000000] = {0}; //횟수 0으로 초기화 시켜줌. 

int makeOne(int n) {
	if (n == 1) //1인 경우는 연산결과가 0이므로 0출력해준다. 
		return 0;
	if (memo[n] > 0)
		return memo[n]; //메모리제이션. 이미 값이 있으면 이 값을 return한다.
	/*
		연산들을 점화식으로 나타내면 
		D[n] = 1 + D[n-1] 
		D[n] = 1 + D[n/2]
		D[n] = 1 + D[n/3] 이다. (1이 연산 횟수 추가)
	*/
	memo[n] = 1 + makeOne(n-1); 
	if (n % 2 == 0) {
		int temp = 1 + makeOne(n / 2);
		if (memo[n] > temp) //처음에 -1연산 되어있는 것이 memo에 다 저장되어있다. 따라서
			memo[n] = temp; //n/2 연산을 한 것이 횟수가 더 작다면 memo에 n/2의 연산 횟수 값을 저장해줘야한다. 
	}
	if (n % 3 == 0) {
		int temp = 1 + makeOne(n / 3);
		if (memo[n] > temp) //n/2연산과 동일한 원리.. 
			memo[n] = temp;
	}
	return memo[n];
}
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n;
	
	cin >> n;
	memo[1] = 0;
	cout << makeOne(n);
	return 0;
}