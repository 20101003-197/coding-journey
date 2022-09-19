#include<iostream>
using namespace std;
class BakeryProducts
{
private:
int p_id;
string p_name;
int quantity;
float price;
string expiry_date;
public:
BakeryProducts(){
p_id=12345;
p_name="BREAD";
quantity=1;
price=60;
expiry_date="18-11-2021";
}
~BakeryProducts()
{
cout<<"************************"<<endl;
cout<<"Obect has been destroyed"<<endl;
cout<<"************************"<<endl;
}
void display()
{
cout<<" Product ID is: "<<p_id<<endl;
cout<<" Product Name is: "<<p_name<<endl;
cout<<" Product quantity is: "<<quantity<<endl;
cout<<" Product price is: "<<price<<endl;
cout<<" Product Expiry date is: "<<expiry_date<<endl;
}
};
int main()
{
BakeryProducts B;
B.display();
return 0;
}
