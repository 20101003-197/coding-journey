#include<iostream>
using namespace std;
const int n=6; // n is the total space 
class List{
	int A[n]; // to store data
	int size; // size means data present
	public:
		List(){
		  size=0;
		}
	void display(){
		if(size==0){
			cout<<"LIST IS EMPTY "<<endl;
		}else{
			for(int i=0;i<size;i++){
				cout<<A[i]<<"  ";
			}
			cout<<endl;
		}
	}	
	void insertEnd(int data){
			
		if(size==n){
			cout<<data<<" can't be inserted bcz List is full.."<<endl;
		}else{
			A[size]=data;
			size++;			
		}		
	}	
	
	void insertStart(int data){
		
		if(size==n){
			cout<<data<<" can't be inserted bcz list is full.."<<endl;
		}else{
			
			for(int i=size;i>=0;i--){
				A[i]=A[i-1];
			}			
			A[0]=data;
			size++;
		}
		
	}

	void count(){
		// There are 5 elements in the list
		cout<<" Number of elements : "<<size<<endl;

	}
	void reverseDisplay(){
			if(size==0){
			cout<<"LIST IS EMPTY "<<endl;
		}else{
			for(int i=size-1;i>=0;i--){
				cout<<A[i]<<"  ";
			}
			cout<<endl;
		}
	}
		void insertatspecificindex(int data){
			
		if(size==n){
			cout<<data<<" can't be inserted bcz list is full.."<<endl;
		}else{
			int index;
			cout<<"Enter desired index: ";
			cin>>index;		
			for(int i=size;i>=index;i--){
				A[i]=A[i-1];
			}			
			A[index]=data;
			size++;
		}
		
	}
	
};

int main(){
	List l1;
	l1.display();
	l1.insertEnd(10);
	l1.insertEnd(20);
	l1.insertEnd(30);
	l1.insertEnd(49);
	l1.display();
	l1.insertatspecificindex(200);
	cout<<"\nAFTER SELECTING\n";
	l1.display();
	l1.insertStart(100);
	l1.display();
	l1.insertStart(500);
	l1.display();
	cout<<" Elements in reverse order are "<<endl;
	l1.reverseDisplay();
	l1.count();
	

}

