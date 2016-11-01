/*
//================THEATER SEATING PROGRAM================//
	PRG/410: C++ Programming I

	Learning Team 'A'
		- Wezley Singleton
		- Raphael Fonseca
		- Joseph Freese
		- Christopher Jackson
//=======================================================//
*/


#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <iomanip>
#include <vector>
using namespace std;

//--------------FUNCTION PROTOTYPES--------------//
void preMenu_seatingChart(char seatingChart[12][10]);
void displayAvailability(char seatingChart[12][10], int&, int&);
void ShowMenu();	
void SeatPrices(double& price, double& price2, double& price3);
void PurchaseTicket(char seatingChart[12][10]);
void updatedSeatDisplay();
void continueAsk();


//----GLOBAL VARIABLE INTIALIZATION AND DECLARATION----//
char seatingChart[12][10];	// array for the main seating chart that shows available and reserved seats
double currentSales[30];	// array for keeping track of chosen seats as well as their price for calculation
double price = 12.50;		// stores the price for the first four rows
double price2 = 18.00;		// stores the price for the next four rows
double price3 = 24.00;		// stores the price for the final four rows

int seatsReserved = 0;		// keeps track of number of reserved seats throughout program
int seatsAvailable = 0;		// keeps track of number of available seats throughout program

// main function displays a welcome messages and calls the functions to continue the program
int main()
{
	std::cout << "Welcome to our movie theater! Here you can view seats available and purchase tickets for available seats!\n" << endl;

	preMenu_seatingChart(seatingChart);
	displayAvailability(seatingChart, seatsAvailable, seatsReserved);
	ShowMenu();

	system("PAUSE");

    return 0;
}

//========================CLASSES AND FUNCTIONS========================//
//=====================================================================//

/****************************
*	Function Name:  preMenu_seatingChart
*	Variables:
*	Return Type:  void
*	Purpose:  Creates a random seating chart and displays it for the user.
*****************************/
void preMenu_seatingChart(char seatingChart[12][10]) 
{
	//random seed - guarantees a unique seating chart each time the program runs
	srand(time(NULL));

	//coin-flip algorithm for 2-D array
	for (int i = 0, k = 1; i < 12; i++) 
	{
		for (int j = 0; j < 10; ++j, ++k) 
		{
			//random coin flip to determine status of seat
			int randomValue = rand() % 2;	// stores a random value of 0 or 1
			switch (randomValue) 
			{
				//case 0 - '#' SEAT AVAILABLE
				case 0:
					seatingChart[i][j] = '#';
					break;
				//case 1 - '*' SEAT RESERVED
				case 1:
					seatingChart[i][j] = '*';
					break;
			}
		}
	}

	//The rest of the code below displays the Seating Chart
	std::cout << "       C1    C2    C3    C4    C5    C6    C7    C8    C9    C10\n" << endl;
	for (int i = 0; i < 12; i++) 
	{
		if (i + 1 >= 10)
		{
			std::cout << "R" << i + 1 << ": ";
		}

		else 
			std::cout << "R" << i + 1 << ":  ";

		for (int j = 0; j < 10; j++) 
		{
			cout << "   " << seatingChart[i][j] << "  ";
		}

		cout << "\n\n\n";
	}

	cout << "* = Seat Reserved, # = Seat Available\n\n";
}

/****************************
*	Function Name:  displayAvailability
*	Return Type:  void
*	Purpose:  Pre-Menu: Displays the number of seats reserved and available to the user
*****************************/
void displayAvailability(char seatingChart[12][10], int& seatsAvailable, int& seatsReserved) {
	for (int i = 0; i < 12; i++) 
	{
		for (int j = 0; j < 10; j++) 
		{
			switch (seatingChart[i][j]) 
			{
				//Counts the # of available seats
				case ('#'):
					seatsAvailable++;
					break;
				
				//Counts the # of reserved seats
				case ('*'):
					seatsReserved++;
					break;
			}
		}
	}

	//Display availability results
	cout << "There are " << seatsAvailable << " seats available for purchase." << endl;
	cout << "There are " << seatsReserved << " seats reserved." << endl;
}

