#include <iostream>
#include <fstream>                              //for adding data through a file
#include <string>                               //same reason as above
#include <functional>                           //allows for sorting of different data types
#include <cstdlib>                              //for generating data for dataset ie strings & ints
#include <ctime>                                //same reason as above
#include <map>                                  //used for condensing sorting choice code
#include <chrono>                               //use for time
#include <iomanip>
#include "flight_reservation.h"

using namespace std;

int reserve = 999;

int seat[size];
void airlines::seat_fill()
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
  return false;                  //(temporary to remove error) Can be removed later 
}

void airlines::menu()
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
cout <<"\t Test [8] \n ";
cout <<"\t --------------------------------------------------------------------------------- \n";
// cout <<"   --------------------------------------------------------------------------------- \n";
cout <<"   Option : ";

	cin >> choice;
	choice = ((int)(choice)-48);

	switch (choice)
	{
	case 1: system("CLS"); make_reservation();
					break;
	case 2: system("CLS"); cancel_reservation();
					break;
	case 3: system("CLS"); search_passenger();
					break;
	case 4: system("CLS"); change_reservation();
					break;
	case 5: system("CLS"); print_list();
					break;
	case 6: system("CLS"); print_report();
					break;
	case 7: cout << "\n\nThank you come again\n\n\n";
					break;
  case 8: system("CLS"); test_menu();
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


//working function
// void airlines:: print_list()
// {
// 	temp=start;
// 	if(temp == NULL)
// 	cout<<" End of lists"<<endl;
// 	else
// 	{	int cnt = 1;
// 		cout << "\tNumber\t First Name\t Last Name\t ID\t";
// 		cout << "Phone Number\t Seat Number\t Reservation No\t Menu\n";

// 		while(temp != NULL)
// 		{
// 			cout << "\t" << cnt <<setw(15);
// 			cout << temp->fname <<setw(15);
// 			cout << temp->lname << setw(12);
// 			cout << temp->ID << setw(12);
// 			cout << temp->phone_num <<setw(15);
// 			cout << temp->seat_num <<setw(15);
// 			cout << temp->reserve_num <<setw(12);
// 			cout << temp->menu << "\n";

// 			temp=temp->next;
// 			cnt++;
// 		}
// 		cout << "\n\n";

// 	}
// }

//testing..
// void airlines::print_list() {
//     temp = start;
//     if (temp == NULL)
//         cout << "End of lists" << endl;
//     else {
//         // Store nodes in a vector
//         vector<node*> nodes;
//         while (temp != NULL) {
//             nodes.push_back(temp);
//             temp = temp->next;
//         }

//         // Sort nodes based on seat number
//         sort(nodes.begin(), nodes.end(), [](node* a, node* b) {
//             return a->seat_num < b->seat_num;
//         });

//         // Print the sorted list
//         int cnt = 1;
//         cout << "\tNumber\t First Name\t Last Name\t ID\t";
//         cout << "Phone Number\t Seat Number\t Reservation No\t Menu\n";
//         for (auto& n : nodes) {
//             cout << "\t" << cnt++ << setw(15);
//             cout << n->fname << setw(15);
//             cout << n->lname << setw(12);
//             cout << n->ID << setw(12);
//             cout << n->phone_num << setw(15);
//             cout << n->seat_num << setw(15);
//             cout << n->reserve_num << setw(12);
//             cout << n->menu << "\n";
//         }
//     }
//     cout << "\n\n";
// }


// restesting for table
#include <iostream>
#include <iomanip> // for setw
#include <vector>
#include <algorithm> // for sort
using namespace std;

void airlines::print_list() {
    temp = start;
    if (temp == NULL) {
        cout << "End of lists" << endl;
    } else {
        // Store nodes in a vector
        vector<node*> nodes;
        while (temp != NULL) {
            nodes.push_back(temp);
            temp = temp->next;
        }

        // Sort nodes based on seat number
        sort(nodes.begin(), nodes.end(), [](node* a, node* b) {
            return a->seat_num < b->seat_num;
        });

        // Print the table header
        cout << left << setw(8) << "Number" << setw(15) << "First Name" << setw(15) << "Last Name" << setw(10) << "ID";
        cout << setw(15) << "Phone Number" << setw(15) << "Seat Number" << setw(15) << "Reservation No" << setw(10) << "Menu\n";
        
        // Print a horizontal line
        cout << left << setfill('-') << setw(93) << "-" << endl;
        cout << setfill(' ');

        // Print each row of the table
        int cnt = 1;
        for (auto& n : nodes) {
            cout << setw(8) << cnt++ << setw(15) << n->fname << setw(15) << n->lname << setw(10) << n->ID;
            cout << setw(15) << n->phone_num << setw(15) << n->seat_num << setw(15) << n->reserve_num << setw(10) << n->menu << "\n";
        }
    }
    cout << "\n\n";
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

//everything below are added functions for sorting/testing

void airlines::test_menu(){
  int input = 0;
  while(input != -1){                                                
    cout << "Test menu. Enter '-1' to quit." << endl
       << "1. Add file to use as dataset." << endl
       << "2. Generate a random dataset. (Please use this to create a dataset to sort through if a dataset has not been provided)" << endl
       << "3. Time sorting algorithms." << endl
       << "4. Sort data." << endl
       << "Enter number here: ";
    cin >> input;
    cout << endl;

    if(input == -1){
      cout << "Program quit." << endl;
      return;
    }
    else if(input == 1){
      string file;
      cout << "Enter the name of the file. (Case sensitive; use 'reservations.txt')" << endl
           << "Enter here: ";
      cin >> file;
      add(file);
      cout << "File '" << file << "' added." << endl;
    }
    else if(input == 2){
      int gen = 0;
      cout << "Enter the number of datapoints you want to be generated: ";
      cin >> gen;
      generateData(gen);
      print_list();
    }
    else if(input == 3){
      int choice = 0;
      while(choice != 1){
        cout << "Select the sorting method you would like to time: " << endl
             << "1. Time normal quick sort (quickSort1)." << endl
             << "2. Time quick sort with insertion sort (quickSort2)." << endl
             << "3. Time merge sort. (mergeSort)" << endl
             << "4. Time all." << endl
             << "Enter here: ";
        cin >> choice;
        cout << endl;

        if(choice == -1){
          cout << "Returning to test menu." << endl;
          break;
        }
        else if(choice == 1){                  //times quicksort1
          askSortTiming(1);
        }
        else if(choice == 2){                  //times quicksort2
          askSortTiming(2);
        }
        else if(choice == 3){                  //times mergesort
          askSortTiming(3);
        }
        else if(choice == 4){
          testAllSorts();
        }
        else{
          cout << "Invalid input. Please try again." << endl;
          continue;
        }
      }
    }
    else if(input == 4){
      map<int, function<bool(const node*, const node*)>> comparisons = {
          {1, [](const node* a, const node* b){ return a->fname < b->fname; }},
          {2, [](const node* a, const node* b){ return a->fname > b->fname; }},
          {3, [](const node* a, const node* b){ return a->lname < b->lname; }},
          {4, [](const node* a, const node* b){ return a->lname > b->lname; }},
          {5, [](const node* a, const node* b){ return a->ID < b->ID; }},
          {6, [](const node* a, const node* b){ return a->ID > b->ID; }},
          {7, [](const node* a, const node* b){ return a->phone_num < b->phone_num; }},
          {8, [](const node* a, const node* b){ return a->phone_num > b->phone_num; }},
          {9, [](const node* a, const node* b){ return a->seat_num < b->seat_num; }},
          {10, [](const node* a, const node* b){ return a->seat_num > b->seat_num; }},
          {11, [](const node* a, const node* b){ return a->reserve_num < b->reserve_num; }},
          {12, [](const node* a, const node* b){ return a->reserve_num > b->reserve_num; }}
      };

      int choice = 0;
      while(choice != -1){
        cout << "Sort by (Enter '-1' to return to test menu.): " << endl
             << "1. First Name (A - Z)" << endl
             << "2. First Name (Z - A)" << endl
             << "3. Last Name (A - Z)" << endl
             << "4. Last Name (Z - A)" << endl
             << "5. ID (Ascending)" << endl
             << "6. ID (Decending)" << endl
             << "7. Phone Number (Ascending)" << endl
             << "8. Phone Number (Decending)" << endl
             << "9. Seat Number (Ascending)" << endl
             << "10. Seat Number (Decending)" << endl
             << "11. Reservation Number (Ascending)" << endl
             << "12. Reservation Number (Decending)" << endl
             << "Enter here: ";
        cin >> choice;
        cout << endl;

        if(choice == -1){
            cout << "Returning to test menu." << endl;
            break;
        }
        else if(comparisons.count(choice)){
            quickSort2<node>(comparisons[choice]);
            print_list();
        }
        else{
            cout << "Invalid choice entered. Please try again." << endl;
        }
      }
    }
    else{
      cout << "Invalid input. Please try again." << endl;
      continue;
    }
  }
}

void airlines::add(string fileName){
  ifstream ifs;                                      //open file
  ifs.open(fileName);

  if(!ifs.is_open()){                                //check for error opening file
    cout << "Error opening file" << endl;
    return;
  }
  else{
    string fname, lname, ID, phone_num, menu, reserve_num, seat_num;        //student variable to create student object
    int reserve_numINT, seat_numINT;

    while(getline(ifs, fname, ',')){                 //read file contents
      getline(ifs, lname, ',');
      getline(ifs, ID, ',');
      getline(ifs, phone_num, ',');
      getline(ifs, menu, ',');
      getline(ifs, reserve_num, ',');
      getline(ifs, seat_num, '\n');
      reserve_numINT = stoi(reserve_num);            //convert strings to int to store
      seat_numINT = stoi(seat_num);

      node* tTemp = new node;                               //create a new node to add onto LinkedList
      tTemp->fname = fname;
      tTemp->lname = lname;
      tTemp->ID = ID;
      tTemp->phone_num = phone_num;
      tTemp->menu = menu;
      tTemp->reserve_num = reserve_numINT;
      tTemp->seat_num = seat_numINT;

      if(start == NULL){
        start = tTemp;
        start->next = NULL;
      }
      else{
        node* tTemp2 = start;
        while(tTemp2->next != NULL){
          tTemp2 = tTemp2->next;
        }
        tTemp2->next = tTemp;
        tTemp->next = NULL;
      }
      trackSize++;
    }
  }
  ifs.close();
}            //add reservations through a file

void airlines::generateData(int gen){
  //for generation of strings
  const char flname[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
  const char IDPhoneSeat[] = "0123456789";

  int flnameSize = sizeof(flname) - 1;            //take chars from the specified char arrays
  int IDPhoneSeatSize = sizeof(IDPhoneSeat) - 1;
  int flnameLength = 10;                          //length of generated strings
  int IDLength = 10;
  int PhoneLength = 10;
  string fnameStr(flnameLength, 0);              //store generated strings
  string lnameStr(flnameLength, 0);
  string IDStr(IDLength, 0);
  string PhoneStr(PhoneLength, 0);
  string menu = "menu";

  ofstream ofs;                                      //open file
  ofs.open("random.txt");

  if(!ofs.is_open()){                                //check for error opening file
    cout << "Error opening file" << endl;
    return;
  }

  srand(time(0));

  for(int genTimes = 0; genTimes < gen; genTimes++){
    for(int i = 0; i < flnameLength; i++){
      fnameStr[i] = flname[rand() % flnameSize];
    }
    for(int i = 0; i < flnameLength; i++){
      lnameStr[i] = flname[rand() % flnameSize];
    }
    for(int i = 0; i < IDLength; i++){
      IDStr[i] = IDPhoneSeat[rand() % IDPhoneSeatSize];
    }
    for(int i = 0; i < PhoneLength; i++){
      PhoneStr[i] = IDPhoneSeat[rand() % IDPhoneSeatSize];
    }


    //for generation of ints
    int seatNum = rand() % 1000;
    int reserveNum = rand() % 1000;

    ofs << fnameStr << ", " << lnameStr << ", " << IDStr << ", " << PhoneStr << ", " << menu << ", " << reserveNum << ", " << seatNum << "\n";
  }

  ofs.close();                    //close random.txt file
  add("random.txt");              //add random.txt contents into linkedlist
}

void airlines::askSortTiming(int option){
  int dataSets = 0;
  cout << "How many datasets do you want to sort?" << endl
       << "Enter here: ";
  cin >> dataSets;
  cout << endl;

  int dataSetSize = 0;
  cout << "How much data do you want to add to the dataset continuously?" << endl
       << "Enter here: ";
  cin >> dataSetSize;
  cout << endl;

  int* oneSortTime = new int[dataSets];          //array to keep track of time for only 1 sorting 
  int oneSortTimeTotal = 0;
  int oneSortAvgTime;

  int** allSortTimes = new int*[12];            //array to keep track of all 12 type sorts
  for(int i = 0; i < 12; i++){
    allSortTimes[i] = new int[dataSets];
  }
  int sortTimeTotal[12] = {0};
  int sortTimeAvg[12];

  int choice = 0;
  while(choice != -1){
    cout << "Time sorting type: (Enter '-1' to return to time test menu.): " << endl
         << "1. First Name (A - Z)" << endl
         << "2. First Name (Z - A)" << endl
         << "3. Last Name (A - Z)" << endl
         << "4. Last Name (Z - A)" << endl
         << "5. ID (Ascending)" << endl
         << "6. ID (Decending)" << endl
         << "7. Phone Number (Ascending)" << endl
         << "8. Phone Number (Decending)" << endl
         << "9. Seat Number (Ascending)" << endl
         << "10. Seat Number (Decending)" << endl
         << "11. Reservation Number (Ascending)" << endl
         << "12. Reservation Number (Decending)" << endl
         << "13. Test all" << endl 
         << "Enter here: ";
    cin >> choice;
    cout << endl;

    if(choice == -1){
      cout << "Returning to test menu." << endl;
      break;
    }
    else if(choice == 13){
      for(int j = 0; j < dataSets; j++){
        generateData(dataSetSize);
        for(int i = 1; i < 13; i++){
          auto start = chrono::high_resolution_clock::now();      //begin timer

          selectSortingMethod(i, option);

          auto stop = chrono::high_resolution_clock::now();       //end timer
          auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);    //take time

          print_list();
          allSortTimes[i - 1][j] = duration.count();
          sortTimeTotal[i - 1] += allSortTimes[i - 1][j];
        }
      }
      for(int i = 0; i < 12; i++){
        sortTimeAvg[i] = sortTimeTotal[i] / dataSets;
      }
      cout << "Average Timings: " << endl
           << "1. First Name (A - Z): " << sortTimeAvg[0] << "ns" << endl
           << "2. First Name (Z - A): " << sortTimeAvg[1] << "ns" << endl
           << "3. Last Name (A - Z): " << sortTimeAvg[2] << "ns" << endl
           << "4. Last Name (Z - A): " << sortTimeAvg[3] << "ns" << endl
           << "5. ID (Ascending): " << sortTimeAvg[4] << "ns" << endl
           << "6. ID (Decending): " << sortTimeAvg[5] << "ns" << endl
           << "7. Phone Number (Ascending): " << sortTimeAvg[6] << "ns" << endl
           << "8. Phone Number (Decending): " << sortTimeAvg[7] << "ns" << endl
           << "9. Seat Number (Ascending): " << sortTimeAvg[8] << "ns" << endl
           << "10. Seat Number (Decending): " << sortTimeAvg[9] << "ns" << endl
           << "11. Reservation Number (Ascending): " << sortTimeAvg[10] << "ns" << endl
           << "12. Reservation Number (Decending): " << sortTimeAvg[11] << "ns" << endl;
          exit(0);
    }
    else if(choice < 13 && choice > 0){
      for(int i = 0; i < dataSets; i++){
        // clearLinkedList();
        generateData(dataSetSize);
        auto start = chrono::high_resolution_clock::now();      //begin timer

        selectSortingMethod(choice, option);

        auto stop = chrono::high_resolution_clock::now();       //end timer
        auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);    //take time

        print_list();
        oneSortTime[i] = duration.count();
        oneSortTimeTotal += oneSortTime[i];
        cout << "Individual Time: " << oneSortTime[i] << "ns Sort Time Total:" << oneSortTimeTotal << "ns" << endl;
      }
      oneSortAvgTime = oneSortTimeTotal / dataSets;
      cout << "Average Time: " << oneSortAvgTime << "ns" << endl;
      exit(0);
    }
    else{
      cout << "Invalid choice entered. Please try again." << endl;
    }
  }
  delete [] oneSortTime;
  for(int i = 0; i < 12; i++) {
    delete[] allSortTimes[i];
  }
  delete[] allSortTimes;
}

void airlines::testAllSorts(){
  int dataSets = 0;
  cout << "How many datasets do you want to sort?" << endl
       << "Enter here: ";
  cin >> dataSets;
  cout << endl;

  int dataSetSize = 0;
  cout << "How much data do you want to add to the dataset continuously?" << endl
       << "Enter here: ";
  cin >> dataSetSize;
  cout << endl;

  int*** allSorts = new int**[3];                            //keep track of all times
  for(int i = 0; i < 3; i++){                                //quick1, quick2, merge
    allSorts[i] = new int*[12];
    for(int j = 0; j < dataSets; j++){
      allSorts[i][j] = new int[dataSets];
    }
  }
  int sortTimeTotal[3][12] = {{0}};
  int sortTimeAvg[3][12];

  for(int j = 0; j < dataSets; j++){
    generateData(dataSetSize);
    for(int i = 1; i < 13; i++){
      for(int option = 1; option < 4; option++){
        auto start = chrono::high_resolution_clock::now();      //begin timer

        selectSortingMethod(i, option);

        auto stop = chrono::high_resolution_clock::now();       //end timer
        auto duration = chrono::duration_cast<chrono::nanoseconds>(stop - start);    //take time

        print_list();
        allSorts[option - 1][i - 1][j] = duration.count();
        sortTimeTotal[option - 1][i - 1] += allSorts[option - 1][i - 1][j];
      }
    }
  }

  for(int j = 0; j < 3; j++){
    for(int i = 0; i < 12; i++){
      sortTimeAvg[j][i] = sortTimeTotal[j][i] / dataSets;
    }
  }
  for(int j = 0; j < 3; j++){
    string sortingMethod;
    if(j == 0){
      sortingMethod = "Quick Sort 1";
    }
    else if(j == 1){
      sortingMethod = "Quick Sort 2";
    }
    else{
      sortingMethod = "Merge Sort";
    }
    cout << sortingMethod << " Timings: " << endl
     << "1. First Name (A - Z): " << sortTimeAvg[j][0] << "ns" << endl
     << "2. First Name (Z - A): " << sortTimeAvg[j][1] << "ns" << endl
     << "3. Last Name (A - Z): " << sortTimeAvg[j][2] << "ns" << endl
     << "4. Last Name (Z - A): " << sortTimeAvg[j][3] << "ns" << endl
     << "5. ID (Ascending): " << sortTimeAvg[j][4] << "ns" << endl
     << "6. ID (Decending): " << sortTimeAvg[j][5] << "ns" << endl
     << "7. Phone Number (Ascending): " << sortTimeAvg[j][6] << "ns" << endl
     << "8. Phone Number (Decending): " << sortTimeAvg[j][7] << "ns" << endl
     << "9. Seat Number (Ascending): " << sortTimeAvg[j][8] << "ns" << endl
     << "10. Seat Number (Decending): " << sortTimeAvg[j][9] << "ns" << endl
     << "11. Reservation Number (Ascending): " << sortTimeAvg[j][10] << "ns" << endl
     << "12. Reservation Number (Decending): " << sortTimeAvg[j][11] << "ns" << endl;
  }

  exit(0);

  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 12; j++){
      delete [] allSorts[i][j];
    }
    delete [] allSorts[i];
  }
  delete [] allSorts;
}

