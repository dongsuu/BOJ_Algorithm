#include<iostream>
using namespace std;
int memo[1000000] = {0}; //Ƚ�� 0���� �ʱ�ȭ ������. 

int makeOne(int n) {
	if (n == 1) //1�� ���� �������� 0�̹Ƿ� 0������ش�. 
		return 0;
	if (memo[n] > 0)
		return memo[n]; //�޸����̼�. �̹� ���� ������ �� ���� return�Ѵ�.
	/*
		������� ��ȭ������ ��Ÿ���� 
		D[n] = 1 + D[n-1] 
		D[n] = 1 + D[n/2]
		D[n] = 1 + D[n/3] �̴�. (1�� ���� Ƚ�� �߰�)
	*/
	memo[n] = 1 + makeOne(n-1); 
	if (n % 2 == 0) {
		int temp = 1 + makeOne(n / 2);
		if (memo[n] > temp) //ó���� -1���� �Ǿ��ִ� ���� memo�� �� ����Ǿ��ִ�. ����
			memo[n] = temp; //n/2 ������ �� ���� Ƚ���� �� �۴ٸ� memo�� n/2�� ���� Ƚ�� ���� ����������Ѵ�. 
	}
	if (n % 3 == 0) {
		int temp = 1 + makeOne(n / 3);
		if (memo[n] > temp) //n/2����� ������ ����.. 
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