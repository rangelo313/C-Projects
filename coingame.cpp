/* Name: Robert Cimarelli
Date: 9/20/17
Section: 0006
Assignment: Assignment#2 part 2
Due Date: 9/26/17
About this project: This program will ask the user to play a game where they set up an amount of money, and have to match that amount of money using the types of coins provided.
Assumptions: Assumes user will choose to play the game and enter positive integer values for the amount of each coin and positive values for the amount selected.

All work below was performed by Robert Cimarelli */


#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	char answer; //user entry to playing the game
	double amount; //user entry to amount decided
	double halfdollar, quarter, dime, nickel, penny; //coins used
	double total; //total value of coins
	
	cout << fixed << showpoint << setprecision(2); //2 decimal places rounded

	cout << "Welcome to the coin game! " << endl; //welcome the user

	cout << "Would you like to play? (y or n) --> "; //ask the user to play
	cin >> answer; 

	if (answer == 'y') //if the user selects y, then the following commands will follow
	{
		cout << "What amount of $ would you like to match? --> "; //asks user for amount of money they will match
		cin >> amount;
		cout << "Okay! you need to match the amount of $" << amount << endl; //their amount they chose is displayed
		//enter the amounts or quantities of each type of coin. ex: 
		cout << "Enter the number of:\n "; //user must enter number of each coin
		cout << "\tHalf Dollars: ";
		cin >> halfdollar;
		cout << "\tQuarters: ";
		cin >> quarter;
		cout << "\tDimes: ";
		cin >> dime;
		cout << "\tNickels: ";
		cin >> nickel;
		cout << "\tPennies:";
		cin >> penny;
		//variable total is set to hold the amount of half dollars, quarters, dimes, nickels, and pennies the user entered
		total = (halfdollar *0.50) + (quarter *.25) + (dime *.10) + (nickel *.05) + (penny * .01);
		if (halfdollar < 0 || quarter < 0 || dime < 0 || nickel < 0 || penny < 0) //accounts for negative numbers a user may enter
			cout << "You can't enter a negative amount of coins. Aborting game.\n " << endl; //abort program
		else if (amount == total) //won the game
			cout << "You WIN!\n " << "Thanks for Playing!\n "; //congratulate
		else if (amount > total) //lost the game by total - amount
			cout << "You lost the game by: $" << amount - total << "\nThanks for playing!\n " << endl;
		else if (amount < total)
			cout << "You lost the game by: $" << total - amount << "\nThanks for playing!\n " << endl;
	}
	else if (answer == 'n') //if the user doesn't want to play
		cout << "Guess you're scared! Come back when you're ready to play! " << endl;
	else //user enters invalid entry
		cout << "Invalid entry, aborting program. " << endl;

		return 0;
	}