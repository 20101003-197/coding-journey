#include<iostream>
using namespace std;
class CounterA{
	public:
	int increament=10;
		
};
class CounterB: public CounterA {
	public:
	void decreament(){
		cout<<"\n\n\n\n"<<"Value of variable before decreament  ="<<increament<<endl;
		cout<<"=================================="<<endl;
		increament--;
		cout<<"\n\n\n\n"<<"Value of variable After decreament  ="<<increament<<endl;
		cout<<"=================================="<<endl;
	}
};
int main(){
	CounterB a;
	a.decreament();
}