void airlines::selectSortingMethod(int sortByNum, int methodNum){
  map<int, function<bool(const node*, const node*)>> comparisons = {
      {1, [](const node* a, const node* b){ return a->fname < b->fname; }},
      {2, [](const node* a, const node* b){ return a->fname > b->fname; }},
      {3, [](const node* a, const node* b){ return a->lname < b->lname; }},
      {4, [](const node* a, const node* b){ return a->lname > b->lname; }},
      {5, [](const node* a, const node* b){ return a->ID < b->ID; }},
      {6, [](const node* a, const node* b){ return a->ID > b->ID; }},
      {7, [](const node* a, const node* b){ return a->phone_num < b->phone_num; }},
      {8, [](const node* a, const node* b){ return a->phone_num > b->phone_num; }},
      {9, [](const node* a, const node* b){ return a->seat_num < b->seat_num; }},
      {10, [](const node* a, const node* b){ return a->seat_num > b->seat_num; }},
      {11, [](const node* a, const node* b){ return a->reserve_num < b->reserve_num; }},
      {12, [](const node* a, const node* b){ return a->reserve_num > b->reserve_num; }}
  };

  if(comparisons.count(sortByNum)){
    if(methodNum == 1){
      quickSort1<node>(comparisons[sortByNum]);
    }
    else if(methodNum == 2){
      quickSort2<node>(comparisons[sortByNum]);
    }
    else if(methodNum == 3){
      mergeSort(&start, comparisons[sortByNum]);
    }
  }
}

