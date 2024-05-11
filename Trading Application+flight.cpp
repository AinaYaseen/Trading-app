#include <iostream>
#include <fstream>
#include <vector>
#include <iostream>
#include <stdio.h>  
#include <ctime>  
#include<iomanip>  
#include <string>  
#include <limits>
using namespace std;

static string userid;

string toLower(string str);
bool isLeap(int year);
bool isValidDate(int d, int m, int y);

time_t t = time(NULL); // Get current time in seconds since the epoch
tm* timePtr = localtime(&t); // Convert time to local time structure
// Define constants for valid date ranges based on the current year and month
const int MAX_VALID_YR = timePtr->tm_year + 1901;   // Maximum valid year (next year)
const int MIN_VALID_YR = timePtr->tm_year + 1900;   // Minimum valid year (current year)
const int MIN_VALID_MNTH = timePtr->tm_mon + 1;    // Minimum valid month (current month)
const int MAX_VALID_MNTH = timePtr->tm_mon + 2;    // Maximum valid month (next month)

void login();
void registration();
void forgot();
class flightDetails
{
public:
// Array storing flight serial numbers
int flightSerial[15] = { 101, 102, 103, 122, 123, 124, 131, 132, 133, 241, 242, 243, 501, 502, 503 };
// Array storing corresponding flight prices
int price[16] = { 12000, 10000, 15000, 11000, 14000, 10000, 12000, 13500, 9000, 12500, 14000, 12000, 16000, 16500, 13500 };
private:
int selectFlight;
int perPersonPrice;
   
