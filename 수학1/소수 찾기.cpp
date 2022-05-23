#include<iostream>
using namespace std;

bool prime(int num) {
	if (num == 1)
		return false;

	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0)
			return false;
	}
	return true;
}

int main() {
	int t_case;
	int num;
	int count = 0;
	bool result;

	cin >> t_case; 
	
	while (t_case--) {
		cin >> num;
		result = prime(num);
		if (result)
			count++;
	}
	cout << count;


	return 0;
}