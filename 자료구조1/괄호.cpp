#include <iostream>
#include <string>
#include<stack>  //���� ���̺귯�� ���. 

using namespace std;

void check_vps(string str) {
	stack <char> s; //stack ����(s)
	int count = 0;  //�� count�� ')' ������ �� ���̴�.

	for (int i = 0; i < str.size(); i++) { //���ڿ� ���̸�ŭ �ݺ�
		if (str[i] == '(') {  // '('�϶��� stack�� push�Ѵ�. 
			s.push(str[i]);
		}
		else if (str[i] == ')') {   //'('�϶� �⺻������ stack���� pop�� �Ѵ�. -- () ���� ���缭 pop --
			if (s.empty() || count != 0) {  //stack�� ������� �� ')'�� ������ pop�� �ƴ϶� push�� ������Ѵ�. 
				s.push(str[i]);             //���� �̹� stack�� ')' �� ������ �� ')'�� ���ö��� pop�� �ƴ϶� push�� ������Ѵ�. ( ')' ')' �̷��� ������ ���, �ι�° ')'������ stack�� empty�� �ƴϱ� ������ �� ���ǵ� �����������)
				count++;                    //�׷��� push�� ')' ������ �����ش�. 
			}
			else {        //������ ������� �����鼭 push�� ')'�� �������� pop�� �Ѵ�. 
				s.pop();
			}
		}
	} 
	if (s.empty())              //���������� stack�� ��������� ��ȣ ¦�� �� ������������ YES ���
		cout << "YES" << '\n';
	else {
		cout << "NO" << '\n';   //stack�� ���� �����ִٸ� ¦�� �ȸ��� ������ NO���
		while (!s.empty()) {    //���� ������ ���� stack �� �����. 
			s.pop();
		}
	}
}

int main() {
	int num;
	cin >> num;

	while (num!=0) {
		string str;
		cin >> str;
		check_vps(str);
		num -= 1;
	}
	return 0;
}