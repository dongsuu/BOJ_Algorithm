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

	for (int i = 2; i <= MAX; +i++) { //2���� MAX���� �� ����. 
		prime[i] = i;
	}

	for (int j = 2; j <= MAX; j++) { //�����佺�׳׽��� ü�� ����ؼ� �Ҽ� ���ϱ�
		cn = 2;
		if (check[j] == false) {
			while (j * cn <= MAX) {
				check[j * cn] = true; 
				cn++;
			}
			count++; //count�� �Ҽ��� ��. 
		}
	}
	//�׽�Ʈ ���̽� ����. 
	while (1) {
		cin >> num;
		if (num == 0)
			break;
		else if (num > 1000000)
			break;
		else {
			for (int i = 2; i <= count; i++) { //check[i]�� check[num-prime[i])�� ��� �Ҽ��϶� ���.(�Ҽ��� ������ ���) 
				if (check[num - prime[i]] == false && check[i] == false) {
					//���⼭ num-prime[i]�� �������� �˻��ϴ� ������ num(�ִ�ġ���� ���� ����� ������ �˻��ϹǷ� �ڵ������� b-a�� ���� ū ���� �ȴ�.) 
					cout << num << " = " << prime[i] << " + " << num - prime[i] << '\n';
					break;
				}
			}
		}

	}
	return 0;
}
