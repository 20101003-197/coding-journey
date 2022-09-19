#include<iostream>
#include<string>
using namespace std;
class Employee{
	protected:
		string name;
		int age;
		double height;
	public:
		Employee(string nm,int ag, double ht)
		{
			name=nm;
			age=ag;
			height=ht;
		}
			void show(){
				cout<<"Name: "<<name<<endl;
				cout<<"Age: "<<age<<endl;
				cout<<"Height: "<<height<<endl;
				cout<<"||===================================||"<<endl;
			}
};
class Teacher: public Employee{
	protected:
		string major_subject;
		int semester;
		public:
		Teacher(string ms,int sem,string nm,int ag, double ht):Employee(nm,ag,ht)
		{
			major_subject=ms;
			semester=sem;
		}
		void show(){
			Employee::show();
			cout<<"MAjor subject: "<<major_subject<<endl;
			cout<<"Semester:"<<semester<<endl;
			
		}
};
class Advisor : public Teacher{
	private:
		string prog1;
		string prog2;
	public:
		Advisor(string pg1,string pg2,string ms,int sem,string nm,int ag, double ht):Teacher(ms,sem,nm,ag,ht){
	
		prog1=pg1;
		prog2=pg2;
	}
		void show(){
			Teacher::show();
			cout<<"programs   "<<prog1<<" , "<<prog2<<endl;
		}
};
int main(){
	Employee a1("Usman Ashraf",19,5.6);
	Teacher a2("English",2,"Usman",20,5.7);
	Advisor a3("BS-IT","BS-CS","Calculus",2,"Usman Ashraf",21,5.8);
	a1.show();
	a2.show();
	a3.show();
}
