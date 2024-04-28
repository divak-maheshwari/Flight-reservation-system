#include <iostream>
#include <iomanip>
#include "flight_reservation.h"
using namespace std;

int reserve = 999;

int seat[size];
void seat_fill()
{
	for (int i = 0; i < size; i++)
	{
		seat[i] = 0;
	}
}

bool taken=false;
bool seat_no(int y)
{

        for (int i = 0; i < size; i++ )
        {
                if( seat[i] == -1 )
                {
				taken=true;
  	                 cout << "The seat is taken already. \n";
                        cout << "Please choose another seat number from below."<<endl;

				int j = 1;
				while ( j < size+1 )
				{
					if ( seat[j-1] == -1)
					j++;
					else
					{
						cout <<"|" << j << "|";
						if ( j%10 == 0 )
						cout << endl;
						j++;
					}

                		}
		}

        }

}

void menu()
{
char choice;

do{
cout <<"\t --------------------------------------------------------------------------------- \n";
cout <<"\t Make Reservation [1] \n";
cout <<"\t --------------------------------------------------------------------------------- \n";
cout <<"\t Cancel Reservation [2] \n ";
cout <<"\t --------------------------------------------------------------------------------- \n";
cout <<"\t Search Passenger [3] \n";
cout <<"\t --------------------------------------------------------------------------------- \n";
cout <<"\t Change Reservation [4] \n";
cout <<"\t --------------------------------------------------------------------------------- \n";
cout <<"\t Print a list [5] \n";
cout <<"\t --------------------------------------------------------------------------------- \n";
cout <<"\t Print status Report [6] \n ";
cout <<"\t --------------------------------------------------------------------------------- \n";
cout <<"\t Quit [7] \n ";
cout <<"\t --------------------------------------------------------------------------------- \n";
// cout <<"   --------------------------------------------------------------------------------- \n";
cout <<"   Option : ";

	cin >> choice;
	choice = ((int)(choice)-48);

	switch (choice)
	{
	case 1: system("CLS"); bluesky.make_reservation();
					break;
	case 2: system("CLS"); bluesky.cancel_reservation();
					break;
	case 3: system("CLS"); bluesky.search_passenger();
					break;
	case 4: system("CLS"); bluesky.change_reservation();
					break;
	case 5: system("CLS"); bluesky.print_list();
					break;
	case 6: system("CLS"); bluesky.print_report();
					break;
	case 7: cout << "\n\nThank you come again\n\n\n";
					break;

	default: cout<<" Don't be like a DORK!!! \n\n";
		break;


	}	// Ending case loop.


	cout<<"\n   PROCESS COMPLETED...\n\n";

	cin.get();
	if(cin.get()=='\n')
		system("CLS");


    cout<<"\n  ------------------------------------------------------------------------------- " << endl;
	cout << "\t    AIRLINE RESERVATION SYSTEM \n";
	cout<<" --------------------------------------------------------------------------------- \n" << endl;
	cout<<" --------------------------------------------------------------------------------- \n" << endl;

 }while(choice != 7 );

}

//************************************************************************
airlines::airlines()
{
	start = NULL;
}

