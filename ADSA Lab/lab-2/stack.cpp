/*
Design the stack data structure with the standard operations such as push, pop, top, size,
isEmpty using classes
*/

#include<vector>
#include <iostream>
using namespace std;


class Stack{

	vector<int> s;
	int s_size;
public:
	Stack(){
		s_size =0;
	}
	void push(int val){
		s.push_back(val);
		s_size++;
	}

	void pop(){
		s_size--;
	}

	int size(){
		return s_size;
	}
	int top(){

		return s[s_size-1];
	}
	bool isEmpty(){
		return s_size == 0;
	}

};

int main(){

	Stack s;
	s.push(3);
	cout<<s.top();
	cout<<s.size();
	s.pop();
	cout<<s.size();
	cout<<s.isEmpty();
	return 0;
}