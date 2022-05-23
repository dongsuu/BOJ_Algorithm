#include <iostream>
#include <string>
#include<stack>  //스택 라이브러리 사용. 

using namespace std;

void check_vps(string str) {
	stack <char> s; //stack 생성(s)
	int count = 0;  //이 count는 ')' 개수를 셀 것이다.

	for (int i = 0; i < str.size(); i++) { //문자열 길이만큼 반복
		if (str[i] == '(') {  // '('일때는 stack에 push한다. 
			s.push(str[i]);
		}
		else if (str[i] == ')') {   //'('일때 기본적으로 stack에서 pop을 한다. -- () 쌍을 맞춰서 pop --
			if (s.empty() || count != 0) {  //stack이 비어있을 때 ')'이 들어오면 pop이 아니라 push를 해줘야한다. 
				s.push(str[i]);             //또한 이미 stack에 ')' 이 존재할 때 ')'이 들어올때도 pop이 아니라 push를 해줘야한다. ( ')' ')' 이렇게 들어오는 경우, 두번째 ')'에서는 stack이 empty가 아니기 때문에 이 조건도 생각해줘야함)
				count++;                    //그래서 push된 ')' 개수를 세어준다. 
			}
			else {        //스택이 비어있지 않으면서 push된 ')'이 없을때는 pop을 한다. 
				s.pop();
			}
		}
	} 
	if (s.empty())              //최종적으로 stack이 비어있으면 괄호 짝이 다 맞춰진것으로 YES 출력
		cout << "YES" << '\n';
	else {
		cout << "NO" << '\n';   //stack에 값이 남아있다면 짝이 안맞은 것으로 NO출력
		while (!s.empty()) {    //다음 실행을 위해 stack 다 비워줌. 
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