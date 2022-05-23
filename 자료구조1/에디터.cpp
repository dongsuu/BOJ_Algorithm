#include<iostream>
#include<string>
#include <stack>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int t_case;
	string str;
	cin >> str;
	stack <char> s; //��� �����ϴ� ����
	stack <char> temp; //L ������ ���� �ӽ÷� pop�� ���ڸ� ���߿� �ٽ� �־��ֱ� ���� �ʿ��� ����. 
	for (int i = 0; i < str.size(); i++) { //�Է� ���� ���ڿ� ���ÿ� ����
		s.push(str[i]);
	}
	cin >> t_case; //�׽�Ʈ ���̽� �Է�
	cin.ignore(); //getline ����� ���� ignore �����Ͽ� '\n' ������

	while (t_case--) {
		string cmd;
		getline(cin, cmd); //��ɾ� �Է¹���. 

			if (cmd[0] == 'L') {   //L ����
				if (s.empty()) {
					continue;
				}
				temp.push(s.top());  //Ŀ���� �������� �̵��ϴ� ���� pop������ �ϴµ� ���ڿ��� ������� ���� �ƴ϶� �ӽ÷� �����ص�. 
				s.pop();
			}

			else if (cmd[0] == 'D') { //D ����
				if (temp.empty())
					continue;
				s.push(temp.top());
				temp.pop();
			}

			else if (cmd[0] == 'B') { //B ����
				if (s.empty()) {
					continue;
				}
				s.pop();
			}
			else if (cmd[0] == 'P') 
				s.push(cmd[2]);
	}

	while(1) { //L�������� ���� temp�� ����ƴ� ���ڿ� �ٽ� ��� ���ÿ� �־��ش�. 
		if (temp.empty())
			break;
		s.push(temp.top());
		temp.pop();
	}

	stack <char> result; //������ LIFO ������ �Ųٷ� �����Ƿ� ���� �ϳ� �� ���� �ݴ�� ����ϰ� ����. 
	while (!s.empty()) {
		result.push(s.top());
		s.pop();
	}
	while (!result.empty()) {
		cout << result.top();
		result.pop();
	}

	return 0;
}