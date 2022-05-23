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
	stack <char> s; //결과 저장하는 스택
	stack <char> temp; //L 연산을 위해 임시로 pop한 문자를 나중에 다시 넣어주기 위해 필요한 스택. 
	for (int i = 0; i < str.size(); i++) { //입력 받은 문자열 스택에 저장
		s.push(str[i]);
	}
	cin >> t_case; //테스트 케이스 입력
	cin.ignore(); //getline 사용을 위해 ignore 실행하여 '\n' 없애줌

	while (t_case--) {
		string cmd;
		getline(cin, cmd); //명령어 입력받음. 

			if (cmd[0] == 'L') {   //L 연산
				if (s.empty()) {
					continue;
				}
				temp.push(s.top());  //커서를 왼쪽으로 이동하는 것은 pop연산은 하는데 문자열이 사라지는 것은 아니라 임시로 저장해둠. 
				s.pop();
			}

			else if (cmd[0] == 'D') { //D 연산
				if (temp.empty())
					continue;
				s.push(temp.top());
				temp.pop();
			}

			else if (cmd[0] == 'B') { //B 연산
				if (s.empty()) {
					continue;
				}
				s.pop();
			}
			else if (cmd[0] == 'P') 
				s.push(cmd[2]);
	}

	while(1) { //L연산으로 인해 temp에 저장됐던 문자열 다시 결과 스택에 넣어준다. 
		if (temp.empty())
			break;
		s.push(temp.top());
		temp.pop();
	}

	stack <char> result; //스택은 LIFO 구조라 거꾸로 나오므로 스택 하나 더 만들어서 반대로 출력하게 해줌. 
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