void airlines::clearLinkedList(){
  if(start == nullptr){
    return;
  }
  node* tTemp;
  node* tTemp2;
  tTemp = start;
  while(tTemp != nullptr){
    tTemp2 = tTemp->next;
    delete tTemp;
    tTemp = tTemp2;
  }
  start = nullptr;
  trackSize = 0;
}

template <typename T>
void airlines::quickSort1(function<bool(const T*, const T*)> comp){    //normal quicksort
  temp = start;
  node** arr = new node*[trackSize];                                  //fixed size Node* array
  for(int i = 0; temp != NULL; temp = temp->next, i++){               //copy linkedlist into ^
    arr[i] = temp;
  }

  quickSort1Helper(arr, trackSize, comp);

  start = arr[0];                                                    //copy arr to linkedlist
  temp = start;
  for (int i = 1; i < trackSize; ++i) {
      temp->next = arr[i];
      temp = temp->next;
  }
  temp->next = NULL;

  delete [] arr;
}

template <typename T>
void airlines::quickSort1Helper(T** arr, int s, function<bool(const T*, const T*)> comp){
  if(s > 1){
    T* pivot = arr[s / 2];
    int leftTrack = 0;
    int rightTrack = s - 1;

    while(leftTrack <= rightTrack){
      while(comp(arr[leftTrack], pivot)){
        leftTrack++;
      }
      while(comp(pivot, arr[rightTrack])){
        rightTrack--;
      }
      if(leftTrack <= rightTrack){
        T* temp = arr[leftTrack];
        arr[leftTrack] = arr[rightTrack];
        arr[rightTrack] = temp;
        leftTrack++;
        rightTrack--;
      }
    }
    if(rightTrack > 0){
      quickSort1Helper(arr, rightTrack + 1, comp);
    }
    if(leftTrack < s){
      quickSort1Helper(arr + leftTrack, s - leftTrack, comp);
    }
  }
}

