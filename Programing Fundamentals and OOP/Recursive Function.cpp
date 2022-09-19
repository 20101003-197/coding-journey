#include<iostream>
using namespace std;
class Fib{
	int a1,a2,a3;
	public:
	Fib(){
		a1=0;
		a2=1;
		a3=0;
	}
	public:
		void recurse(int n){
			if(n>0){
				a3=a1+a2;
				a1=a2;
				a2=a3;
				cout<<"  "<<a3;
				recurse(n-1);
			}
		}
};
int main(){
	Fib a;
	int b;
	cin>>b;
	a.recurse(b);
	
}
