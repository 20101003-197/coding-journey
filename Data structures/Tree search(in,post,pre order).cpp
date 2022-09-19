#include<iostream>
using namespace std;
struct node{
	int data;
	node *left;
	node *right;
};
	node* insert(node* temp,int dat){
		if(temp==NULL){
			temp=new node;
			temp->data=dat;
			temp->left=NULL;
			temp->right=NULL;
		}
		else if(dat<temp->data)
		temp->left=insert(temp->left,dat);
		else if(dat>=temp->data)
		temp->right=insert(temp->right,dat);
		
	}
	void search(node* temp,int dat){
		if(temp==NULL)
		cout<<"NUMBER NOT FOUND\n";
		else if(temp->data==dat)
		cout<<"Number Found";
		else if (temp->data<dat)
		search(temp->left,dat);
		else if(temp->data>dat)
		search(temp->right,dat);
	}
	void inorder(node* temp){
		if(temp!=NULL){
			inorder(temp->left);
			cout<<temp->data<<" \n";
			inorder(temp->right);
		}
	}
	void preorder(node* temp ){
		if(temp!=NULL){
			cout<<temp->data<<" \n";
			preorder(temp->left);
			preorder(temp->right);
		}
	}
	void postorder(node* temp){
			postorder(temp->left);
			postorder(temp->right);
			cout<<temp->data<<" \n";
	}
int main(){
	node *root=NULL;
	insert(root,5);
	insert(root,89);
	insert(root,45);
	insert(root,20);
	insert(root,9);
	inorder(root);
	postorder(root);
	preorder(root);
    search(root,0);
	cout<<endl;
	search(root,45);
	
}
