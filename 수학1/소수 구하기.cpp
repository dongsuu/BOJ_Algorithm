#include<iostream>
using namespace std;

int main() {
	int m, n;
	int min = 2; //에라토스테네스의 체에서 2부터 시작하므로 초기값 2로 함. 
	cin >> m >> n; //m이상 n이하 입력
	int* prime = new int[n+1]; //index 0은 사용하지 않을거라 n+1로 동적 할당 해줌. 
	bool* check = new bool[n+1];

	for (int i = 2; i <= n; i++) { //2부터 n까지 모든 수 써두기
		prime[i] = i;
	}

	for (int i = 1; i <= n; i++) { //지워지지 않은 것은 모두 초기값으로 false로 설정.
		check[i] = false;          //즉, 지워지면 true, 지워지지 않으면 false로 됨. 
	}

	for (int i = min; i <= n; i++) {
		min = prime[i]; //가장 작은 값을 찾는다.(지워진 수였다면 밑에 if문이 실행되지않아 다음반복으로 넘어가서 결국 if문 실행될때 min은 지워지지 않은 수임.)
		if (check[i] == false) {  //지워지지 않은 수였다면, 
			for (int j = 1; i * j <= n; j++) { //그 수의 배수들을 모두 지운다. 
				check[min * j] = true;
			}
			if(min>=m) // 조건에서 m이상일때의 소수만 찾으므로 출력조건 걸어줌. 
				cout << min << '\n';
		}
	}

	return 0;
}