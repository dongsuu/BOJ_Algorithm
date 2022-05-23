#include<iostream>
#include<cmath>
using namespace std;
#define MAX 333334*3

int result[MAX] = { 0 };
string str;
int eight[MAX] = { 0 };
int main() {
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		eight[i] = str[i] - '0';
	}

	int count = str.size()-1;
	int j = 0;

	while(count >= 0) {
		for (int i = 0; i < 3; i++) {
			result[j] = eight[count] % 2;
			eight[count] = eight[count]/2;
			j++;
		}
		count--;
	}

	if (result[j - 1] == 0) {
		j--;
		if (result[j - 1] == 0)
			j--;
	}

	for (int i = j-1; i >= 0; i--) {
		cout << result[i];
	}

	return 0;
}