#include<iostream>
using namespace std;
const int MAX = 1000000;

int prime[MAX + 1];
bool check[MAX + 1];

int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int num;
	int count = 0;
	int cn;

	for (int i = 2; i <= MAX; +i++) { //2부터 MAX까지 수 쓰기. 
		prime[i] = i;
	}

	for (int j = 2; j <= MAX; j++) { //에라토스테네스의 체를 사용해서 소수 구하기
		cn = 2;
		if (check[j] == false) {
			while (j * cn <= MAX) {
				check[j * cn] = true; 
				cn++;
			}
			count++; //count는 소수의 수. 
		}
	}
	//테스트 케이스 시작. 
	while (1) {
		cin >> num;
		if (num == 0)
			break;
		else if (num > 1000000)
			break;
		else {
			for (int i = 2; i <= count; i++) { //check[i]와 check[num-prime[i])가 모두 소수일때 출력.(소수의 합으로 출력) 
				if (check[num - prime[i]] == false && check[i] == false) {
					//여기서 num-prime[i]를 조건으로 검사하는 이유는 num(최대치에서 가장 가까운 수부터 검사하므로 자동적으로 b-a가 가장 큰 값이 된다.) 
					cout << num << " = " << prime[i] << " + " << num - prime[i] << '\n';
					break;
				}
			}
		}

	}
	return 0;
}
