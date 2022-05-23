#include<iostream>
#include<stack>

using namespace std;

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int t_case;
	cin >> t_case;
	int* num = new int[t_case];
	char* op = new char[t_case*2];

	stack <int> s;
	for (int i = 0; i < t_case; i++) {
		cin >> num[i];
	}

	int temp = 1;
	int count = 0;
	for (int j = 1; j <= t_case; j++) {
		for (int i = temp; i <= t_case+1; i++) {
			if (s.empty() == true || num[j - 1] != s.top()) {
				s.push(i);
				op[count] = '+';
				count++;
			}
			else{
				s.pop();
				op[count] = '-';
				count++;
				temp = i;
				break;
			}
		}
	}
	
	if (!s.empty()) {
		cout << "NO";
	}
	else {
		for (int i = 0; i < t_case * 2; i++)
			cout << op[i] << '\n';
	}
	return 0;
}