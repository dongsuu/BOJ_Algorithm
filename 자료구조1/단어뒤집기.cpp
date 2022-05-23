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
	cin.ignore(); //cin 에서 입력받으면 \n 남는데 이거 지워줌!! 
	              //왜냐. getline은 '\n' 나올때 까지 문자열로 인식하는데 바로 '\n' 나오니 오류.


	for(int i=0; i< t_case; i++){
		string str;
		getline(cin, str);
		revString(str);
		cout << '\n';
	}
	return 0;
}