#include<iostream>
using namespace std;
int main()
{
	int x,y;
	cout<<"Enter X=";
	cin>>x;
	cout<<"Enter Y=";
	cin>>y;
    x = x + y;
    y = x - y;
    x = x - y;
    cout << "After Swapping: x =" << x << ", y=" << y;
}
