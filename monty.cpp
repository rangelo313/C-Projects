/* Name: Robert Cimarelli
Date: 10/15/2017
Section: 6
Assignment: Assignment#4
Due Date: 10/20/2017
About this project: Monty Hall- This project will prompt the user to choose a door (1-3) based on randomization and display whether they won the game or not.  
Assumptions: Assuming that the user enters a number between 1 and 3 and that the program will generate a winning door and a losing door

All work below was performed by Robert Cimarelli */

#include <iostream> //libraries
#include <cstdlib>
#include <iomanip>
#include <ctime>
using namespace std;

//function prototypes
int gen(); //door generator 
void stats(double, double); //statistics
void printDoors(); //doors printed

//build another function

int main()
{
	srand((unsigned int)time(0)); //seed the random number generator
	cout << "Welcome to the Monty Hall Let's Make a Deal Simulator!" << endl; //welcome
	//declare variables here
	int entry, random, choice, losing, winnerDoor, attempt, otherDoor; //doors and user entries
	double win = 0; //counts the wins
	double loss = 0; //counts the losses
	int games = 0; //games in total
	
	do {														//menu loops
	cout << "Choose one of the Following: " << endl;
	
	cout << " 1 - Play the Game\n ";
	cout << "2 - See Stats\n ";
	cout << "3 - Reset Stats\n ";
	cout << "4 - Quit\n";
	cin >> entry;

		switch (entry) //based on the user's entry.
		{
		case 1:
			cout << "Pick a door, 1, 2, or 3! " << endl;
			printDoors(); //function call
			cin >> choice;
			cout << "You chose door #" << choice << "!" << endl;
			cout << "I'll now open a door for you randomly that you didn't choose!" << endl;
			winnerDoor = gen(); //function call to generate a winning door


			//winning is picked 
			//choice is picked 

			losing = gen(); //losing door is picked, this loop makes it so that it cannot equal choice and winnerdoor
			while (losing == choice || losing == winnerDoor) {
				losing = gen();
			}

			//losing is picked

			cout << "Opening door #" << losing << " and it's a GOAT!" << endl; //losing door is displayed
			cout << "Now I'll be a kind host and give you the chance to switch your door " << endl; //opportunity to switch

			otherDoor = gen(); //another random door is generated, losing door cannot be the same and choice can't either
			while (otherDoor == losing || otherDoor == choice) {
				otherDoor = gen();
			}

			cout << "Now would you like door #" << choice << " or door #" << otherDoor << endl;
			cin >> attempt;
			cout << "Opening door #" << attempt << ".........." << endl;

			if (attempt == winnerDoor)
			{
				cout << "Congratulations! You won a new car! " << endl;
				win++; //record wins
				games++; //records games played
			}
			else
			{
				cout << "baaaaaaaaaaaaa....it's a GOAT!!!! You LOSE!" << endl; 
				loss++; //record losses
				games++; //games played
			}
			break;
		case 2:
			if (games == 0)
			{
				cout << "No stats to show, zero games played " << endl; //zero games played
			}
			if (games > 0)
			{
				cout << "Results after " << games << " games: " << endl; //calls function to display stats
				stats(win, loss);
			}

			break;
		case 3:
			games = 0;
			cout << "..... Statistics reset" << endl; //sets games equal to zero
			break;
		case 4:
			cout << "Goodbye! " << endl; //exits loop
			break;
		default:
			cout << "Invalid entry, please try again. "; //prompts user to enter a valid entry
			break;
		}
	} while (entry < 4 && entry >= 1); //entry must be less than 4 and greater than or equal to one for loop to run




	return 0;
}


void printDoors() //prints door options
{
	cout << "---------    ---------    ---------- \n";
	cout << "|       |    |  ____ |    |  _____ | \n";
	cout << "|   |   |    |     | |    |      | | \n";
	cout << "|   |   |    |  ___| |    |   ___| | \n";
	cout << "|   |   |    | |     |    |      | | \n";
	cout << "|   |   |    | |____ |    |  ____| | \n";
	cout << "---------    ---------    ---------- \n";

	return;
}

int gen() //door generator 
{
	int num;
	num = (rand() % 3 + 1); //between 1 and 3 

	return  num;
}
void stats(double wins, double losses) //shows user's stats
{
	double games; //another way of getting the total # of games
	double winratio, lossratio;
	games = wins + losses; //adds wins to losses
	winratio = (wins / games) * 100;
	lossratio = (losses / games) * 100;
	cout << "Your total number of wins is: " << wins << "\t"; //displays wins
	cout << "\tYour total number of losses is: " << losses << endl; //displays losses
	cout << fixed << showpoint << setprecision(1);
	cout << "Win %: " << winratio << "\t "; //displays percentage of wins
	cout << "\t\t\tLoss %: " << lossratio << "\t" << endl; //displays percent of losses
	

}
