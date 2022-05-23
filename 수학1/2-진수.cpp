#include<iostream>
#include<cmath>
#include<stack>
using namespace std;

int main() {
	long long ten;
	stack <long long> s;
	cin >> ten;
	
	while (1) {
		if (ten > 0 || ten%-2 ==0) {
			s.push(ten % -2);
			ten = ten / -2;
			if (ten == 0) {
				break;
			}
		}
		else if (ten < 0 && ten%-2 != 0) {
			s.push(-(ten % -2));
			ten = ten / -2;
			if (ten == 0) {
				ten += 1;
				s.push(ten);
				break;
			}
			ten += 1;
		}
	}
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}

	return 0;
}