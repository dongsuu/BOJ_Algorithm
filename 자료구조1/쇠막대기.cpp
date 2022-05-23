#include<iostream>
#include<stack>

using namespace std;
int main() {
	stack <char> s; // 괄호 저장할 스택 사용
	string exp; 
	cin >> exp; //괄호 입력받기. 
	int result = 0;  //결과값 저장

	for (int i = 0; i < exp.size(); i++) { //괄호 수 만큼 반복
		if (exp[i] == '(') { // '('괄호는 일단 push. 다음 괄호가 ')'이면 레이저가 되는 거고, 아니면 막대가 되는 것임.
			s.push(exp[i]);
		}
		else if (exp[i] == ')') { // ')'괄호가 나왔을 때는 2가지로 나뉘어짐.( 레이저 vs 막대 )
			if (exp[i - 1] == '(') { // 이전 괄호가 '('이면 레이저인 경우.
				s.pop(); // 레이저 이므로 pop연산으로 인해 '()' 한 쌍을 만들어 주고 
				result = result + s.size();  // pop을 해버려서 이제 스택 안에는 '('만 있는데 '(' 개수가 막대의 개수가 되므로 stack의 size만큼 더해줌.
			}
			else { //그렇지 않으면 막대의 끝부분이 되는 경우. 
				s.pop(); //pop을 진행해서 막대를 완성시켜 주고  
				result = result + 1; //결과값에 +1을 해준다. (완성된 막대의 가장 오른쪽 부분 더해줘야함..)
			}
		}
	}

	cout << result;
	return 0;
}