    // Functions for displaying available flights and handling passenger choices for each destination
public:
void lahore()
{
cout << "\n Flights available for Lahore:" <<endl;
cout << "\n  " << flightSerial[0] << "-Flight (Time: 5:00pm) " << price[0] << "/- per person";
cout << "\n  " << flightSerial[1] << "-Flight (Time: 12:00am) " << price[1] << "/- per person";
cout << "\n  " << flightSerial[2] << "-Flight (Time: 8:00pm) " << price[2] << "/- per person";

cout << "\nChoose your Flight: ";
cin >> selectFlight;

for (int i = 0; i < 3; i++)
{
if (selectFlight == flightSerial[i])
{
setPerPersonPrice(price[i]);
break;
}
}
}

public:
void karachi()
{
cout << "\n You have choosen Karachi.";
cout << "\n FLIGHTS AVAILABLE FOR KARACHI:" <<endl;
cout << "\n  " << flightSerial[3] << "-Flight (Time: 3:00pm) " << price[3] << "/- per person";
cout << "\n  " << flightSerial[4] << "-Flight (Time: 7:00pm) " << price[4] << "/- per person";
cout << "\n  " << flightSerial[5] << "-Flight (Time: 2:00am) " << price[5] << "/- per person";

cout << "\n\nChoose your Flight: ";
cin >> selectFlight;

for (int i = 3; i <= 5; i++)
{
if (selectFlight == flightSerial[i])
{
setPerPersonPrice(price[i]);
break;
}
}
}
public:
void islamabad()
{
cout << "\n You have choosen Islamabad." <<endl;
cout << "\n FLIGHTS AVAILABLE FOR ISLAMABAD:";
cout << "\n  " << flightSerial[6] << "-Flight (Time: 4:00pm) " << price[6] << "/- per person";
cout << "\n  " << flightSerial[7] << "-Flight (Time: 9:00pm) " << price[7] << "/- per person";
cout << "\n  " << flightSerial[8] << "-Flight (Time: 2:00am) " << price[8] << "/- per person";

cout << "\n\nChoose your Fight: ";
cin >> selectFlight;

for (int i = 6; i <= 8; i++)
{
if (selectFlight == flightSerial[i])
{
setPerPersonPrice(price[i]);
break;
}
}
}

public:
void peshawar()
{
cout << "\n You have choosen Peshawar.";
cout << "\n FLIGHTS AVAILABLE FOR PESHAWAR:" <<endl;
cout << "\n  " << flightSerial[9] << "-Flight (Time: 5:00pm) " << price[9] << "/- per person";
cout << "\n  " << flightSerial[10] << "-Flight (ime: 6:00pm) " << price[10] << "/- per person";
cout << "\n  " << flightSerial[11] << "-Flight (Time: 1:00am) " << price[11] << "/- per person";
cout << "\n\nChoose your Flight: ";
cin >> selectFlight;

for (int i = 9; i <= 11; i++)
{
if (selectFlight == flightSerial[i])
{
setPerPersonPrice(price[i]);
break;
}
}
}
public:
void quetta()
{
cout << "\n FLIGHTS AVAILABLE FOR QUETTA:" <<endl;
cout << "\n  " << flightSerial[12] << "-Flight (Time: 4:00am) " << price[12] << "/- per person";
cout << "\n  " << flightSerial[13] << "-Flight (Time: 3:00pm) " << price[13] << "/- per person";
cout << "\n  " << flightSerial[14] << "-Flight (Time: 6:00am) " << price[14] << "/- per person";

cout << "\n\nChoose your flight: ";
cin >> selectFlight;

for (int i = 12; i <= 14; i++)
{
if (selectFlight == flightSerial[i])
{
setPerPersonPrice(price[i]);
break;
}
}
}
// Set Price of per person
void setPerPersonPrice(int price)
{
perPersonPrice = price;
}
// Get Price of per person
int getperPersonPrice()
{
return perPersonPrice;
}
// Get selected flight by passenger
int getSelectFlight()
{
return selectFlight;
}
};
// Class Node saving user information
class Node
{
public:
string name = "", date = "", departureCity = "", destinationCity = "", gender = "", CNIC = "";
int age = 0, bookingCode = 0, ticketSerialNo = 0;
float fare = 0;
Node* next = NULL;
};
// Class for the main process of booking tickets
class bookingProcedureOfTicket
{
private:
    // Node pointers for linked list implementation (likely for storing passenger information)
Node* head = NULL;
Node* current = NULL;
Node* front = NULL;
Node* rear = NULL;
int Bcode = 0;
int Bcode2 = 0;
flightDetails call;
public:
// Variables for passenger details, fare calculations, and booking count
int Age = 0;
int members = 0;
int count = 0;
float sum = 0;
float fare = 0;
float discount = 0;
float discountFare = 0;
float totalFare = 0;
string cnic = "";
int numberOfBooking = 0;
public:
// Function to check if a given city is valid
bool isValidCity(string city)
{
if (toLower(city) == "lahore" || toLower(city) == "islamabad" ||
toLower(city) == "karachi" || toLower(city) == "quetta" || toLower(city) == "peshawar")
{
return true;
}
return false;
}
// This method will contain all the passenger info
void inputPassengersInfo()
{
// 1. Generate booking codes
        // - Create a unique booking code using a random number
Bcode = rand();

Bcode2 = 8971 + Bcode;

string departureCity = "", destinationCity = "", date = "";
// for city selection or correction
int change = 1;
        // Main loop to ensure distinct and valid departure and destination cities
do {
if (change == 1 || change == 2)
{
do
{
cout << "\n -DEPARTURE-" <<endl;
cout << "\n-> Our flights are only available from: \nKarachi || Lahore || Peshawar || Islamabad || Quetta.\n";
cout << "\nEnter your departure city from above mentioned cities: ";
cin >> departureCity;
} while (!isValidCity(departureCity));
}
           
if (change == 1 || change == 3)
{
do
{
cout << "\n -DESTINATION- " <<endl;
cout << "\n-> Our flights are only available to: \nKarachi || Lahore || Peshawar || Islamabad || Quetta.\n";
cout << "\nEnter your destination city from above mentioned cities: ";
cin >> destinationCity;
} while (!isValidCity(destinationCity));

}
            // Handle same city input
if (toLower(departureCity) == toLower(destinationCity))
{
cout << "\nDeparture and Destination cities cannot be same." << endl;
cout << "\nTo change both Enter 1.\nTo change Deaprture Enter 2.\nTo Change Destnation Enter 3.\n" << endl;
cout << "Select: ";
cin >> change;
}
} while (toLower(departureCity) == toLower(destinationCity));

// Date Input
int d = 0, m = 0, y = 0;
bool validDate = false;

do
{
cout << "\nEnter Date: ";
cin >> d;
cout << "Enter Month: ";
cin >> m;
cout << "Enter Year: ";
cin >> y;
            // Validate the entered date using the isValidDate function
validDate = isValidDate(d, m, y);
            // If the date is not valid, display an error message and return from the function
if (!validDate)
{
cout << "\nPlease enter a valid date, month and year. You can book seats upto 30 days in advance.\n";
return;
}
	
          ofstream outfile("flighthistory.txt", ios::app);
    outfile<<userid <<" "<<departureCity<<" "<<destinationCity<<" "<<d<<"/"<<m<<"/"<<y<<" "<<"Flight booked"<<endl;
}
// Continue looping until a valid date is entered
while (!validDate);
// Format the date string
date = to_string(d) + "/" + to_string(m) + "/" + to_string(y);
// Gather passenger information
cout << "\nFor how many people you want to Book Tickets: ";
cin >> members;
cout << endl;

numberOfBooking = count + members;
for (int i = 1; i <= members; i++)
{
// Create a new node for each passenger
Node* passenger_newnode = new Node();
cout << "Enter Passenger Name: ";
getline(cin>>ws,passenger_newnode->name);
cout << "Enter Your Age: ";
cin >> passenger_newnode->age;
passenger_newnode->date = date;
cout << "Enter Gender: ";
cin >> passenger_newnode->gender;
// CNIC validation
cout << "Enter CNIC (without dashes): ";
cin >> cnic;
if (cnic.length() != 13)
{
cout << "Enter correct CNIC number (without dashes): ";
cin >> cnic;
}
cnic = cnic.insert(5, "-");
cnic = cnic.insert(13, "-");
passenger_newnode->CNIC = cnic;
// Assign ticket serial number
cout << "Your Ticket Serial No. is: S-" << i;
passenger_newnode->ticketSerialNo = i;
cout << "\n----------------------------------------------------\n" << endl;
// Store passenger information
passenger_newnode->departureCity = departureCity;
passenger_newnode->destinationCity = destinationCity;
passenger_newnode->bookingCode = Bcode2;
count++; // incrementing number of bookings
// Link passenger node to appropriate data structure
if (numberOfBooking > 2)
{
// Use a queue-like structure for efficiency with more bookings
if (front == NULL)
{
// Create the first node in the queue
front = passenger_newnode;
rear = passenger_newnode;
}

else
{
rear->next = passenger_newnode;
rear = passenger_newnode;
}
}
else
{
if (head == NULL)
{
head = passenger_newnode;
passenger_newnode->next = NULL;
}

else
{
current = head;
// Find the last node in the list
while (current->next != NULL)
{
current = current->next;
}
// Append the new node to the end of the list
current->next = passenger_newnode;
}
}

}
// Dispatch based on destination city
if (destinationCity == "Lahore" || destinationCity == "lahore" || destinationCity =="LAHORE")
{
call.lahore();
}
else if (destinationCity == "Islamabad" || destinationCity == "islamabad" || destinationCity =="ISLAMABAD")
{
call.islamabad();
}
else if (destinationCity == "Karachi" || destinationCity == "karachi" || destinationCity =="KARACHI")
{
call.karachi();
}
else if (destinationCity == "Quetta" || destinationCity == "quetta" || destinationCity =="QUETTA")
{
call.quetta();
}
else if (destinationCity == "Peshawar" || destinationCity == "peshawar" || destinationCity =="PESHAWAR")
{
call.peshawar();
}
else
{
cout << "Wrong destinationCity\n";
}
// Check available seats and provide booking status
if (numberOfBooking > 2)
{
// Seats are full, add passenger to waiting list
cout << "\nYour Booking Code is:  " << Bcode2;
cout << "\nNo more seats are availbale, you are added in the waiting list" << endl;
}
else
{
// Seats are available, proceed to price calculation
cout << "\nYour Booking Code is: " << Bcode2;
cout << "\nTo proceed and view Total Price, Press 3.";
}
// Clear the input buffer to prevent unintended input carryover
cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
// Function to display information about passengers on the waiting list
void showWaitingList()
{
string search_string = userid;
    ifstream file("flighthistory.txt");
    string line;
    bool isfound = false;
    cout<<"\t---------------- Purchase History ----------------"<<endl<<endl;
    while (getline(file, line)) {
        if (line.find(search_string) != string::npos) {
            cout <<"\t"<< line << endl;
         isfound = true; 
		}
    }    
    if(isfound != true){
    	cout<<"No  History found "<<endl;
	}
    file.close();
}
// Function to calculate the total fare for a booking, applying age-based discounts
void calculatePrice()
{
current = head;
bool found = false;
fare = call.getperPersonPrice();
totalFare = sum = 0;

int bcode;
        // Prompt the user for their booking code
cout << "Enter your Booking Code: ";
cin >> bcode;

if (current == NULL)
cout << "\nNo Price to Display";
        // Check if the booking list is empty
while (current != NULL)
{
if (bcode == current->bookingCode)
{
// Found the matching booking
                // Apply discounts based on age
if (current->age > 0 && current->age <= 6)
{
discount = call.getperPersonPrice() * 0.5; // 50% discount
discountFare = call.getperPersonPrice() - discount;
current->fare = discountFare;
sum += discountFare; // Total fare
}
else if (current->age > 6 && current->age <= 12)
{
discount = call.getperPersonPrice() * 0.3; // 30% discount
discountFare = call.getperPersonPrice() - discount;
current->fare = discountFare;
sum += discountFare; // Total fare
}
else if (current->age >= 60)
{
discount = call.getperPersonPrice() * 0.2; // 20% discount
discountFare = call.getperPersonPrice() - discount;
current->fare = discountFare;
sum += discountFare; // Total fare
}
else
{
fare = call.getperPersonPrice();
current->fare = fare;
sum += fare;
}

found = true;
}
current = current->next;
}
// Display the total fare or an error message
if (found == false)
{
cout << "Enter correct Booking Code" << endl;
}
else
{
// Calculate the final total fare
totalFare = sum;
cout << "Your Total Fare is: " << totalFare;
}
}
void viewInfo() {
string search_string = userid;
    ifstream file("flighthistory.txt");
    string line;
    bool isfound = false;
    cout<<"\t---------------- Purchase History ----------------"<<endl<<endl;
    while (getline(file, line)) {
        if (line.find(search_string) != string::npos) {
            cout <<"\t"<< line << endl;
         isfound = true; 
		}
    }    
    if(isfound != true){
    	cout<<"No Purcahase History found "<<endl;
	}
    file.close();
}
void modifyTicket()
{
int bcode;
int serial;
int found = -1;

cout << "Enter your Booking Code: ";
cin >> bcode;

cout << "\nEnter Serial Number to edit: S-";
cin >> serial;

current = head;
while (current != NULL)
{
if (bcode == current->bookingCode && serial == current->ticketSerialNo)
{
// Get updated passenger information
cout << "Enter Passenger Name: ";
getline(cin >> ws,current->name);

cout << "Enter Your Age: ";
cin >> current->age;

cout << "Enter Date: ";
cin >> current->date;

cout << "Enter Gender: ";
cin >> current->gender;

found = 0;
cout << endl;
break; //Exit the loop
}
current = current->next;
}

if (found == -1)
{
cout << "Booking Not Found!" << endl;
}
cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
// Function to handle payments and confirm bookings
void confirmPayment()
{
current = head;

int bcode, userInput;
string cnic;
bool found = false;

cout << "Enter your Booking Code: ";
cin >> bcode;

cout << "\nEnter CNIC number of Booking of 1st Person(with dashes): ";
cin >> cnic;

if (current == NULL)
{
cout << "\nThere is No Booking aganist entered Booking Code" << endl;
}

while (current != NULL)
{
if (bcode == current->bookingCode && cnic == current->CNIC)
{
found = true;
break;
}
current = current->next;
}
         // If the booking is found, proceed with payment
if (found)
{

cout << "\nYour Total Fare is: " << totalFare << endl;

cout << "\nPay fare amount to Tonfirm Ticket: ";
cin >> userInput;

if (userInput == totalFare)
{
cout << "\nYOUR BOOKING IS CONFIRMED, ENJOY YOUR TRIP!!!";
}
else
{
cout << "\nPlease Pay the Required Amount" << endl;

cout << "\nPay Fare Amount to Confirm Ticket: ";
cin >> userInput;

if (userInput == totalFare)
{
cout << "\nYOUR BOOKING IS CONFIRMED, ENJOY YOUR TRIP!!!";
}

else
{
cout << "\nYOUR BOOKING IS NOT CONFIRMED CANCELLED, BOOK AGAIN." << endl;
}
}
}
else
{
cout << "\nBookings Not Found, Book your Ticket First." << endl;
}
}
// Function to delete passenger information
void DeletingPassengerInfo()
{
current = head;
int Bcode;
//char decide;
bool found = false;

cout << "Enter your Booking Code to Cancel Booking: ";
cin >> Bcode;

if (head == NULL)
{
cout << "No Booking to Cancel." << endl;
}
else
{
if (current->next == NULL)            // If only one Node in Linked List this condition will execute
{
if (Bcode == current->bookingCode)
{
head = NULL;
delete(current);
found = true;
}
}
else
{
// If there are more than one node and first node is deleting
if (current == head && Bcode == current->bookingCode)
{
Node* temp = current;
current = current->next;
delete(temp);
found = true;
}
else  // If deleting node from end or middle
{
Node* previous = current;
while (current != NULL)
{
if (Bcode == current->bookingCode)
{
previous->next = current->next;
delete (current);
found = true;
}

current = current->next;
}
}
}

if (found == false)
{
cout << "Booking Not Found!" << endl;
}
else {
cout << "\nBOOKING IS CANCELLED, SUCCESSFULLY!" << endl;
}
}
}
};


class Account {
private:
    int dogecoin, balance;
    int bitcoin;
    int deposit, withdraw;
    int total_equity = 100;
    int predict;
    int dogecoin_value;
    int bitcoin_value;
    int crypto_invest;
    int crypto_return;
    vector<pair<string, int>> transactions;

public:
    // ... (Assuming you have other member variables and methods here)



    bool Deposit(int money) {
        deposit += money;
        balance += money;
        transactions.push_back({"Deposit:", money});
       
          ofstream outfile("history.txt", ios::app);
    outfile<<userid <<" "<<deposit<<" "<<"Amount Deposited"<<endl;
	    return true;

    }

    void Get_account_information() {
        cout << "Money Details:\n";
        cout << "Bank Balance:" << balance << endl;
        cout << "Dogecoin:" << dogecoin << endl;
        cout << "Bitcoin:" << bitcoin << endl;
     
     
    }

    bool Withdraw(int money) {
        if (money > balance) {
            return false;
        }
        withdraw += money;
        balance -= money;
        transactions.push_back({"Withdraw:", money});
        ofstream outfile("history.txt", ios::app);
    outfile<<userid <<" "<<money<<" "<<"Amount Withdarwal"<<endl;

        return true;
    }

    bool buy_crypto() {
        int option;
        cout << "Want to purchase dogecoin press 1 else "
             "for bitcoin press 2\n";
        cin >> option;

        // Checking equity
        if (total_equity != 0) {
            srand(time(NULL));
            int luck = rand();

            // Adjust the condition for a higher success rate
            if (luck % 2 == 0) {
                if (option == 1) {
                    dogecoin += 1;
                    balance -= dogecoin_value;
                    crypto_invest += (dogecoin)*dogecoin_value;
                      ofstream outfile("history.txt", ios::app);
    outfile<<userid <<" "<<dogecoin<<" "<<"Got Dogecoin"<<endl;

                } else {
                    bitcoin += 1;
                    balance -= bitcoin_value;
                    crypto_invest += bitcoin_value;
                      ofstream outfile("history.txt", ios::app);
    outfile<<userid <<" "<<bitcoin<<" "<<"Got bitcoin"<<endl;

                }
            } else {
                return false;
            }
        } else {
            return false;
        }
        return true;
    }

    bool sell_crypto() {
        int option;
        cout << "Want to sell dogecoin press 1 else for bitcoin press 2\n";
        cin >> option;

        if (option == 2) {
            if (bitcoin == 0)
                return false;
            crypto_return += bitcoin_value;
            balance += bitcoin_value;
            transactions.push_back({"Bitcoin Sold:", bitcoin_value});
            bitcoin -= 1;
                        ofstream outfile("history.txt", ios::app);
    	outfile<<userid <<" "<<bitcoin<<" "<<"bitcoin sold"<<endl;

        } else {
            if (dogecoin == 0)
                return false;
            crypto_return += dogecoin_value;
            balance += dogecoin_value;
            transactions.push_back({"Dogecoin Sold:", dogecoin_value});
            dogecoin -= 1;
              ofstream outfile("history.txt", ios::app);
    	outfile<<userid <<" "<<dogecoin<<" "<<"Dogecoin sold"<<endl;

        }

        return true;
    }

    void History() {
string search_string = userid;
    ifstream file("history.txt");
    string line;
    bool isfound = false;
    cout<<"\t---------------- Purchase History ----------------"<<endl<<endl;
    while (getline(file, line)) {
        if (line.find(search_string) != string::npos) {
            cout <<"\t"<< line << endl;
         isfound = true; 
		}
    }    
    if(isfound != true){
    	cout<<" History found "<<endl;
	}
    file.close();
    }
	
    Account() {
        crypto_invest = 0;
        crypto_return = 0;
        total_equity = 100;

        balance = 50000;
        dogecoin = 0;
        bitcoin = 0;
        withdraw = 0;
        deposit = 0;
        dogecoin_value = 100;
        bitcoin_value = 500;
    }
};
// Menu which will select our desirable query
class Menu
{
int choice = 0;
bookingProcedureOfTicket call;

public:
// Method to display the menu and handle user choices
void showMenu(){
   do{
            cout << "\n---------------------------------------------------------------" << endl;
cout << "_______________*PAKISTAN INTERNATIONAL AIRLINES*_______________ ";
cout << "\n";
cout << "\n---------------------------------------------------------------" << endl;

cout<<"\n\t__________________________________________________"<<endl;
cout<<"\n\t |\t Press 1: Services for the Cities \t|"<<endl;
       cout<<"\t |\t Press 2: Booking                 \t|"<<endl;
       cout<<"\t |\t Press 3: Price                   \t|"<<endl;
       cout<<"\t |\t Press 4: View Ticket details     \t|"<<endl;
       cout<<"\t |\t Press 5: Modify Ticket details   \t|" <<endl;
       cout<<"\t |\t Press 6: Payment confirmation    \t|" <<endl;
       cout<<"\t |\t Press 7: Cancel your booking     \t|"<<endl;
       cout<<"\t |\t Press 8: Show waiting List       \t|" <<endl;
          cout<<"\t |\t Press 0 to Exit!!!               \t|"<<endl;
cout<<"\n\t__________________________________________________"<<endl;
cout << " \nENTER YOUR CHOICE: ";
cin >> choice;

switch (choice)
{
case 1:
cout << "\n----------------------------------" << endl;
cout << " -Karachi \n";
cout << " -Peshawar \n";
cout << " -Islamabad \n";
cout << " -Quetta \n";
cout << " -Lahore \n";
cout << "----------------------------------" << endl;

break;
case 2:
cout << endl;
cout << "----------------------------------" << endl;
cout << "\n    *BOOK PIA FLIGHT TICKETS* \n"<< endl;
cout << "----------------------------------" << endl;
call.inputPassengersInfo();
break;
case 3:
cout << endl;
call.calculatePrice();
break;
case 4:
cout << endl;
call.viewInfo();
break;
case 5:
cout << endl;
call.modifyTicket();
break;
case 6:
cout << endl;
call.confirmPayment();
break;
case 7:
cout << endl;
call.DeletingPassengerInfo();
break;
case 8:
cout << endl;
call.showWaitingList();
}

} while (choice != 0);
}
};

void login();
void registration();
void forgot();

int main() {
char choice1;
    int c;
    cout << "\t\t\t________________________________________________________________\n\n\n";
    cout << "\t\t\t             WELCOME TO LOGIN PAGE           \n\n\n";
    cout << "\t\t\t____________       MAIN MENU     _____________\n\n";
    cout << "\t\t\t                                                   ";
    cout << "\n\t|PRESS 1 TO LOGIN                              |" << endl;
    cout << "\t|PRESS 2 TO REGISTER                           |" << endl;
    cout << "\t|PRESS 3 TO IF YOU FORGOT PASSWORD             |" << endl;
    cout << "\t|PRESS 4 TO EXIT                               |" << endl;
    cout << "\n\t\t\t PLEASE ENTER YOUR CHOICE:";
    cin >> c;

    cout << endl;

    switch (c) {
    case 1:
        login();
        break;

    case 2:
        registration();
        break;

    case 3:
        forgot();
        break;

    case 4:
        cout << "\t\t\t THANK YOU!   \n\n";
        break;

    default:
        system("cls");
        cout << "\t\t\t PLEASE SELECT FROM THE OPTIONS GIVEN ABOVE \n" << endl;
        main();
    }
    cout<<"-------------------------------WHAT SYSTEM DO YOU WANT?------------------------------"<<endl;
cout<<"-------------------------------CRYPTOGRAPHY OR AIRLINE RESERVATION------------------------------"<<endl;
cout<<"ENTER C FOR CRYPTOGRAPHY:";
cout<<"ENTER F FOR AIRLINE RESERVATION:";
cin>>choice1;

   Account person;
switch (choice1) {
        case 'C':
       
    int amount, choice;
    bool check;

    while (1) {
        cout << " "
             << "******************************************"
             << "***************************** \n";

        cout << endl;
        cout << "Press 1 if want to have your Account Info "
             << endl;
        cout << "Press 2 if want to Deposit your money "
             << endl;
        cout << "Press 3 if want to withdraw your money "
             << endl;
        cout << "Press 4 if want to know your history "
             << endl;
        cout << "Press 5 if want to know your Buy Crypto "
             << endl;
        cout << "Press 6 if want to know your Sell Crypto "
             << endl;
        cout << "Else press any invalid key for exit \n"
             << endl;

        cout << " "
             << "******************************************"
             << "***************************** \n";

        cin >> choice;
        int ans;

        switch (choice) {
        case 1:
            person.Get_account_information();
            break;

        case 2:
            cout << "Enter amount to deposit : ";
            cin >> amount;
            ans = person.Deposit(amount);
            if (ans)
                cout << "Successfully deposited money"
                     << endl;
            else
                cout << "Failed\n";

            break;

        case 3:
            cout << "Enter amount to withdraw : ";
            cin >> amount;
            ans = person.Withdraw(amount);

            if (ans)
                cout << "Successfully withdrawn Amount"
                     << endl;
            else
                cout << "Not Enough Balance\n";

            break;

        case 4:
            person.History();
            break;

        case 5:
            ans = person.buy_crypto();
            if (ans)
                cout << "Successful Transaction" << endl;
            else
                cout << "Better Luck next time\n";
            break;

        case 6:
            ans = person.sell_crypto();
            if (ans)
                cout << "Successful Transaction" << endl;
            else
                cout << "Not Enough Cryptocoins\n";
            break;

        default:
            exit(0);
        }
    }
            break;
       

        case 'F':
       
{

              // Create an object of the Menu class to manage the user interface
Menu call;
call.showMenu();  // Call the showMenu() method to start the menu-driven interaction

       
            break;
    }

 default:
            cout << "Invalid choice" << endl;
            break;
}
           

    return 0;
}

void login() {
    int count = 0;
    string  password, id, pass;
    system("cls");
    cout << "\t\t\t  PLEASE ENTER THE USERNAME AND PASSWORD : " << endl;
    cout << "\t\t\t  USERNAME : ";
    cin >> userid;
    cout << "\t\t\t  PASSWORD : ";
    cin >> password;

    ifstream input("records.txt");

    while (input >> id >> pass) {
        if (userid == id && pass == password) {
            count = 1;
            system("cls");
        }
    }
    input.close();

    if (count == 1) {
        cout << userid << "\n YOUR LOGIN IS SUCCESSFULL \n THANKS FOR LOGGING IN !\n";
       // main();
    } else {
        cout << "\n     LOGIN  UNSUCCESSFUL \n  PLEASE CHECK YOUR USERNAME AND PASSWORD\n";
        main();
    }
 
}

void registration() {
    string  rpassword;
    system("cls");
    cout << "\t\t\t ENTER THE USERNAME : ";
    cin >> userid;
    cout << "\t\t\t ENTER THE PASSWORD : ";
    cin >> rpassword;

    ofstream f1("records.txt", ios::app);
    f1 << userid << ' ' << rpassword << endl;

    system("cls");

    cout << "\n\t\t\t REGISTRATION IS SUCCESSFUL! \n";
    login();
}

void forgot() {
    int option;
    system("cls");
    cout << "\t\t\t YOU FORGOT THE PASSWORD? NO WORRIES \n";
    cout << "PRESS 1 TO SEARCH YOUR ID BY USENAME : " << endl;
    cout << "PRESS 2 TO GO BACK TO MAIN MENU : " << endl;
    cout << "\t\t\t ENTER YOUR CHOICE : ";
    cin >> option;
    switch (option) {
    case 1: {
        int count = 0;
        string suserid, sid, spass;
        cout << "\n\t\t\t ENTER THE USERNAME WHICH YOU REMEMBERED : ";
        cin >> suserid;

        ifstream f2("records.txt");
        while (f2 >> sid >> spass) {
            if (sid == suserid) {
                count = 1;
            }
        }
        f2.close();
        if (count == 1) {
            cout << "\n\n YOUR ACCOUNT IS FOUND! \n";
            cout << "\n\n YOUR PASSWORD IS :" << spass;
            main();
        } else {
            cout << "\n\t SORRY! YOUR ACCOUNT IS NOT FOUND! \n";
            main();
        }
        break;
    }
    case 2: {
        main();
    }
    default:
        cout << "\t\t\t WRONG CHOICE! PLEASE TRY AGAIN " << endl;
        forgot();
   
}




}



// Function to convert a string to lowercase
string toLower(string str)
{
// Create a copy of the input string
string lowerStr = str;
// Iterate through each character in the string
for (size_t i = 0; i < str.length(); ++i) {
// Convert the character to lowercase using the tolower function
lowerStr[i] = tolower((unsigned char)str[i]);
}
return lowerStr;
}
// Returns true if
// given year is valid.
bool isLeap(int year)
{
// Return true if year
// is a multiple of 4 and
// not multiple of 100.
// OR year is multiple of 400.
return (((year % 4 == 0) &&
(year % 100 != 0)) ||
(year % 400 == 0));
}
// Returns true if given
// year is valid or not.
bool isValidDate(int d, int m, int y)
{
// If year, month and day
// are not in given range
if (y > MAX_VALID_YR ||
y < MIN_VALID_YR)
return false;
if (m < MIN_VALID_MNTH || m > MAX_VALID_MNTH)
return false;
if (d < 1 || d > 31)
return false;

// Handle February month
// with leap year
if (m == 2)
{
if (isLeap(y))
return (d <= 29);
else
return (d <= 28);
}

// Months of April, June,
// Sept and Nov must have
// number of days less than
// or equal to 30.
if (m == 4 || m == 6 ||
m == 9 || m == 11)
return (d <= 30);

return true;
}