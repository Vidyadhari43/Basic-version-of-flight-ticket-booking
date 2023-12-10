#include<iostream>
#include<fstream>
#include <queue>

using namespace std;

void main_menu();
queue<int>history;

class Management
{
	public:
		Management(){
			main_menu();
		}
};

class Details_info
{
	public:
		
		static string name, gender;
		int phoneNo;
		int age;
		string add;
		static int cId;
		char arr[100];
		bool info=false;
		void information()
		{
			cout<<"\nEnter the customer ID:";
			cin>>cId;
			cout<<"\nEnter the name :";
			cin>>name;
			cout<<"\nEnter the age :";
			cin>>age;
			cout<<"\n Address :";
			cin>>add;
			cout<<"\n Gender :";
			cin>>gender;
			cout<<"Your details saved successfully\n"<<endl;
			info=true;
		}
};

int Details_info::cId;
string Details_info::name;
string Details_info::gender;

class Registration_ticket
{
	public:
		static int choice;
		int choice1;
		int back;
		static float charges;
		bool booking=false;
		void flights()
		{
			string flightN[]={"Canada","UK","USA"};
			
			for(int a=0;a<3;a++)
			{
				cout<<(a+1)<<".flight to "<<flightN[a]<<endl;
				
			}
			
			cout<<"\nWelcome to the Airlines!\n"<<endl;
			cout<<"Enter ther number of the country of which you want to book the flight:";
			cin>>choice;
			
			switch(choice){
			case 1:
				{
					cout<<"_______________________Welcome to Canadian Airlines____________________\n"<<endl;
						
						cout<<"Following are the flights \n"<<endl;
						
						cout<<"1. Flight-1"<<endl;
						cout<<"Date: 09-10-2023 \n departure time: 2:00PM\n Journey time: 20hrs\n Ticket fare: Rs. 34000"<<endl;
						cout<<"2. Flight-2"<<endl;
						cout<<"Date: 10-10-2023 \n departure time: 6:00AM\n Journey time: 23hrs\n Ticket fare: Rs. 29000"<<endl;
						
						cout<<"\nSelect the flight you want to book :";
						cin>>choice1;
						
						if(choice1==1)
						{
							charges=34000;
							cout<<"\nYou have successfully booked the Flight-1"<<endl;
							cout<<"You can go  back to menu and take the ticket"<<endl;
							booking=true;
						}
						
						else if(choice1==2)
						{
							charges=29000;
							cout<<"\nYou have successfully booked the Flight-2"<<endl;
							cout<<"You can go  back to menu and take the ticket"<<endl;booking=true;
						}
						else
						{
							cout<<"Invalid input , redirecting to the previous menu"<<endl;
							flights();
						}
						break;
				}
				
			case 2:
			{
				
				cout<<"_______________________Welcome to UK Airways____________________\n"<<endl;
					
					cout<<"Following are the flights \n"<<endl;
					
					cout<<"1. Flight-1"<<endl;
					cout<<"Date: 13-10-2023 \n departure time: 10:00AM\n Journey time: 14hrs\n Ticket fare: Rs. 44000"<<endl;
					cout<<"\nSelect the flight you want to book :";
					cin>>choice1;
					
					if(choice1==1)
					{
						charges=44000;
						cout<<"\nYou have successfully booked the Flight-1"<<endl;
						cout<<"You can go  back to menu and take the ticket"<<endl;booking=true;
					}
					
					
					else
					{
						cout<<"Invalid input , redirecting to the previous menu"<<endl;
						flights();
					}
					break;
				
			}
			case 3:
				{
					cout<<"_______________________Welcome to US Airways____________________\n"<<endl;
					
					cout<<"Following are the flights \n"<<endl;
					cout<<"1. Flight-1"<<endl;
					cout<<"Date: 10-10-2023\n departure time: 9:00AM\n Journey time: 22hrs\n Ticket fare: Rs. 37000"<<endl;
					cout<<"2. Flight-2"<<endl;
					cout<<"Date: 09-10-2023\n departure time: 6:00AM\n Journey time: 22hrs\n Ticket fare: Rs. 39000"<<endl;
					
					cout<<"\nSelect the flight you want to book :";
					cin>>choice1;
					if(choice1==1)
					{
						charges=37000;
						cout<<"\nYou have successfully booked the Flight-1"<<endl;
						cout<<"You can go  back to menu and take the ticket"<<endl;booking=true;
					}
					else if(choice1==2)
					{
						charges=39000;
						cout<<"\nYou have successfully booked the Flight-2"<<endl;
						cout<<"You can go  back to menu and take the ticket"<<endl;booking=true;
					}
					else
					{
						cout<<"Invalid input , redirecting to the previous menu"<<endl;
						flights();
					}
					break;
				}
			
			default :
				{
					cout<<"Invalid input "<<endl;
					break;
				}
		}
		if(history.front()==3){
			cout<<"Enter any number to resume displaying your ticket:"<<endl;
			cin>>back;
		}
		else{
			cout<<"Enter any number to go back to the main menu:"<<endl;
			cin>>back;
			main_menu();
		}
	}
};
Details_info d;
Registration_ticket r;
float Registration_ticket::charges;
int Registration_ticket::choice;

