#include<iostream>
#include<string>
#include<cstring>
#include<stack>

using namespace std;

void revString(string str) {
	stack <char> s;
	for (int i = 0; i < str.size()+1; i++) {
		if (str[i] == ' ' || str[i] == '\0') {
			while (!s.empty()) {
				cout << s.top();
				s.pop();		
			}
			cout << ' ';
		}
		else {
			s.push(str[i]);
		}
	}
}
int main() {
	int t_case;
	cin >> t_case;
	cin.ignore(); //cin ���� �Է¹����� \n ���µ� �̰� ������!! 
	              //�ֳ�. getline�� '\n' ���ö� ���� ���ڿ��� �ν��ϴµ� �ٷ� '\n' ������ ����.


	for(int i=0; i< t_case; i++){
		string str;
		getline(cin, str);
		revString(str);
		cout << '\n';
	}
	return 0;
}