/****************************
*	Function Name:  updatedSeatDisplay
*	Return Type:  void
*	Purpose:  Displays an updated seating chart
*****************************/
void updatedSeatDisplay()
{
	system("CLS");
	std::cout << "       C1    C2    C3    C4    C5    C6    C7    C8    C9    C10\n" << endl;
	for (int i = 0; i < 12; i++)
	{
		if (i + 1 >= 10)
		{
			std::cout << "R" << i + 1 << ": ";
		}

		else
			std::cout << "R" << i + 1 << ":  ";

		for (int j = 0; j < 10; j++) 
		{
			cout << "   " << seatingChart[i][j] << "  ";
		}

		cout << "\n\n\n";
	}

	cout << "* = Seat Reserved, # = Seat Available\n\n";

	cout << "There are " << seatsAvailable << " seats available for purchase." << endl;
	cout << "There are " << seatsReserved << " seats reserved." << endl;
	continueAsk();
}

/****************************
*	Function Name:  ShowMenu
*	Return Type:  void
*	Purpose:  ShowMenu function will allow the user to purchase one or more tickets.
*****************************/
void ShowMenu()
{
	system("CLS");
	int choice = 0;	// stores the users menu choice integer

	do  // loops through the main menu until user decides to exit
	{
		cout << " \tMAIN MENU\n";
		cout << " 1. View Seat Prices.\n";
		cout << " 2. Purchase a Ticket.\n";
		cout << " 3. View Available Seats.\n";
		cout << " 4. Quit the program.\n";
		cout << "_____________________\n\n";
		cout << "Please enter your choice: ";
		std::cin >> choice;
		cout << endl << endl;

		switch (choice)
		{
			case 1:	// display seat prices
			{
				SeatPrices(price, price2, price3);
				break;
			}
			case 2:	// call PurchaseTicket function to choose and purchase seats
			{
				PurchaseTicket(seatingChart);
				break;
			}
			case 3:	// display most recent seating chart
			{
				updatedSeatDisplay();
				break;
			}
			case 4:	// exit menu
			{
				break;
			}
		}
	} while (choice != 4);
}

/****************************
*	Function Name:  SeatPrices
*	Return Type:  void
*	Purpose:  Displays the prices for wanted row/seat
*****************************/
void SeatPrices(double& price, double& price2, double& price3)
{
	system("CLS");
	printf("The price for each ticket in Row 1-4 is $%.2f\n", price3);
	printf("The price for each ticket in Row 5-8 is $%.2f\n", price2);
	printf("The price for each ticket in Row 9-12 is $%.2f\n", price);
	continueAsk();
}

