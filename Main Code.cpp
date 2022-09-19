#include<iostream>
#include<conio.h>
#include<fstream>
#include<windows.h>
using namespace std;
class bus{
	private:   //busNO. // Bus Name //		driver name;
		string b_no,b_name,d_name; // frequently used variables
		int b_seats; // total seats
	public:
		bus(){
			b_no=" ";
			b_name=" ";
			d_name=" ";
			b_seats=32;
		}
	//Public Functions
		 void menu(); 
		 void new_bus();
		 void view_bus();
		 void single_busview();
		 void All_busview();
		 void update_bus();
		 void del_bus();
		 void route_bus();
		 void detail_bus();
		 void booking();
		 void renew_bus(); // remove bookings After A day of booking
		 void search_booking();
		 void update_booking(); //Delete previous booking and rebook.
		 void DEL_BOOKING();
		 void show_all_booking();
};
void bus::menu() //Default interface to use the program
{
int choice;
p:
		system("cls");
		cout << "\n\n\n";
        cout << "\t\t\t\t\t\t\t ==========================================================\n";
        cout << "\t\t\t\t\t\t\t ################::BUS MANAGEMENT SYSTEM::################\n";
        cout << "\t\t\t\t\t\t\t ==========================================================\n\n\n";
		cout << "\t\t\t\t\t\t\t  -----------------------------------------------\n";
        cout << "\t\t\t\t\t\t\t  |\t1.  Add Bus Record     \t\t\t|\n";
        cout << "\t\t\t\t\t\t\t  -----------------------------------------------\n";
        cout << "\t\t\t\t\t\t\t  |\t2.  VIEW BUS DETAILS   \t\t\t|\n";
        cout << "\t\t\t\t\t\t\t  -----------------------------------------------\n";
        cout << "\t\t\t\t\t\t\t  |\t3.  UPDATE BUS DETAIL  \t\t\t|\n";
        cout << "\t\t\t\t\t\t\t  -----------------------------------------------\n";
        cout << "\t\t\t\t\t\t\t  |\t4.  DELETE BUS DETAIL  \t\t\t|\n";
        cout << "\t\t\t\t\t\t\t  -----------------------------------------------\n";
        cout << "\t\t\t\t\t\t\t  |\t5.  VIEW ROUTE DETAILS \t\t\t|\n";
        cout << "\t\t\t\t\t\t\t  -----------------------------------------------\n";
        cout << "\t\t\t\t\t\t\t  |\t6.  RESERVATION DETAILS\t\t\t|\n";
        cout << "\t\t\t\t\t\t\t  -----------------------------------------------\n";
        cout << "\t\t\t\t\t\t\t  |\t7.  Book SEAT          \t\t\t|\n";
        cout << "\t\t\t\t\t\t\t  -----------------------------------------------\n";
        cout << "\t\t\t\t\t\t\t  |\t8.  RENEW RESERVATION  \t\t\t|\n";
        cout << "\t\t\t\t\t\t\t  -----------------------------------------------\n";
        cout << "\t\t\t\t\t\t\t  |\t9.  SEARCH BOOKING     \t\t\t|\n";
        cout << "\t\t\t\t\t\t\t  -----------------------------------------------\n";
        cout << "\t\t\t\t\t\t\t  |\t10. UPDATE RECORD      \t\t\t|\n";
        cout << "\t\t\t\t\t\t\t  -----------------------------------------------\n";
        cout << "\t\t\t\t\t\t\t  |\t11. DELETE RECORD      \t\t\t|\n";
        cout << "\t\t\t\t\t\t\t  -----------------------------------------------\n";
        cout << "\t\t\t\t\t\t\t  |\t12. SHOW ALL RECORD    \t\t\t|\n";
        cout << "\t\t\t\t\t\t\t  -----------------------------------------------\n";
        cout << "\t\t\t\t\t\t\t  |\t13. EXIT               \t\t\t|\n";
        cout << "\t\t\t\t\t\t\t  -----------------------------------------------\n";
        cout<<"\n\n ENTER YOUR CHOICE : ";
	cin>>choice;
	switch(choice){
		case 1:{
			
			new_bus();
			break;
	}
		case 2:{
		view_bus();
			break;
}
		 case 3:{
		update_bus();
	 	break;
	}
		 case 4:{
		 	del_bus();
			break;
	}
		 case 5:{
		 	route_bus();
			break;
	}
		 case 6:{
		 	detail_bus();
			break;
	}
		 case 7:{
		 	booking();
			break;
	}
		 case 8:{
		 	renew_bus();
			break; 
	}
		 case 9:{
		 	search_booking();
			break;
}
		 case 10:{
		 	update_booking();
			break;
	}
		 case 11:{
		 	DEL_BOOKING();
			break;
	}
		 case 12:{
		 	show_all_booking();
			break;
	}
		 case 13:{
		 	exit(0);
			break;
	}
		 default:
		 	cout<<"\n\n Invalid Choice......PLEASE TRY AGAIN....";
}
			getch();
		 	goto p;
	 
}
	void bus::new_bus(){ // Adds new bus record, Duplicate Entry Validation
		p:
		system("cls");	
		cout << "\n\n\n";
        cout << "\t\t\t\t\t\t\t ==========================================================\n";
        cout << "\t\t\t\t\t\t\t ################::BUS MANAGEMENT SYSTEM::################\n";
        cout << "\t\t\t\t\t\t\t ==========================================================\n\n\n";
		fstream file;
		string t_no,tb_name,td_name;  //TEMPORARY VARIABLE for checking Data duplication
		int t_seats,found=0;
		cout<<"\n\n Bus No : ";
		cin>>b_no;
		cout<<"\n\n Bus Name : ";
		cin>>b_name;
		cout<<"\n\n TOTAL SEATS : ";
		cin>>b_seats;
		cout<<"\n\n Driver Name : ";
		cin>>d_name;
		file.open("bus.txt",ios::in);
		if(!file){
			file.open("bus.txt",ios::app | ios::out);
			file<<b_no<<" "<<b_name<<" "<<b_seats<<" "<<d_name<<"\n";
			file.close();
		}
		else{
			file>>t_no>>tb_name>>t_seats>>td_name;
			while(!file.eof()){
				if(b_no==t_no){
					found++;
				}
				file>>t_no>>tb_name>>t_seats>>td_name;
			}
			file.close();
			if(found == 0){
			file.open("bus.txt",ios::app | ios::out);
			file<<b_no<<" "<<b_name<<" "<<b_seats<<" "<<d_name<<"\n";
			file.close();
			}
			else{
				cout<<"\n\n Duplicate Record Found......";
				getch();
				goto p;
			}
		}
		cout<<"\n\n BUS RECORD ENTERED SUCCESSFULLY.....";
	}
	void bus::view_bus(){ // view bus record // has 2 sub function
		p:
		system("cls");
		cout << "\n\n\n";
        cout << "\t\t\t\t\t\t\t ==========================================================\n";
        cout << "\t\t\t\t\t\t\t ################::BUS MANAGEMENT SYSTEM::################\n";
        cout << "\t\t\t\t\t\t\t ==========================================================\n\n\n";
		int choice;
		cout<<"\n\n 1. Single BUS RECORD";
		cout<<"\n 2.ALL BUSES RECORD";
		cout<<"\n 3. GO BACK";
		cout<<"\n\n Enter Your Choice : ";
		cin>>choice;
		switch(choice){
			case 1:{
				single_busview();
				break;
			}
			case 2:{
				All_busview();
				break;
			}
			case 3:{
				menu();
				break;
			}	
			default:{
				cout<<"\n\n Invalid Choice.....Please Try again.";
				getch();
				goto p;
				}
		}
	}
		void bus::single_busview(){
		system("cls");
		cout << "\n\n\n";
        cout << "\t\t\t\t\t\t\t ==========================================================\n";
        cout << "\t\t\t\t\t\t\t ################::BUS MANAGEMENT SYSTEM::################\n";
        cout << "\t\t\t\t\t\t\t ==========================================================\n\n\n";
		 	string t_no;
		 	fstream file;
		 	int found=0;
			cin>>t_no;
			file.open("bus.txt",ios::in);
			if(!file){
				cout<<"\n\n File Opening ERROR....";
			}
			else{
				cout<<"\n\n Bus No. : ";
				cin>>t_no;
				file>>b_no>>b_name>>b_seats>>d_name;
				while(!file.eof()){
					if(t_no==b_no){ // if Input data matches
						system("cls");
						cout << "\n\n\n";
				        cout << "\t\t\t\t\t\t\t ==========================================================\n";
				        cout << "\t\t\t\t\t\t\t ################::BUS MANAGEMENT SYSTEM::################\n";
				        cout << "\t\t\t\t\t\t\t ==========================================================\n\n\n";
						cout<<"\n\n BUS NO.\tBUS NAME\tNO. OF SEATS\tDRIVER NAME";
						cout<<"\n"<<b_no<<"\t\t"<<b_name<<"\t\t"<<b_seats<<"\t\t"<<d_name;
					found++;
					}
					file>>b_no>>b_name>>b_seats>>d_name;
				}file.close();
				if(found==0){ // if input doesnt match
					cout<<"\n\nInvalid BUS NO#.........";
				}
				

						}
			
		 }
		 void bus::All_busview(){ // NO INPUT VALIDATION REQUIRED
		system("cls");
		cout << "\n\n\n";
        cout << "\t\t\t\t\t\t\t ==========================================================\n";
        cout << "\t\t\t\t\t\t\t ################::BUS MANAGEMENT SYSTEM::################\n";
        cout << "\t\t\t\t\t\t\t ==========================================================\n\n\n";
				 	fstream file;
			file.open("bus.txt",ios::in);
			if(!file){
				cout<<"\n\n File Opening ERROR....";
			}
			else{
				cout<<"\n\n BUS NO.\tBUS NAME\tNO. OF SEATS\tDRIVER NAME";
				file>>b_no>>b_name>>b_seats>>d_name;
				while(!file.eof())
				{
					
					cout<<"\n "<<b_no<<"\t\t"<<b_name<<"\t\t"<<b_seats<<"\t\t"<<d_name;
					file>>b_no>>b_name>>b_seats>>d_name;
				}
				file.close();
			
		 }
	}
	void bus::update_bus(){ // EDIT Existing record (logic: Copies the data to a new file and writes the newly entered record in a new file then rename it)
		system("cls");
		cout << "\n\n\n";
        cout << "\t\t\t\t\t\t\t ==========================================================\n";
        cout << "\t\t\t\t\t\t\t ################::BUS MANAGEMENT SYSTEM::################\n";
        cout << "\t\t\t\t\t\t\t ==========================================================\n\n\n";
		fstream file,file1;
	string t_no,no,t_name,td_name;
	int t_seats,found=0;
	file.open("bus.txt",ios::in);
	if(!file)
	{
		cout<<"\n\n File Not Found.....";
	}
	else
	{
		cout<<"\n\n Bus NO: ";
		cin>>t_no;
		file1.open("temp.txt",ios::app | ios::out);
		file>>b_no>>b_name>>b_seats>>d_name;
		while(!file.eof()){
			if(t_no==b_no){
				cout<<"\n\n New BUS NO. : ";
				cin>>no;
				cout<<"\n\n Bus Name : ";
				cin>>t_name;
				cout<<"\n\n No. Of Seats : ";
				cin>>t_seats;
				cout<<"\n\n Driver Name : ";
				cin>>td_name;
				file1<<no<<" "<<t_name<<" "<<t_seats<<" "<<td_name<<"\n";
				cout<<"\n\n\n\t\t\t RECORD UPDATED SUCCESSFULLY.....";
				found++;
			}
			else{
				file1<<b_no<<" "<<b_name<<" "<<b_seats<<" "<<d_name<<"\n";
			}
			file>>b_no>>b_name>>b_seats>>d_name;
		}
		file.close();
		file1.close();
		remove("bus.txt");
		rename("temp.txt","bus.txt");
		if(found==0){
			cout<<"\n\n Bus No. is Invalid.....";
			
		}
	}

	}
	void bus::del_bus(){// Update_bus() function with a few tweaks, Send data to new file except the one selected for deletion
	system("cls");
		cout << "\n\n\n";
        cout << "\t\t\t\t\t\t\t ==========================================================\n";
        cout << "\t\t\t\t\t\t\t ################::BUS MANAGEMENT SYSTEM::################\n";
        cout << "\t\t\t\t\t\t\t ==========================================================\n\n\n";
		fstream file,file1;
	string t_no;
	int found=0;
	file.open("bus.txt",ios::in);
	if(!file)
	{
		cout<<"\n\n File Not Found.....";
	}
	else
	{
		cout<<"\n\n Bus NO: ";
		cin>>t_no;
		file1.open("temp.txt",ios::app | ios::out);
		file>>b_no>>b_name>>b_seats>>d_name;
		while(!file.eof()){
			if(t_no==b_no){
				cout<<"\n\n\n\t\t\t RECORD DELETED SUCCESSFULLY.....";
				found++;
			}
			else{
				file1<<b_no<<" "<<b_name<<" "<<b_seats<<" "<<d_name<<"\n";
			}
			file>>b_no>>b_name>>b_seats>>d_name;
		}
		file.close();
		file1.close();
		remove("bus.txt");
		rename("temp.txt","bus.txt");
		if(found==0){
			cout<<"\n\n Bus No. is Invalid.....";
		
		}
	}

	}
	void bus::route_bus(){// Simple Comodity Function. No complex technicality
		p:
		system("cls");
		cout << "\n\n\n";
        cout << "\t\t\t\t\t\t\t ==========================================================\n";
        cout << "\t\t\t\t\t\t\t ################::BUS MANAGEMENT SYSTEM::################\n";
        cout << "\t\t\t\t\t\t\t ==========================================================\n\n\n";
			int choice;
		cout<<"\n\n 1. 1st ROUT DETAILS";
		cout<<"\n\n 2. 2nd ROUT DETAILS";
		cout<<"\n\n 3. 3nd ROUT DETAILS";
		cout<<"\n\n 4. 4nd ROUT DETAILS";
		cout<<"\n\n 5. 5nd ROUT DETAILS";
		cout<<"\n\n Enter Your Choice : ";
		cin>>choice;
		switch(choice)
		{
			case 1:{
		system("cls");
		cout << "\n\n\n";
        cout << "\t\t\t\t\t\t\t ==========================================================\n";
        cout << "\t\t\t\t\t\t\t ################::BUS MANAGEMENT SYSTEM::################\n";
        cout << "\t\t\t\t\t\t\t ==========================================================\n\n\n";
				cout<<"\n    From Sialkot to Lahore";
				cout<<"\n 9:00 am-------------------- 11:00 am";
				cout<<"\n    From Lahore to Faisalabad";
				cout<<"\n 12:00 am-------------------- 2:30 pm";
				cout<<"\n    From Sahiwal to Bhawalpur";
				cout<<"\n 4:00 am-------------------- 9:00 am";
				cout<<"\n    From Lahore to Multan";
				cout<<"\n 7:00 am-------------------- 2:00 pm";
				cout<<"\n    From Islamabad to Murree";
				cout<<"\n 10:00 am-------------------- 11:30 am";
				cout<<"\n    From Daska to Lahore";
				cout<<"\n 8:30 am-------------------- 10:00 am";
				break;
			}
			case 2:{
		system("cls");
		cout << "\n\n\n";
        cout << "\t\t\t\t\t\t\t ==========================================================\n";
        cout << "\t\t\t\t\t\t\t ################::BUS MANAGEMENT SYSTEM::################\n";
        cout << "\t\t\t\t\t\t\t ==========================================================\n\n\n";
				cout<<"\n    From Sialkot to Gujranwala";
				cout<<"\n 9:00 am-------------------- 10:00 am";
				cout<<"\n   From Lahore to Kamoki";
				cout<<"\n 12:00 am-------------------- !:00 pm";
				cout<<"\n    From Islamabad to Rawalpindi";
				cout<<"\n 10:00 am-------------------- 11:00 pm";
				break;
			}
			case 3:{
		system("cls");
		cout << "\n\n\n";
        cout << "\t\t\t\t\t\t\t ==========================================================\n";
        cout << "\t\t\t\t\t\t\t ################::BUS MANAGEMENT SYSTEM::################\n";
        cout << "\t\t\t\t\t\t\t ==========================================================\n\n\n";
				cout<<"\n    From Kamoki to Wazirabad";
				cout<<"\n 8:30 am-------------------- 9:30 am";
				cout<<"\n    From Lahore to Gujranwala";
				cout<<"\n 1:00 pm-------------------- 2:30 pm";
				cout<<"\n    From Murree to New Murree";
				cout<<"\n 4:00 pm-------------------- 4:30 pm";
				cout<<"\n    From Naran to Nathiya Gali";
				cout<<"\n 7:00 am-------------------- 12:00 pm";
				cout<<"\n    From Sialkot to Jhelum";
				cout<<"\n 8:00 am-------------------- 10:30 am";
							
				break;
			}
			case 4:{
		system("cls");
		cout << "\n\n\n";
        cout << "\t\t\t\t\t\t\t ==========================================================\n";
        cout << "\t\t\t\t\t\t\t ################::BUS MANAGEMENT SYSTEM::################\n";
        cout << "\t\t\t\t\t\t\t ==========================================================\n\n\n";
				cout<<"\n    From Rawalpindi to Attock";
				cout<<"\n 9:00 am-------------------- 11:00 am";
				cout<<"\n    From Lahore to Faisalabad";
				cout<<"\n 12:00 am-------------------- 2:30 pm";
				cout<<"\n    From Sahiwal to Bhawalpur";
				cout<<"\n 4:00 am-------------------- 9:00 am";
				cout<<"\n    From Lahore to Multan";
				cout<<"\n 7:00 am-------------------- 2:00 pm";
				cout<<"\n    From Murree to New Murree";
				cout<<"\n 4:00 pm-------------------- 4:30 pm";
				cout<<"\n    From Naran to Nathiya Gali";
				cout<<"\n 7:00 am-------------------- 12:00 pm";
				cout<<"\n    From Sialkot to Jhelum";
				cout<<"\n 8:00 am-------------------- 10:30 am";
				break;
			}
			case 5:{
		system("cls");
		cout << "\n\n\n";
        cout << "\t\t\t\t\t\t\t ==========================================================\n";
        cout << "\t\t\t\t\t\t\t ################::BUS MANAGEMENT SYSTEM::################\n";
        cout << "\t\t\t\t\t\t\t ==========================================================\n\n\n";
				cout<<"\n    From Multan to Lahore";
				cout<<"\n 9:00 am-------------------- 11:00 am";
				cout<<"\n    From Daska to Faisalabad";
				cout<<"\n 12:00 am-------------------- 2:30 pm";
				cout<<"\n    From Sialkot to Quetta";
				cout<<"\n 4:00 am-------------------- 9:00 am";
				cout<<"\n    From Lahore to Multan";
				cout<<"\n 3:00 am-------------------- 3:00 am";
				cout<<"\n    From Sialkot to Islamabad";
				cout<<"\n 7:30 am-------------------- 5:30 pm";
				break;
			}
			default:
				cout<<"\n\n Invalid Choice....Please Try Again...";
				getch();
				goto p;
		}
	}
	void bus::detail_bus(){ //Input Validation + Displays seats information
		system("cls");
		cout<<"\n\t\t_______________BUS MANAGEMENT SYSTEM____________";
		fstream file,file1;
		string t_no,s_no,s_b_no;
		int count=0,found=0;
		file.open("bus.txt",ios::in);
		file1.open("seat.txt",ios::in);
		if(!file || !file1){
			cout<<"\n\n FILE NOT FOUND...";
		}
		else{
			cout<<"\n\n ENTER BUS NO : ";
			cin>>t_no;
			file1>>s_b_no>>s_no;
			while(!file1.eof()){
				if(t_no==s_b_no){
					count++;
				}
				file1>>s_b_no>>s_no;
			}
			file1.close();
			file>>b_no>>b_name>>b_seats>>d_name;
			while(!file.eof()){
				if(t_no==b_no){
				system("cls");
				cout << "\n\n\n";
       			 cout << "\t\t\t\t\t\t\t ==========================================================\n";
        		cout << "\t\t\t\t\t\t\t ################::BUS MANAGEMENT SYSTEM::################\n";
        		cout << "\t\t\t\t\t\t\t ==========================================================\n\n\n";
				cout<<"\n\n Total NO. of Seats : "<<b_seats;
					cout<<"\n\n Reserved No. of Seats : "<<count;
					cout<<"\n\n Empty No. of Seats : "<<b_seats-count;
					found++;

				}
			file>>b_no>>b_name>>b_seats>>d_name;
			}
			file.close();
			if(found==0){
				cout<<"\n\n Bus No. is Invalid....";
			}
		}
	}
	void bus::booking(){ // Reserves ticket,Generates comprehensive Invoice
		p:
		system("cls");
		cout << "\n\n\n";
        cout << "\t\t\t\t\t\t\t ==========================================================\n";
        cout << "\t\t\t\t\t\t\t ################::BUS MANAGEMENT SYSTEM::################\n";
        cout << "\t\t\t\t\t\t\t ==========================================================\n\n\n";
		fstream file;
		string t_no,s_b_no,cus_name,phone,from,to;
		char x;
		int s_no,seats=0,s_s_no,ss_no[25],i=0,s_amount;
		int count=0, found=0;	
		int total_amount,r_amount;
		file.open("bus.txt",ios::in);
		if(!file){
			cout<<"\n\nFile Opening ERROR.....";
		}
		else{
			cout<<"\n\nBus No. : ";
			cin>>t_no;
			file.close();
			file.open("seat.txt",ios::in);
			if(file)
			{
			file>>s_b_no>>s_s_no;
			while(!file.eof()){
				if(t_no==s_b_no){
					count++;
				}
				file>>s_b_no>>s_s_no;
				
			}
				file.close();
		}
			file.open("bus.txt",ios::in);
			file>>b_no>>b_name>>b_seats>>d_name;
			while(!file.eof()){
				if(t_no==b_no){
					seats=b_seats;
					found++;
				}
			file>>b_no>>b_name>>b_seats>>d_name;
			}
			file.close();
			if(seats-count == 0){
				cout<<"\n\n All Seats Are Already Booked";
			}
			else if(found==1)
			{
				do{
					h:
					cout<<"\n\n Enter Seat No. : ";
					cin>>s_no;
					if(s_no>seats){
						cout<<"\n\n Seat number is Invalid.....Please Try Again.";
						goto h;
					}
					file.open("seat.txt",ios::in);
					if(!file){
						file.open("seat.txt",ios::app | ios::out);
						file<<t_no<<" "<<s_no<<"\n";
						file.close();
						}
						else
						{
							file>>s_b_no>>s_s_no;
							while(!file.eof())
							{
								if(t_no== s_b_no && s_no ==s_s_no)
								{
									cout<<"\n\n Seat is Already Reserved....Please Enter Another Seat ";
									file.close();
									goto h;
								}
							file>>s_b_no>>s_s_no;	
							}
						file.close();
						file.open("seat.txt",ios::app | ios::in);
						file<<t_no<<" "<<s_no<<"\n";
						file.close();
					}			
					ss_no[i]=s_no;
					i++;   
					cout<<"\n\n Book Another Seat(Y/N) : ";
					cin>>x;
				}while(x=='y'||x=='Y');
				system("cls");
		cout << "\n\n\n";
        cout << "\t\t\t\t\t\t\t ==========================================================\n";
        cout << "\t\t\t\t\t\t\t ################::BUS MANAGEMENT SYSTEM::################\n";
        cout << "\t\t\t\t\t\t\t ==========================================================\n\n\n";
		cout<<"\n\n CUSTOMER NAME : ";
			 	cin>>cus_name;
			 	cout<<"\n\n Phone No. : ";
			 	cin>>phone;
			 	cout<<"\n\n From : ";
			 	cin>>from;
			 	cout<<"\n\n To : ";
			 	cin>>to;
			 	cout<<"\n\n Single Seat Fare : ";
			 	cin>>s_amount;
			 	total_amount=s_amount*i;
				cout<<"\n\n Total Amount : "<<total_amount;
				cout<<"\n\n Recieve Amount : ";
				cin>>r_amount;
			 	file.open("customer.txt",ios::app | ios::in);
			 	file<<cus_name<<" "<<t_no<<" "<<phone<<" "<<i<<" "<<total_amount<<"\n";
			 	file.close();
			 	system("cls");
			 	cout<<"\n\t\t_______________BUS MANAGEMENT SYSTEM____________";
			 	cout<<"\n\n\t\t************************************************";
			 	cout<<"\n\n\t\t_______________BOOKING INFORMATION______________";
			 	cout<<"\n\n\t\t************************************************";
			 	cout<<"\n\n\t\tCNAME :                  "<<cus_name;
			 	cout<<"\n\t\tFrom :                     "<<from;
			 	cout<<"\n\t\tTo :                       "<<to;
			 	cout<<"\n\t\tTotal Seats :              "<<i;
			 	cout<<"\n\t\tReserved Seat :            ";
			 	for(int a=0;a<i;a++)
			 	{
			 		if(a != 0)
			 			cout<<",";
			 			cout<<ss_no[a];
				 }
				 cout<<"\n\t\tSingle Seat Amount :      "<<s_amount;
				 cout<<"\n\t\tTotal Ammount :           "<<total_amount;
				 cout<<"\n\t\tRecieve Amount :          "<<r_amount;
				 cout<<"\n\t\tReturn Ammount :          "<<r_amount-total_amount;
				 cout<<"\n\n\t\t************************************************";
				 cout<<"\n\n\t\t    Thank You So Much For Your Time ";
				 cout<<"\n\n\t\t************************************************";
			}
			else{
				cout<<"\n\n Bus No. is Invalid..... Please Try Again";
				getch();
				goto p;
			}

		}
	}
	void bus::renew_bus(){ //Clears all the reservation i.e Delete the seat reservation file( not kidding)
	system("cls");
		cout << "\n\n\n";
        cout << "\t\t\t\t\t\t\t ==========================================================\n";
        cout << "\t\t\t\t\t\t\t ################::BUS MANAGEMENT SYSTEM::################\n";
        cout << "\t\t\t\t\t\t\t ==========================================================\n\n\n";
		fstream file;
	char x;
	file.open("seat.txt",ios::out);
	if(!file){
		cout<<"\n\n File Not Found.....";
	}
	else
	{
		cout<<"\n\n Do You want to Renew All Seats (Y/N) : ";
		cin>>x;
		if(x=='y' || x=='Y'){
			remove("seat.txt");
			cout<<"\n\n\t\t\t All Seats Are Empty....";
		}
		else{
			cout<<"\n\n\t\t\t Thank You All Seats Reservations Are Saved.......";
			
		}
	}

	}
	void bus::search_booking(){ // Searches booking Info by customer name and displays miscellaneous info 
	system("cls");
		cout << "\n\n\n";
        cout << "\t\t\t\t\t\t\t ==========================================================\n";
        cout << "\t\t\t\t\t\t\t ################::BUS MANAGEMENT SYSTEM::################\n";
        cout << "\t\t\t\t\t\t\t ==========================================================\n\n\n";
		fstream file;
	string name,no,phone,t_name;
	int t_seats,t_amo,found=0;
	file.open("customer.txt",ios::in);
	if(!file){
		cout<<"\n\nFile Opening Error......";
	}
	else{
		cout<<"\n\n Enter Customer Name to SEARCH : ";
		cin>>t_name;
		file>>name>>no>>phone>>t_seats>>t_amo;
		while(!file.eof())
		{
			if(t_name== name){
				if(found==0){
			system("cls");
		cout << "\n\n\n";
        cout << "\t\t\t\t\t\t\t ==========================================================\n";
        cout << "\t\t\t\t\t\t\t ################::BUS MANAGEMENT SYSTEM::################\n";
        cout << "\t\t\t\t\t\t\t ==========================================================\n\n\n";
		}
			cout<<"\n\n\n Customer Name : "<<name;
			cout<<"\n\n Bus No. : "<<no;
			cout<<"\n\n Phone No. : "<<phone;
			cout<<"\n\n Reserved Seats : "<<t_seats;
			cout<<"\n\n Total Amount : "<<t_amo;
			cout<<"\n\n===============================";
			found++;
			}
			file>>name>>no>>phone>>t_seats>>t_amo;
		}
		file.close();
		if(found ==0){
			cout<<"\n\n Customer Name in Invalid....";
		}
	}

	}
	void bus::update_booking(){ // Uses user's phone number for searching 1st, Deletes previous file and writes to new one
		system("cls");
		cout << "\n\n\n";
        cout << "\t\t\t\t\t\t\t ==========================================================\n";
        cout << "\t\t\t\t\t\t\t ################::BUS MANAGEMENT SYSTEM::################\n";
        cout << "\t\t\t\t\t\t\t ==========================================================\n\n\n";
		fstream file,file1;
		string name,no,phone,t_phone,del_no;
		int t_seats,t_amo,found=0,del_seats,i=0;
		file.open("customer.txt",ios::in);
		if(!file){
			cout<<"\n\n File Not Found.......";
		}
		else{
			cout<<"\n\n Phone No. : ";
			cin>>t_phone;
			file>>name>>no>>phone>>t_seats>>t_amo;
			while(!file.eof()){
				if(t_phone == phone){
					file.close();
					file.open("customer.txt",ios::in);
					file1.open("customer1.txt",ios::out | ios::app);
					file>>name>>no>>phone>>t_seats>>t_amo;
					while(!file.eof())
					{
						if(t_phone == phone)
						{
							del_no=no;
							del_seats=t_seats;
						}
						if(t_phone!=phone)
						{
							file1<<name<<" "<<no<<" "<<phone<<" "<<t_seats<<" "<<t_amo<<"\n";
						}
						file>>name>>no>>phone>>t_seats>>t_amo;
					}
					file.close();
					file1.close();
					remove("customer.txt");
					rename("customer1.txt","customer.txt");
					file.open("seat.txt",ios::in);
					file1.open("seat1.txt",ios::out | ios::app);
					file>>no>>t_seats;
					while(!file.eof())
					{
						if(!(del_no == no && i<del_seats))
						{
							file1<<no<<" "<<t_seats<<"\n";
						}
						file>>no>>t_seats;
					}
					file.close();
					file1.close();
					remove("seat.txt");
					rename("seat1.txt","seat.txt");
					booking();
					cout<<"\n\n\t\t\t BOOKING UPDATED SUCCESFULLY...";
					found++;
					goto h;
				}
				file>>name>>no>>phone>>t_seats>>t_amo;
			}
			file.close();
			h:
				if(found==0){
					cout<<"\n\n Phone Number Not found....";
				}

		}
	}
	void bus::DEL_BOOKING(){// Coding similar to coding function except a little tweak
		system("cls");
		cout << "\n\n\n";
        cout << "\t\t\t\t\t\t\t ==========================================================\n";
        cout << "\t\t\t\t\t\t\t ################::BUS MANAGEMENT SYSTEM::################\n";
        cout << "\t\t\t\t\t\t\t ==========================================================\n\n\n";
		fstream file,file1;
		string name,no,phone,t_name,t_phone,del_no;
		int t_seats,t_amo,found=0,del_seats,i=0;
		file.open("customer.txt",ios::in);
		if(!file){
			cout<<"\n\n File Not Found.......";
		}
		else{
			cout<<"\n\n Phone No. : ";
			cin>>t_phone;
			file>>name>>no>>phone>>t_seats>>t_amo;
			while(!file.eof()){
				if(t_phone == phone){
					file.close();
					file.open("customer.txt",ios::in);
					file1.open("customer1.txt",ios::out | ios::app);
					file>>name>>no>>phone>>t_seats>>t_amo;
					while(!file.eof())
					{
						if(t_phone == phone)
						{
							del_no=no;
							del_seats=t_seats;
						}
						if(t_phone!=phone)
						{
							file1<<name<<" "<<no<<" "<<phone<<" "<<t_seats<<" "<<t_amo<<"\n";
						}
						file>>name>>no>>phone>>t_seats>>t_amo;
					}
					file.close();
					file1.close();
					remove("customer.txt");
					rename("customer1.txt","customer.txt");
					file.open("seat.txt",ios::in);
					file1.open("seat1.txt",ios::out | ios::app);
					file>>no>>t_seats;
					while(!file.eof())
					{
						if(!(del_no == no && i<del_seats))
						{
							file1<<no<<" "<<t_seats<<"\n";
						}
						file>>no>>t_seats;
					}
					file.close();
					file1.close();
					remove("seat.txt");
					rename("seat1.txt","seat.txt");
					cout<<"\n\n\t\t\t Booking Deleted Successfully";
					found++;
					goto h;
				}
				file>>name>>no>>phone>>t_seats>>t_amo;
			}
			file.close();
			h:
				if(found==0){
					cout<<"\n\n Phone Number Not found....";
				}

		}
	}
	void bus::show_all_booking(){ // Search booking function except coding for search feature is removed
	system("cls");
		cout << "\n\n\n";
        cout << "\t\t\t\t\t\t\t ==========================================================\n";
        cout << "\t\t\t\t\t\t\t ################::BUS MANAGEMENT SYSTEM::################\n";
        cout << "\t\t\t\t\t\t\t ==========================================================\n\n\n";
		fstream file;
	string name,no,phone;
	int t_seats,t_amo,found=0;
	file.open("customer.txt",ios::in);
	if(!file){
		cout<<"\n\nFile Opening Error......";
	}
	else{
		file>>name>>no>>phone>>t_seats>>t_amo;
		while(!file.eof())
		{
			cout<<"\n\n\n Customer Name : "<<name;
			cout<<"\n\n Bus No. : "<<no;
			cout<<"\n\n Phone No. : "<<phone;
			cout<<"\n\n Reserved Seats : "<<t_seats;
			cout<<"\n\n Total Amount : "<<t_amo;
			cout<<"\n\n===============================";
			found++;
			file>>name>>no>>phone>>t_seats>>t_amo;
		}
		file.close();
		if(found ==0){
			cout<<"\n\n No Booking Record Found....";
		}
	}

	}
