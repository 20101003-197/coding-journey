#include<iostream>
using namespace std;
class HP{
	private:
		
		string model;
		string manufacturer;
		string memory;
		public:
			HP(){
				
			}
			~HP(){
				cout<<endl<<" OBJECT TERMINATED "<<endl;
			}
			HP(string x,string y, string z){
				model=x;
				manufacturer=y;
				memory=z;
			}
		void input(){
			cout<<" Enter Model:";
			cin>>model;
			cout<<endl<<" Enter manufacturer:";
			cin>>manufacturer;
			cout<<endl<<" Enter memory: ";
			cin>>memory;
		}
		void display(){
			cout<<" Model is = "<<model<<endl;
			cout<<" manufacturer is = "<<manufacturer<<endl;
			cout<<" memory is = "<<memory<<endl;
		}
		};
int main()
{
	HP s1;
	s1.input();
	HP s2("NOTEBOOK PRO","ASUS","5 TB");
	HP s3=s2;
	s1.display();
	cout<<"\n\n\n";
	s2.display();
	cout<<"\n\n\n";
	s3.display();
	}