template <typename T>
void airlines::insertionSort(T** arr, int s, function<bool(const T*, const T*)> comp){
  for(int i = 1; i < s; i++){
    T* temp = arr[i];
    int j = i - 1;
    while(j >= 0 && comp(temp, arr[j])){
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = temp;
  }
}

template <typename T>
void airlines::quickSort2(function<bool(const T*, const T*)> comp){    //quicksort with insertionsort
  temp = start;
  node** arr = new node*[trackSize];                                  //fixed size Node* array
  for(int i = 0; temp != NULL; temp = temp->next, i++){               //copy linkedlist into ^
    arr[i] = temp;
  }

  quickSort2Helper(arr, trackSize, comp);

  start = arr[0];                                                    //copy arr to linkedlist
  temp = start;
  for (int i = 1; i < trackSize; ++i) {
      temp->next = arr[i];
      temp = temp->next;
  }
  temp->next = NULL;

  delete [] arr;
}

template <typename T>
void airlines::quickSort2Helper(T** arr, int s, function<bool(const T*, const T*)> comp){
  if(s <= 15){
    insertionSort(arr, s, comp);
  }
  else if(s > 1){
    T* pivot = arr[s / 2];
    int leftTrack = 0;
    int rightTrack = s - 1;

    while(leftTrack <= rightTrack){
      while(comp(arr[leftTrack], pivot)){
        leftTrack++;
      }
      while(comp(pivot, arr[rightTrack])){
        rightTrack--;
      }
      if(leftTrack <= rightTrack){
        T* temp = arr[leftTrack];
        arr[leftTrack] = arr[rightTrack];
        arr[rightTrack] = temp;
        leftTrack++;
        rightTrack--;
      }
    }
    if(rightTrack > 0){
      quickSort2Helper(arr, rightTrack + 1, comp);
    }
    if(leftTrack < s){
      quickSort2Helper(arr + leftTrack, s - leftTrack, comp);
    }
  }
}

template <typename T>
void airlines::mergeSort(T** start, function<bool(const T*, const T*)> comp){
  node* a;
  node* b;
  node* head = *start;

  if(start == NULL || head->next == NULL){
    return;
  }

  split(head, &a, &b);

  mergeSort(&a, comp);
  mergeSort(&b, comp);

  *start = merge(a, b, comp);
}

template <typename T>
void airlines::split(T* source, T** firstStart, T** secondStart){
    node* fast;
    node* slow;
    slow = source;
    fast = source->next;

    while(fast != NULL){
      fast = fast->next;
      if(fast != NULL){
        slow = slow->next;
        fast = fast->next;
      }
    }
    *firstStart = source;
    *secondStart = slow->next;
    slow->next = NULL;
}

template <typename T>
T* airlines::merge(T* first, T* second, function<bool(const T*, const T*)> comp){
  T* result = NULL;

  if(first == NULL){
    return (second);
  }
  else if(second == NULL){
    return (first);
  }

  if(comp(first, second)){
    result = first;
    result->next = merge(first->next, second, comp);
  }
  else{
    result = second;
    result->next = merge(first, second->next, comp);
  }
  return (result);
}