/****************************
*	Function Name:  PurchaseTicket
*	Return Type:  void
*	Purpose:  Allows user to select the actual ticket that is needed
*****************************/
void PurchaseTicket(char seatingChart[12][10])
{
	int rowChoice = 0;	// stores the row choice entered by the user
	int colChoice = 0;	// stores the column choice entered by the user
	
	int purchases = 0;	// stores the actual number of tickets the user wants to purchase
	char choice;	// stores char value 'y' or 'n' to determine if user wants to buy more tickets
	char chosenSeat;	// stores the current symbol from the seatingChart array to see if seat is taken or available

	system("CLS");

	do  // keep looping through purchase ticket menu until user says 'n' for no
	{
		int currentIndex = 0;	// stores the index to be used for the currentSales array
		double currentTotal = 0;	// keeps track of the total price for all currently chosen tickets
		int currentTicket = 0;	// stores the current ticket number being purchased
		cout << "How many tickets would you like to purchase? (Purchase Limit is 10 at a time)\n";
		std::cin >> purchases;

	while (purchases < 0 || purchases > 10)	// check if ticket quantity input is valid
	{
		cout << "You can only purchase tickets in the quantity range of 1 and 10.\nPlease enter how many tickets you would like to purchase \n (Purchase Limit is 10 at a time) \n";
		cin >> purchases;
	}
	
	
		for (int i = 0; i < purchases; i++)	// for loop based on how many tickets user wants to purchase
		{
			do  // keep looping until user has chosen all of their seats
			{
				cout << "Pick a Row: ";
				std::cin >> rowChoice;

				while (rowChoice < 0 || rowChoice > 12)	// check if row choice is within range
				{
					cout << "Please pick a row that is between the numbers 1 and 12. Thank you. \n";
					cin >> rowChoice;
				}

				cout << "Pick a Column: ";
				std::cin >> colChoice;

				while (colChoice < 0 || colChoice > 10)	// check if column choice is within range
				{
					cout << "Please pick a column that is between the numbers 1 and 10. Thank you. \n";
					cin >> colChoice;
				}

				chosenSeat = seatingChart[rowChoice - 1][colChoice - 1];

				if (chosenSeat == '*')	// condition checks if seat is sold, if not then it updates the seating chart and stores current prices in currentSales array
				{
					std::cout << "the seat you chose is SOLD. Please choose another row and column for your seat!" << endl;
				}
				else
				{
					currentSales[currentIndex++] = rowChoice;
					currentSales[currentIndex++] = colChoice;
					if ((rowChoice > 0) && (rowChoice < 5))
					{
						currentSales[currentIndex++] = price3;
					}

					else if ((rowChoice > 4) && (rowChoice < 9))
					{
						currentSales[currentIndex++] = price2;
					}

					else if ((rowChoice > 8) && (rowChoice < 13))
					{
						currentSales[currentIndex++] = price;
					}
				}
				
			} while (chosenSeat == '*');
		}

		for (int i = 0; i < 30; i++)	// Display all ticket choices along with the total
		{
			if (currentSales[i] == 0)
				break;
			currentTicket++;
			std::cout << "ticket choice " << currentTicket << " in row " << currentSales[i++]; 
			std::cout << " column " << currentSales[i++];
			std::cout << " costs $";
			printf("%.2f\n", currentSales[i]);
			currentTotal += currentSales[i];
		}

		printf("current total: $%.2f\n", currentTotal);

		char finalAnswer;	// stores the users final answer for purchasing tickets
		std::cout << "Are you sure you want to purchase the tickets shown for the current total? (Yes (y) or No (n))" << endl;
		std::cin >> finalAnswer;
		if (finalAnswer == 'y')	// allow user to decide if they actually want to buy the tickets
		{
			for (int i = 0; i < 30; i++)
			{
				if (currentSales[i] == 0)
					break;
				int theRow = currentSales[i];
				int theColumn = currentSales[i + 1];
				seatingChart[theRow-1][theColumn-1] = '*';
				i += 2;

			}
			
			seatsAvailable -= currentTicket;
			seatsReserved += currentTicket;
		}

		else if (finalAnswer == 'n')
		{
			std::cout << "You decided not to buy the tickets! Returning to Main Menu" << endl;
			break;
		}

		cout << "\n\nWould you like to buy more tickets? (Y or N): ";
		std::cin >> choice;

	} while (choice == 'Y' || choice == 'y');
}

//==========================================================//
//	FUNCTION NAME:											//
//		continueAsk											//
//															//
//	CLASS (ACCESS LEVEL):									//
//		None											    //
//															//
//	INPUTS:													//
//		none												//
//															//
//	OUTPUTS:												//
//		none												//
//															//
//	DESCRIPTION:											//
//		This function asks the user if they would like to	//
//		return to the main menu for further actions.		//
//==========================================================//
void continueAsk() {
	char continueChoice;
	cout << "\nWould you like to return to the main menu? (Y/N)" << endl;
	cin >> continueChoice;
	switch (continueChoice) {
	case ('Y'):
		system("CLS");
		ShowMenu();
		break;
	case 'N':
		system("CLS");
		cout << "Are you sure you want to exit the program? (Y/N)" << endl;
		cin >> continueChoice;
		switch (continueChoice) {
		case 'Y':
			cout << "Exiting program..." << endl;
			exit(0);
		case 'N':
			ShowMenu();
		default:
			cout << "\nERROR: INVALID SELECTION\nPlease make a valid selection." << endl;
			continueAsk();
		}
	default:
		cout << "\nERROR: INVALID SELECTION\nPlease make a valid selection." << endl;
		continueAsk();
	}
}