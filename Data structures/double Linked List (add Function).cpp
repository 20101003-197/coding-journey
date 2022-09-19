#include<iostream>
using namespace std;
class node{
	public:
	int data;
	node *next;
	node *prev;
	node *head;
};
node* head=NULL;
node *prev=NULL;
//Function to iNsert Value in the list
	void insert(int val){
			if(head==NULL){
				node *temp=new node;
				temp->data=val;
				temp->next=head;
				temp->prev=NULL;
			}
			else{
				node *temp=new node;
				temp->data=val;
				temp->next=prev->next;
				prev->next=temp;
				temp->prev=prev;
				if(temp->next!=NULL)
				temp->next->prev=temp;
			}
		}
		//Function to display Value entered in List
		void display(){
			node *temp;
			temp=head;
			while(temp!=NULL){
				cout<<temp->data<<" ";
				temp=temp->next;
			}
		}
	

int main(){
	node q;
	insert(12);
	insert(12);
	insert(12);
	insert(12);
	display();
}
