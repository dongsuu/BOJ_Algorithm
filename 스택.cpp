/*
cin.tie(NULL);
ios::sync_with_stdio(false);
*/
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <math.h>
#include<vector>

using namespace std;

struct Stack { //stack ����ü
	int stackarr[10000];   //�迭 ����� stack
	int topIndex;          //topIndex�� ���� stack�� �׿��ִ� �� �߿� ���� �ֱٿ� �� stack�迭�� index.
	Stack() {
		topIndex = -1;    //stack�� �ʱ�ȭ. ���ÿ� �ƹ��͵� �ȵ�������Ƿ� topIndex = -1�̴�. 
	}

	void SPush(int num) {   //stack�� ���� �ִ� ����.
		topIndex += 1;      //topIndex�� 1���� �����ְ�
		stackarr[topIndex] = num;    //topIndex�� ����Ű�� ���� ���� �ִ´�. 
	}

	bool SIsEmpty() {      //������ ����ִ��� Ȯ��. 
		if (topIndex == -1)   //topIndex�� -1�̸� stack�� ����ִ� ��Ȳ�̹Ƿ� true�� ����. 
			return true;
		else                  //�׷��� ������ false�� ����. 
			return false;
	}
	int SPop() {           //stack�� ���� �����ϴ� ����. 
		if (SIsEmpty()) {    //���� stack�� ����ִ��� Ȯ�����ְ� ��������� -1 ����.
			return -1;
		}
		int temp_index;        //������ stack �迭�� index�� ����.
		temp_index = topIndex;
		topIndex -= 1;           //�� �ϳ� �����ϹǷ� topIndex -1���ش�. 
		return stackarr[temp_index];	 //������ ������ ��ȯ
	}
	int SPeek() {             //Peek�� ���� �ֱٿ� �� �����͸� Ȯ�θ� �ϴ� ����. 
		if (SIsEmpty()) {
			return -1;
		}
		return stackarr[topIndex];   //�� ���������ʰ� ��ȯ�� �Ѵ�. 
	}
};


int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	int num; 
	cin >> num;
	Stack stack;

	while (num!=0) {
		string str;
		cin >> str;      
		if (str == "push") {
			int data;
			cin >> data;
			stack.SPush(data);
		}
		else if (str == "top") {
			cout << stack.SPeek()<<'\n';
		}
		else if (str == "size") {
			cout << stack.topIndex + 1<<'\n';
		}
		else if(str == "empty"){
			cout << stack.SIsEmpty()<<'\n';
		}
		else if (str == "pop") {
			cout << stack.SPop() << '\n';
		}
		num--;
	}

	return 0;
}
