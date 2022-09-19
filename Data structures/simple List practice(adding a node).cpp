#include<iostream>
using namespace std;
struct node{
	int data;
	node *next;
};
class list{
	private:
	node *head,*tail;
	public:
		list(){
			head=NULL;
			tail=NULL;
		}
		void add(int n){
			
			node *temp=new node;
			temp->data=n;
			temp->next=NULL;
			if(head==NULL){
				head=temp;
				tail=temp;
			}
			else{
				tail->next=temp;
				tail=tail->next;
			}
			
		}
		void display(){
				node *ptr;
				ptr=head;
				while(ptr!=NULL){
					cout<<ptr->data<<" ";
					ptr=ptr->next;
				}
			}
};


int mian() {
	int ch,val,count=1;
	list obj;
	while(ch!=3){
	cout<<" ENter desired operation\n1.add\n2.display\n3.Exit";
	cin>>ch;
	switch(ch){
		case 1:
			cout<<" ENTER VALUE IN NODE # "<<count<<endl;
			cin>>val;
			count++;
			obj.add(val);
		case 2:
			obj.display();
		case 3:
			exit(0);
		default:
			cout<<"INvalid Operation numbr. Re-enter!";
	}
}
return 0;
}
