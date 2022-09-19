#include<iostream>
using namespace std;
int main()
{
int n, s, i, j;
cout << "Enter number of rows: ";
cin >> n;
while(i>=1)
{
	i=n;
//for loop to put space
while(s<n){

s=n;
cout << " ";
s++;}
//for loop for displaying star
while (j <= i){
j=1;
cout << "* ";
j++;}
// ending line after each row
cout << "\n";
i--;
}
return 0;
}
