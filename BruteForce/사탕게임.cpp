#include<iostream>
using namespace std;

// swap for row 
void r_swap(string *s, int i, int j) {
	char temp = s[i][j];
	s[i][j] = s[i][j + 1];
	s[i][j + 1] = temp;
}

// swap for column 
void c_swap(string* s, int i, int j) {
	char temp = s[i][j];
	s[i][j] = s[i+1][j];
	s[i+1][j] = temp;
}

// 배열이 주어졌을 때, 가장 긴 연속 부분(행 또는 열) 구하기
int getLongest(string *s, int n) {
	int count;         // couting 
	int row_max = 0;   // 행에서 최댓값
	int col_max = 0;   // 열에서 최댓값

	// row
	for (int i = 0; i < n; i++) {
		count = 0;
		for (int j = 0; j < n-1; j++) {    // 배열 범위 넘어서지 않게. 
			if (s[i][j] == s[i][j + 1]) {
				count++;
			}

			if (s[i][j] != s[i][j + 1] || j == n - 2) {  // 후자 조건은 마지막 배열 index에 도달했을 때. 이거 없으면 배열 범위 넘어서 비교가 일어나서 쓰레기 값과 비교됨.
				if (row_max < count)
					row_max = count;
				count = 0;
			}
		}
	}

	//column
	for (int i = 0; i < n; i++) {
		count = 0;

		for (int j = 0; j < n - 1; j++) {
			if (s[j][i] == s[j + 1][i]) {
				count++;
			}

			if (s[j][i] != s[j + 1][i] || j == n - 2) {
				if (col_max < count)
					col_max = count;
				count = 0;
			}
		}
	}

	if (col_max > row_max)  // 최종적으로 행에서 가장 긴 부분 , 열에서 가장 긴 부분 중 더 큰 값 return. 
		                    // count에는 같은 횟수를 출력하고, 실제 같은 문자는 +1 해야함. ( EX. CC -> count: 1 , 같은 문자 개수: 2 ) 
		return col_max+1;
	else
		return row_max+1;
}

int main() {
	int n;
	int row_count = 0;
	int col_count = 0;
	int first;
	int count;
	int result = 0;
	cin >> n;
	string *s = new string[n];

	// input
	for (int i = 0; i < n; i++)
		cin >> s[i];

	first = getLongest(s, n); // 처음 주어진 배열에서 getLongest. 
	result = first;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			// when row swap 
			if (j<n-1 && s[i][j] != s[i][j + 1]) { 
				r_swap(s, i,j);   // swap
				row_count = getLongest(s, n);
				r_swap(s, i, j);  // 원래대로 돌려주기 
			}

			// when col swap
			if (i<n-1 && s[i][j] != s[i + 1][j]) {
				c_swap(s, i,j);
				col_count = getLongest(s, n);
				c_swap(s, i, j);
			}

			if (row_count > col_count)
				count = row_count;
			else
				count = col_count;

			if (count > result)
				result = count;
		}
	}

	cout << result;

	return 0;
}