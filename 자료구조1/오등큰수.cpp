#include<iostream>
#include<stack>
using namespace std;
int F[1000001] = { 0 };

int main(void) {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	int* num = new int[n];
	int* NGF = new int[n];
	stack <int> s;

	for (int i = 0; i < n; i++) {
		cin >> num[i];
		F[num[i]]++;       //F[1] = 3, F[2]=2, F[3]=1, F[4]=1
	}

	for (int i = 0; i < n; i++) {
		if (s.empty()) {
			s.push(i);
		}
		while(!s.empty() && (F[num[s.top()]] < F[num[i]])) {
			NGF[s.top()] = num[i];
			s.pop();
		}
		s.push(i);
	}
	while (!s.empty()) {
		NGF[s.top()] = -1;
		s.pop();
	}

	for (int i = 0; i < n; i++) {
		cout << NGF[i] << ' ';
	}
	return 0;
}