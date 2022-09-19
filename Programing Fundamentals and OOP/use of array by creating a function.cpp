#include<iostream>
using namespace std;
int candidates()
{
	string name[50];
	float weight[100];
	float diff;
	for(int i=1;i<=25;i++){
		cout<<"Enter "<<i<<" Candidate Name: ";
		cin>>name[i];
		cout<<"Enter "<<i<<" Candidate Weight : ";
		cin>>weight[i];
	}
	float weight1[100];
	cout<<"\t\tNow we are getting details of Candidate after 6 months\n\n";
	for(int i=1;i<=25;i++){
		cout<<name[i]<<" Candidate Name :\n\n";
		cout<<"Enter "<<i<<" Candidate weight after 6 months :";
		cin>>weight1[i];
	}
	for (int i=1;i<=25;i++){
		diff=weight[i]-weight1[i];
		if(diff>5){
			cout<<name[i];
			cout<<"\n\n\t Follow diet plan\n\n";
		}
		else
		cout<<"\n\n\t Visit Nutritionist \n\n";
		}
	}
int main()
{
	candidates();

	}
	
