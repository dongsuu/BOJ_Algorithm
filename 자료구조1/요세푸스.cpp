#include<iostream>
#include<queue>

using namespace std;
int main() {
	queue <int> queue; //int data 저장할 수 있는 queue 생성.
	int n, k;  
	cin >> n >> k;  //n은 사람 수, k는 몇번째 수 사람 제거할지. 

	for (int i = 1; i <= n; i++) {  //먼저 사람수(n)만큼 queue에 data를 넣는다.
		queue.push(i);             // 1 2 3 4 5 6 7 
	}

	cout << "<";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k-1; j++) {   //queue의 index가 0부터 시작하니 k번째 사람은 queue의 k-1번째에 있다. 
			queue.push(queue.front());    //원형으로 앉아있으니 queue의 front인 0을 젤 뒤로, 그다음 1을 젤 뒤로 보내면서 원형을 이루게 한다. 
			queue.pop();                  //queue에 들어있던 1,2를 꺼낸다. 즉, |1 2| 3 4 5 6 7 1 2 
		}
		if (i == n - 1)                  //마지막 출력에는 ,없애려고.. 
			cout << queue.front();
		else {
			cout << queue.front() << ", ";   //위의 inner forloop를 마치게 되면 3(k)을 출력해야한다. 
			queue.pop();                     //출력 후, 3(k)은 이제 pop  => 4 5 6 7 1 2 => 여기서 3번째는 이제 6이다. 따라서 이러한 과정을 또 반복. 
		}
	}
	cout << ">";
	return 0;
}