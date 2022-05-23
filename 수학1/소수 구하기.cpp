#include<iostream>
using namespace std;

int main() {
	int m, n;
	int min = 2; //�����佺�׳׽��� ü���� 2���� �����ϹǷ� �ʱⰪ 2�� ��. 
	cin >> m >> n; //m�̻� n���� �Է�
	int* prime = new int[n+1]; //index 0�� ������� �����Ŷ� n+1�� ���� �Ҵ� ����. 
	bool* check = new bool[n+1];

	for (int i = 2; i <= n; i++) { //2���� n���� ��� �� ��α�
		prime[i] = i;
	}

	for (int i = 1; i <= n; i++) { //�������� ���� ���� ��� �ʱⰪ���� false�� ����.
		check[i] = false;          //��, �������� true, �������� ������ false�� ��. 
	}

	for (int i = min; i <= n; i++) {
		min = prime[i]; //���� ���� ���� ã�´�.(������ �����ٸ� �ؿ� if���� ��������ʾ� �����ݺ����� �Ѿ�� �ᱹ if�� ����ɶ� min�� �������� ���� ����.)
		if (check[i] == false) {  //�������� ���� �����ٸ�, 
			for (int j = 1; i * j <= n; j++) { //�� ���� ������� ��� �����. 
				check[min * j] = true;
			}
			if(min>=m) // ���ǿ��� m�̻��϶��� �Ҽ��� ã���Ƿ� ������� �ɾ���. 
				cout << min << '\n';
		}
	}

	return 0;
}