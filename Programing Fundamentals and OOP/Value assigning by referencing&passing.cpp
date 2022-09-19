#include<iostream>
using namespace std;
int add(int x);
void add1(int &y);
int main()
{
	int a,b;
	a=add(a); // passing value
	add1(b); // referencing
	cout<<" Value in A by passing = "<<a<<endl;
	cout<<" Value in B by reference = "<<b<<endl;
	return 0;
}
int add(int x){ // by passing value
	int input; 
	cout<<" Enter Value to be added( by passing ) = "<<endl;
	cin>>input;
	x=x+input;
	return x;
}
int add(int &y){ // By referencing
	int input2;
	cout<<" Enter value to be added( by reference ) = ";
	cin>>input2;
	y=y+input2;
}
