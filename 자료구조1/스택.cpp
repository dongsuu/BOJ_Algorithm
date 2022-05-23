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

struct Stack { //stack 구조체
	int stackarr[10000];   //배열 기반의 stack
	int topIndex;          //topIndex는 현재 stack에 쌓여있는 값 중에 가장 최근에 들어간 stack배열의 index.
	Stack() {
		topIndex = -1;    //stack의 초기화. 스택에 아무것도 안들어있으므로 topIndex = -1이다. 
	}

	void SPush(int num) {   //stack에 값을 넣는 과정.
		topIndex += 1;      //topIndex를 1증가 시켜주고
		stackarr[topIndex] = num;    //topIndex가 가리키는 곳에 값을 넣는다. 
	}

	bool SIsEmpty() {      //스택이 비어있는지 확인. 
		if (topIndex == -1)   //topIndex가 -1이면 stack이 비어있는 상황이므로 true를 리턴. 
			return true;
		else                  //그렇지 않으면 false를 리턴. 
			return false;
	}
	int SPop() {           //stack에 값을 삭제하는 과정. 
		if (SIsEmpty()) {    //먼저 stack이 비어있는지 확인해주고 비어있으면 -1 리턴.
			return -1;
		}
		int temp_index;        //삭제할 stack 배열의 index값 저장.
		temp_index = topIndex;
		topIndex -= 1;           //값 하나 삭제하므로 topIndex -1해준다. 
		return stackarr[temp_index];	 //삭제할 데이터 반환
	}
	int SPeek() {             //Peek는 가장 최근에 들어간 데이터를 확인만 하는 과정. 
		if (SIsEmpty()) {
			return -1;
		}
		return stackarr[topIndex];   //값 삭제하지않고 반환만 한다. 
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
