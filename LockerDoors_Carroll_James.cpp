/*
Author: James Carroll
Date: 9/7/2021
Purpose of Program: This program takes user input on number of passes by a locker and number of lockers passed, and toggles ever ith locker being opened or closed for i number of passes.
*/

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
	//User enters how many times the lockers will be passed by.
	cout << "Enter the number of passes that will be made" << endl;
	int passes = 0;
	cin >> passes;

	//User enters the number of lockers that will be passed by.
	cout << "Enter the number of lockers" << endl;
	int lockers = 0;
	cin >> lockers;

	//Array holding the boolean status of the locker doors, sized to the number of lockers being passeed, false for closed, true for open, all lockers begin closed.
	bool doors[lockers] = {false};

	//Loops for the number of passes
	for (int i = 0; i < passes; i++)
	{
		//Loops for the number of lockers being passed
		for (int j = 0; j < lockers; j++)
		{
			//If the locker number can be evenly divided by which pass is currently happening, the lockers door is toggled. (Ex: locker 4 on pass 2 would be toggled because 4 % 2 = 0)
			if ((j + 1) % (i + 1) == 0)
			{
				if (doors[j] == false)
					doors[j] = true;
				else if (doors[j] == true)
					doors[j] = false;
			}
		}
	}

	//Loops that prints the door status of each locker.
	for (int i = 0; i < lockers; i++)
	{
		if (doors[i] == true)
			cout << "Door " << i + 1 << " is open" << endl;
		else if (doors[i] == false)
			cout << "Door " << i + 1 << " is closed" << endl;
	}
}