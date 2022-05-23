#include<iostream>
using namespace std;
int prime[1000002];
bool check[1000002];
int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int t,num;
	int cnt;
	int count = 0;
	for (int i = 2; i <= 1000000; i++) {
		prime[i] = i;
		check[i] = true;
	}
	for (int i = 2; i<=1000000; i++) {
		cnt = 2;
		if (check[i] == true) {
			while (i*cnt <= 1000000) {
				check[cnt*i] = false;
				cnt++;
			}
		}
	}
	
	cin >> t;
	while (t--) {
		cin >> num;
		for (int i = 1; i <= num/2; i++) {
			if (check[num-i] == true && check[i] == true) {
				count++;
			}
		}
		cout << count << '\n';
		count = 0;
	}
	return 0;
}