class ticket : public Registration_ticket, Details_info
{
	public:
		
		void Bill()
		{
			string destination="";
			ofstream outf("records.txt");
			{
				outf<<"_____________XYZ Airlines____________"<<endl;
				outf<<"______________Ticket_________________"<<endl;
				outf<<"_____________________________________"<<endl;
				
				outf<<"Customer ID:"<<Details_info::cId<<endl;
				outf<<"Customer Name:"<<Details_info::name<<endl;
				outf<<"Customer Gender:"<<Details_info::gender<<endl;
				outf<<"\tDescription"<<endl<<endl;
				if(Registration_ticket::choice==1)
				{
					destination="Canada";
				}
				else if(Registration_ticket::choice==2)
				{
					destination="UK";
				}
				else if(Registration_ticket::choice==3)
				{
					destination="USA";
				}
				
				outf<<"Destination\t\t"<<destination<<endl;
				outf<<"Flight cost :\t\t"<<Registration_ticket::charges<<endl;
				
			}
			outf.close();
			
		}
		void dispBill()
		{
			ifstream ifs("records.txt");
			{
				if(!ifs)
				{
					cout<<"File error!"<<endl;
				}
				while(!ifs.eof())
				{
					ifs.getline(arr, 100);
					cout<<arr<<endl;
				}
			}
			ifs.close();
		}
};

void main_menu()
{
	int lchoice;
	int schoice;
	int back;
	
	cout<<"\t               XYZ Airlines \n"<<endl;
	cout<<"\t______________Main Menu______________\n"<<endl;
	
	cout<<"\t\t Enter 1 to add the Customer Details_info    \t"<<endl;
	cout<<"\t\t Enter 2 for Flight Registration_ticket        \t"<<endl;
	cout<<"\t\t Enter 3 to display your ticket         \t"<<endl;
	cout<<"\t\t Enter 4 to Exit                        \t"<<endl;
	cout<<"\t\t\t\t\t\t\t" <<endl;
	cout<<"\t_____________________________________________________"<<endl;
	
	cout<<"Enter the choice : ";
	cin>>lchoice;
	
	
	ticket t;
	switch(lchoice)
	{
		
		case 1:
			{
			   cout<<"__________Customers__________\n"<<endl;
			   	d.information();
			   	cout<<" Enter any number to go back to Main menu ";
			   	cin>>back;
			   	main_menu();
				   break;
			}
			
		case 2:
			{
				cout<<"________Book a flight using this system ____________\n"<<endl;
				r.flights();
				main_menu();
				break;
			}
			
		case 3:{
			history.push(3);
			while(!d.info){
				cout<<"Enter your information and complete booking process to display your ticket\n";
				d.information();
			}
			while(!r.booking){
				cout<<"Select the flight and complete booking process to display your ticket\n\n";
				r.flights();
			}
			system("clear");
			cout<<"_____GET YOUR TICKET____\n"<<endl;
			t.Bill();
			t.dispBill();
			cout<<"Enter any number to go back to main menu:";
			cin>>back;
			d.info=false;
			r.booking=false;
			main_menu();
			history.pop();
			break;
		}
	
		case 4:
			{
				cout<<"\n\n\t_________Thankyou_______"<<endl;
				break;
			}
			
		default :
			{
				cout<<"Invalid input, Please try again!\n"<<endl;
				main_menu();
				break;
			}
	}
}

int main()
{
	Management Mobj;
	return 0;
}
