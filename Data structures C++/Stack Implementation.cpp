#include<iostream>
using namespace std;
class stack{
	int max=10;
	int top;
	int st[10];
	stack(){
		top=-1;
	}

bool isEmpty(){
	if(top==-1)
		return true;
	else
	return false;
}
bool isFull(){
	if(top==max-1)
	return true;
	else
	return false;
}
void push(int a){
	
	if(!isFull()){
		top++;
		st[top]=a;
	}
	else
	cout<<"OVERFLOW\n\n"
}
void pop(){
	if(!isEmpty()){
	st[top]=0;
	top--;
}
void display(){
	cout<<"=============================\n";
	cout<<"stack elements are : ";
	for(int i=top; i>=0; i--){
		cout<<st[i]<<" ";
	}
}

};
int main(){
	stack l;
	l.push(12);
	l.push(42);
	l.push(85);
	l.display();
}

