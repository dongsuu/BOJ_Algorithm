#include<iostream>
using namespace std;

int Bigger(int a, int b) {
	if (a > b)
		return a;
	else
		return b;
}

void maxCard(int* arr, int* max, int n) {
	max[1] = arr[1];
	int temp;
	for (int i = 2; i <= n; i++) {
		max[i] = 0;
		for (int j = 1; j < i; j++) {
			temp = Bigger(arr[i], max[i - j] + arr[j]);
			max[i] = Bigger(max[i], temp);
		}
	}
}

int main() {
	int n;
	int count;
	int index = 1;
	cin >> n;
	int *arr = new int[n+1];
	int* max = new int[n+1];

	for (int i = 1; i <=n; i++) 
		cin >> arr[i];
	
	maxCard(arr, max, n);
	cout << max[n];
}
