#include<iostream>
using namespace std;
int bruh(int arr[]){
   int temp = arr[0];
   for(int i=0; i<5; i++) {
	if(temp>arr[i]) {
    temp=arr[i];
    }
   }
   return temp;
}
int main()
{
	int arr[5];
	cout<<"Enter 5 array elements: ";
	for(int i=0;i<5;i++)
	cin>>arr[i];
	int smallest;
	int bruh(arr[5]);
	smallest=bruh(arr[5]);
	cout<<smallest<<"\n\n";
	
}
