/* Name: Robert Cimarelli
Date: 11.11.2017
Section: 6
Assignment: (Assignment#6)
Due Date: 11.13.2017
About this project: this program takes in a password from the user and must meet the requirements depicted below
Assumptions: password must be six characters or abovev

All work below was performed by (Your Name) */

#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
#include <iomanip>
using namespace std;
int main()
{
	
	char password[80]; //password 
	int length; //length of pass
	int i; //loop
	char password2[80]; //re entry
	bool isUpper; //true if it is upper
	bool isLower; //true if it is lower
	bool isDigit; //true is if it a digit
	bool Compare; //true if they are the same 

	do {
		isUpper = false; //declare booleans in loop to check
		isLower = false;
		isDigit = false;
		Compare = false;


		cout << "Enter your password: " << endl;
		cin >> password;

		length = strlen(password); //length of password
		if (length < 6) //less than min length
		{
			cout << "Password needs to have 6 or more characters " << endl; //restriction 
		}
		else if (length == 0) //if length is zero
		{
			cout << "Enter your password: " << endl;
		}
		for (i = 0; i < length; i++)
		{
			if (isupper(password[i]))  //if it is uppercase
				isUpper = true;
			
			if (islower(password[i]))  //if it is lowercase
				isLower = true;	
			if (isdigit(password[i])) //if it is a digit
				isDigit = true;
		}
		if (!isUpper) //checks uppercase
			cout << "Password needs to contain at least one uppercase letter " << endl;
		if (!isLower) //checks lowercase
			cout << "Password needs to contain at least one lowercase letter " << endl;
		if (!isDigit) //checks digit
			cout << "Password needs to contain at least one digit " << endl;
		if (isUpper == true && isLower == true && isDigit == true) //if all are true, pass is valid
		{
			cout << "Now re-enter your password for verification: " << endl;
			cin >> password2;

			if (strcmp(password, password2) == 0) //compare to see if they are the same
			{
				Compare = true;
				cout << "You have now entered a valid password " << endl;
			}
			else
				cout << "Password does not match.  Start over " << endl;
		}
	} while (length = 0 || length < 6 ||  !isLower || !isUpper || !isDigit || !Compare); 
	
	







	return 0;
}