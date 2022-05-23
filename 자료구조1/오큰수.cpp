#include<iostream>
#include<stack>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int t_case;
	stack <int> s; //���ÿ��� num�迭�� index�� ������ ���̴�. 
	cin >> t_case;
	int* num = new int[t_case];
	int* NGE = new int[t_case];

	for (int i = 0; i < t_case; i++) {
		cin >> num[i]; 
	}
	s.push(0); //������ ó������ num�迭�� ù��° �� ������. 
	for (int i = 1; i < t_case; i++) {
		if (s.empty()) {  //������ empty�� ���¿����� push���ش�. 
			s.push(i);
		}
		while(!s.empty() && num[s.top()] < num[i]) //������ ������� �ʰų�, num[s.top()]�� num[i]���� ���� ���� while���� ���� ��ū���� ã�´�. 
		/*
		��, 3 5 2 7�� �ִٰ� ����. 
		  1�ܰ�: ������ ������� �ʰ�, num[1] < num[2]�̹Ƿ� while���� ����ȴ�. ��, ���� num[i]�� num[s.top()]�� �ٷ� �������� ū ���̹Ƿ� ��ū���� �ȴ�. 
		         ���� NGE[s.top()]�� num[i]�� �����ϰ� ��ū�� ã������ pop���ش�. �̶� stack�� ��������Ƿ� �ݺ��� ����. �׸��� ���� num[i]�� index�� i�� stack�� push ==> stack: 2
		  2�ܰ�: stack�� ������� �ʰ�  ���� num[i](2)�� num[s.top()](5)���� �����Ƿ� �ݺ��� ����x => stack�� num[i]�� index push. ==> stack: 2 3
		  3�ܰ�: num[i]�� num[s.top()]���� ũ�� �ݺ��� ����. num[s.top()]�� ��ū���� num[i]�� �ȴ�. ��ū �� ã������ pop =>stack:2 ,�׷��� ���� num[i]�� num[s.top()]���� ũ��.
		         ���� �ٽ� �ݺ����� ����ȴ�. num[s.top]�� ��ū���� num[i]. ��ū�� ã������ pop => stack�� empty���¶� �ݺ��� ���� �� num[i]�� index push. 
				 ==> stack: 7
		  4�ܰ�: for���� �����µ� stack�� �����ִ� ���� �ִ�. �̴� ��ū���� �������� �ʴ°��̹Ƿ� -1 ����. 
		 */
		{
			NGE[s.top()] = num[i];
			s.pop();
		}
		s.push(i);
	}
		while (!s.empty()) {
			NGE[s.top()] = -1;
			s.pop();
		}

	for (int i = 0; i < t_case; i++) { //��ū�� ���
		cout << NGE[i] << " ";
	}
	
	return 0;
}