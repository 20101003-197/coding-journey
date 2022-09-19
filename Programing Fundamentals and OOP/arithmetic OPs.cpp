#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
start:
	system("cls");
int a,b;
char c;
cout
<<"Enter value of a"<<endl;
	cin>>a ;cout<<"Enter value of b\n";cin>>b;
	retry:
	cout<<"\n"; 
	cout<<"Enter operation to perform"<<endl;
	cout<<"operations:\n multiply:'*' \n divide:'/'\n add:'+' \n subtract:'-'\n";
	c=getche(); 
	cout<<"\n";
	if (c=='+' || c=='-' || c=='*' || c=='/')     // If the entered operation is invalid, the program prompts the user to enter a valid operation
	goto begin;
	else
	cout<<"Invalid operation. Please enter a valid operation.";
	goto retry;
	begin:
	if ( c=='*')
	cout<<"Dot of a,b ="<<a*b<<endl;
	else if ( c=='+')
	cout<<"sum of a,b = "<<a+b<<endl;
	else if( c=='/' )
	cout<<"Division of a by b="<<a/b<<endl;
	else if( c=='-')
	cout<<"subtraction of a,b="<<a-b<<endl;
	char d;
	cout<<"would you like to re-run the program(Y/N)";
	d=getch();cout<<"\n";
	if( d=='Y' || d=='y')
	goto start;
	else
	exit; 
}