int main(){
	bus b;
	p:
		system("cls");
			double total;
		char ch;
	string email,pass;
	cout<<"\n\n\t\t\t*****Security Required*****";
	cout<<"\n\n Email : ";
	cin>>email;
	cout<<"\n\n Password : ";
	for(int i=1;i<=6;i++){
		ch=getch();
		pass+=ch;
		cout<<"*";
	}
	if(email=="admin@uskt"&&pass=="123456"){
		system("cls");
	cout << "\n\n\n\n\n\n\n\n\n\n";
    cout << "\n\t\t\t ================================================\n";
    cout << "\t\t\t ||                  WELCOME TO                ||\n";
    cout << "\t\t\t ||                                            ||\n";
    cout << "\t\t\t ||            BUS RESERVATION SYSTEM          ||\n";
    cout << "\t\t\t ||                                            ||\n";
    cout << "\t\t\t ||                    PROJECT                 ||\n";
    cout << "\t\t\t ================================================\n\n\n";

    cout << "\t\t\t-------------------------------------------------\n";
    cout << "\t\t\t  Developed By:-           \t\n";
    cout << "\t\t\t                           \t\n";
    cout << "\t\t\t  Usman Ashraf 197         \t\n";
    cout << "\t\t\t-------------------------------------------------\n\n";
		cout<<"\n\n\n\t\t\tLoading";
		for(int i=1;i<=32;i++)
		{
			Sleep(50);
		cout<<".";
		system("color 0f");
		}
		cout<<"\n\n\n\t\t\tLOADING COMPLETE.\n\n\n\t\t\t";
		Sleep(750);
    system("pause");
		b.menu();
	}
	else
	{
		cout<<"\n\n\t\tYour Email or Password is Incorrect...\n";
		system("pause");
	goto p;
	}
}
