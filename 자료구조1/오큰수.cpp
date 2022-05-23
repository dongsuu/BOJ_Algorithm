#include<iostream>
#include<stack>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int t_case;
	stack <int> s; //스택에는 num배열의 index를 저장할 것이다. 
	cin >> t_case;
	int* num = new int[t_case];
	int* NGE = new int[t_case];

	for (int i = 0; i < t_case; i++) {
		cin >> num[i]; 
	}
	s.push(0); //스택의 처음에는 num배열의 첫번째 수 들어가야함. 
	for (int i = 1; i < t_case; i++) {
		if (s.empty()) {  //스택이 empty인 상태에서는 push해준다. 
			s.push(i);
		}
		while(!s.empty() && num[s.top()] < num[i]) //스택이 비어있지 않거나, num[s.top()]이 num[i]보다 작은 경우는 while문을 통해 오큰수를 찾는다. 
		/*
		즉, 3 5 2 7이 있다고 하자. 
		  1단계: 스택이 비어있지 않고, num[1] < num[2]이므로 while문이 실행된다. 즉, 현재 num[i]는 num[s.top()]의 바로 오른쪽의 큰 수이므로 오큰수가 된다. 
		         따라서 NGE[s.top()]에 num[i]를 저장하고 오큰수 찾았으니 pop해준다. 이때 stack이 비어있으므로 반복문 종료. 그리고 이제 num[i]의 index인 i를 stack에 push ==> stack: 2
		  2단계: stack이 비어있지 않고  현재 num[i](2)가 num[s.top()](5)보다 작으므로 반복문 성립x => stack에 num[i]의 index push. ==> stack: 2 3
		  3단계: num[i]가 num[s.top()]보다 크니 반복문 실행. num[s.top()]의 오큰수는 num[i]가 된다. 오큰 수 찾았으니 pop =>stack:2 ,그런데 아직 num[i]가 num[s.top()]보다 크다.
		         따라서 다시 반복문이 실행된다. num[s.top]의 오큰수는 num[i]. 오큰수 찾았으니 pop => stack은 empty상태라 반복문 종료 후 num[i]의 index push. 
				 ==> stack: 7
		  4단계: for문이 끝났는데 stack에 남아있는 것이 있다. 이는 오큰수가 존재하지 않는것이므로 -1 대입. 
		 */
		{
			NGE[s.top()] = num[i];
			s.pop();
		}
		s.push(i);
	}
		while (!s.empty()) {
			NGE[s.top()] = -1;
			s.pop();
		}

	for (int i = 0; i < t_case; i++) { //오큰수 출력
		cout << NGE[i] << " ";
	}
	
	return 0;
}