//*************************************************************************
void airlines:: make_reservation()
{
	int meal_choice, x;

	temp = new node;

	cout << "\n\n   Enter First Name of person: ";
	cin >> temp->fname;
	cout << "   --------------------------------------------------------------------------------- \n";
	cout << "   Enter Last Name of Person: ";
	cin >> temp->lname;
	cout << "   --------------------------------------------------------------------------------- \n";
	cout << "   Enter ID of the person: ";
	cin >> temp->ID;
	cout <<"   ---------------------------------------------------------------------------------\n";
	cout <<"   Enter Phone Number of Person: ";
	cin >> temp -> phone_num;
	cout<<"   --------------------------------------------------------------------------------- \n";

	do{
	cout << "   Please Enter the Seat Number: ";
		cin>>x;
		while(x>size){
		cout<<"   Try again:: ";
		cin >>x;
		}
	cout << " --------------------------------------------------------------------------------- \n";
		if((seat[x-1])>-1)
		taken = false;
		else
		seat_no(x);
	seat[x-1] = -1;
	temp->seat_num = x;
	}
	while(taken==true);

//******************************************************************************

		cout << "   Please Enter Your Menu Preference from below: \n\n";
		cout << "      Veg     ..... '1'\n";
		cout << "      Non-Veg ..... '2'\n";
		cout << "      No meal ..... '3'\n\n";

		cout << "   Your Choice :: ";
		cin >> meal_choice;

		while(meal_choice>3 || meal_choice<1){
		cout<<"   Try Again:: ";
		cin>>meal_choice;
		}
		if (meal_choice == 1)
		temp->menu = "veg";
		else if (meal_choice == 2)
		temp->menu = "Non-Veg";
		else
		temp->menu = "No meal";
	reserve++;
	temp -> reserve_num=reserve;
	cout << "\n --------------------------------------------------------------------------------- \n";
	cout << "   YOUR RESERVATION NUMBER IS :: " << reserve << "\n";
	cout << " --------------------------------------------------------------------------------- \n";

	temp -> next = NULL;

	if(start == NULL)
		start = temp;
	else
	{
		temp2 = start;
		while (temp2->next != NULL)
		{
			temp2 = temp2->next;
		}
		temp2->next = temp;
	}

}
//********************************************************************************************
int cancel=0;
void airlines:: cancel_reservation()
{	int num;
	cout << "Please Enter your reservation Number here: ";
	cin >> num;

		node *cur = start;
		if(cur!=NULL)
		{

		if ( start->reserve_num == num )
		{
			node *del = start;
			start = start->next;
			delete del;
			seat[0] = 0;
			cancel++;
			return;
		}
		else
		{
			node *pre, *cur;
			pre = start;
			cur = start->next;
			while(cur != NULL)
			{
				if ( cur->reserve_num == num )
						break;
				pre = cur;
				cur = cur->next;
			}
			seat[cur->seat_num-1] = 0;
			if (cur != NULL )
			pre->next = cur->next;

		}

	cancel++;


		}
		else
		{
		cout<<"!!! *** Nothing to delete or invalid entry *** !!! \n"<<endl;
		}

}
//********************************************************************************************
void airlines:: search_passenger()
{
		string fakename;
		cout << "Please enter your first name here: ";
		cin >> fakename;

		node *cur = start;
		while (cur != NULL)
		{
			if (cur->fname == fakename)
			{
				cout << "First Name : " << cur->fname << endl;
				cout << "Last Name : " << cur->lname << endl;
				cout << "ID " << cur->ID << endl;
				cout << "Phone number: " << cur->phone_num << endl;
				cout << "Seat Number: " << cur->seat_num << endl;
				cout << "Reservation No. " << cur->reserve_num<< endl;
				return;
			}	cur = cur->next;
		}	cout << " Sorry!!! NOT FOUND \n\n";

}

//********************************************************************************************
void airlines:: change_reservation()

{
	int option , next_seat;
	cout << " Please enter your seat number: ";
	cin >> option;
	node *cur;
	cur = start;

	while(cur != NULL)
	{
		if ( cur->seat_num == option )
			break;
		cur = cur->next;
	}
	cout << "Please choose another seat number from below.";
		int j = 1;
		while ( j < size+1 )
		{
			if ( seat[j-1] == -1)
			j++;
			else
			{
			cout <<"| " << j << "|";
			if ( j%10 == 0 )
			cout << endl;
			j++;
			}
		}
	cin >> next_seat;
	seat[cur->seat_num-1]=0;
	cur->seat_num = next_seat;
	seat[next_seat-1] = -1;

}

//********************************************************************************************
void airlines:: print_list()
{
	temp=start;
	if(temp == NULL)
	cout<<" End of lists"<<endl;
	else
	{	int cnt = 1;
		cout << "\tNumber\t First Name\t Last Name\t ID\t";
		cout << "Phone Number\t Seat Number\t Reservation No\t Menu\n";

		while(temp != NULL)
		{
			cout << "\t" << cnt <<setw(15);
			cout << temp->fname <<setw(15);
			cout << temp->lname << setw(12);
			cout << temp->ID << setw(12);
			cout << temp->phone_num <<setw(15);
			cout << temp->seat_num <<setw(15);
			cout << temp->reserve_num <<setw(12);
			cout << temp->menu << "\n";

			temp=temp->next;
			cnt++;
		}
		cout << "\n\n";

	}
}
//********************************************************************************************

void airlines:: print_report()
{	int count = 0;
	for (int i =0; i < size; i++ )
	{
		if (seat[i] == -1)
			count++;
	}
	cout << "Number of reserved seats are: " << count << endl;
	cout << "Number of cancellations are: " << cancel << endl;
}

//********************************************************************************************
