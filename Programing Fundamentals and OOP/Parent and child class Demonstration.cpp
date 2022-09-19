#include<iostream>
using namespace std;
class F
{
public:
int RollNo=197;
int marks=865;
};
class G
{
public:
float cgpa=3.5;
};
class E: public F,public G
{
public:
string name="Usman";
void display()
{
cout<<"Base class :: F AND G"<<endl;
cout<<"Student Name : "<<name<<endl;
cout<<"Student Roll No : "<<RollNo<<endl;
cout<<"Student marks : "<<marks<<endl;
cout<<"Student CGPA : "<<cgpa<<endl;
cout<<"-----------------------------------"<<endl;
}
};
class B:public F
{
public:
string subject="computer";
void output()
{
cout<<"Base class :: F"<<endl;
cout<<"student Roll no: "<<RollNo<<endl;
cout<<"student Marks: "<<marks<<endl;
cout<<"student Favourite Subject: "<<subject<<endl;
cout<<"-----------------------------------"<<endl;
}
};
class A: public B
{
public:
string name="Usman";
void input()
{
cout<<"Base class :: B"<<endl;
cout<<"Student Name: "<<name<<endl;
cout<<"student Roll no: "<<RollNo<<endl;
cout<<"student Marks: "<<marks<<endl;
cout<<"student Favourite Subject: "<<subject<<endl;
cout<<"-----------------------------------"<<endl;
}
};
class C: public B
{
public:
int id=123;
void getter()
{
cout<<"Base class :: B"<<endl;
cout<<"Student ID: "<<id<<endl;
cout<<"student Roll no: "<<RollNo<<endl;
cout<<"student Marks: "<<marks<<endl;
cout<<"student Favourite Subject:"<<subject<<endl;
cout<<"-----------------------------------"<<endl;
}
};
int main(){
E obj1;
obj1.display();
B obj2;
obj2.output();
A obj3;
obj3.input();
C obj4;
obj4.getter();

}
