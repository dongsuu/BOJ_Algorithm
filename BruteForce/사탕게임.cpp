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

// �迭�� �־����� ��, ���� �� ���� �κ�(�� �Ǵ� ��) ���ϱ�
int getLongest(string *s, int n) {
	int count;         // couting 
	int row_max = 0;   // �࿡�� �ִ�
	int col_max = 0;   // ������ �ִ�

	// row
	for (int i = 0; i < n; i++) {
		count = 0;
		for (int j = 0; j < n-1; j++) {    // �迭 ���� �Ѿ�� �ʰ�. 
			if (s[i][j] == s[i][j + 1]) {
				count++;
			}

			if (s[i][j] != s[i][j + 1] || j == n - 2) {  // ���� ������ ������ �迭 index�� �������� ��. �̰� ������ �迭 ���� �Ѿ �񱳰� �Ͼ�� ������ ���� �񱳵�.
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

	if (col_max > row_max)  // ���������� �࿡�� ���� �� �κ� , ������ ���� �� �κ� �� �� ū �� return. 
		                    // count���� ���� Ƚ���� ����ϰ�, ���� ���� ���ڴ� +1 �ؾ���. ( EX. CC -> count: 1 , ���� ���� ����: 2 ) 
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

	first = getLongest(s, n); // ó�� �־��� �迭���� getLongest. 
	result = first;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			// when row swap 
			if (j<n-1 && s[i][j] != s[i][j + 1]) { 
				r_swap(s, i,j);   // swap
				row_count = getLongest(s, n);
				r_swap(s, i, j);  // ������� �����ֱ� 
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