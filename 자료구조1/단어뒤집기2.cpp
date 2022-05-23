#include<iostream>
#include<string>
#include<stack>

using namespace std;
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	string str;
	stack <char> s;
	stack <char> t;
	bool flag = false;
	getline(cin, str);
	for (int i = 0; i < str.size(); i++) {
		if (str[i] >= 'a' && str[i] <= 'z') {
			if (flag == false)
				s.push(str[i]);
			else
				t.push(str[i]);
			if (str[i + 1] == '<') {
				while (!s.empty()) {
					cout << s.top();
					s.pop();
				}
			}
		}
		else if (str[i] == '<') {
			t.push(str[i]);
			flag = true;
		}
		else if (str[i] == '>') {
			stack <char> r;
			t.push(str[i]);
			while (!t.empty()) {
				r.push(t.top());
				t.pop();
			}
			while (!r.empty()) {
				cout << r.top();
				r.pop();
			}
			flag = false;
		}
		else if (str[i] >= '0' && str[i] <= '9') {
			if (flag == false)
				s.push(str[i]);
			else
				t.push(str[i]);
			if (str[i + 1] == '<') {
				while (!s.empty()) {
					cout << s.top();
					s.pop();
				}
			}
		}
		else if (str[i] == ' ') {
			if (flag == true)
				t.push(str[i]);
			else {
				while (!s.empty()) {
					cout << s.top();
					s.pop();
				}
				cout << ' ';
			}
		}
	}
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
	return 0;
}