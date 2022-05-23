#include<iostream>
#include<queue>

using namespace std;
int main() {
	queue <int> queue; //int data ������ �� �ִ� queue ����.
	int n, k;  
	cin >> n >> k;  //n�� ��� ��, k�� ���° �� ��� ��������. 

	for (int i = 1; i <= n; i++) {  //���� �����(n)��ŭ queue�� data�� �ִ´�.
		queue.push(i);             // 1 2 3 4 5 6 7 
	}

	cout << "<";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k-1; j++) {   //queue�� index�� 0���� �����ϴ� k��° ����� queue�� k-1��°�� �ִ�. 
			queue.push(queue.front());    //�������� �ɾ������� queue�� front�� 0�� �� �ڷ�, �״��� 1�� �� �ڷ� �����鼭 ������ �̷�� �Ѵ�. 
			queue.pop();                  //queue�� ����ִ� 1,2�� ������. ��, |1 2| 3 4 5 6 7 1 2 
		}
		if (i == n - 1)                  //������ ��¿��� ,���ַ���.. 
			cout << queue.front();
		else {
			cout << queue.front() << ", ";   //���� inner forloop�� ��ġ�� �Ǹ� 3(k)�� ����ؾ��Ѵ�. 
			queue.pop();                     //��� ��, 3(k)�� ���� pop  => 4 5 6 7 1 2 => ���⼭ 3��°�� ���� 6�̴�. ���� �̷��� ������ �� �ݺ�. 
		}
	}
	cout << ">";
	return 0;
}