#include<iostream>
using namespace std;

int GCD(int a, int b) { //유클리드 호제법 이용. GCD(a,b) = GCD(b,r) {r=a%b}
	if (b == 0)
		return a;
	else
		return GCD(b, a%b);
}
int LCM(int a, int b) { // a*b = GCD * LCM
	return a * b / GCD(a, b);
}
int main() {
	int a, b;
	int t_case;
	cin >> t_case;
	while (t_case--) {
		cin >> a >> b;
		cout << LCM(a, b) << '\n';
	}
	return 0;
}