#include <iostream>
#include <math.h>
#include "func.h"
	int main()
	{
		//Name
		std::cout << "NEW & Stand Off Calculator\n";
		std::cout << "This program calculates the NEW and Standoff for any number of concurrent elements in a charge. In order"
			"to calculate you will need the quantity of explosive you are using, The weight of the explosive\n"
			"in the given package, the Relative Explosive Factor, as well as if the explosive is in grain form.\n";

		//Variable Declaration
		double wt, qty, ref, NEW, totalNEW = 0;
		std::string name, response = "y";
		std::string isGrain = "n";
		bool isComplete = false;

		//Main Loop
		while (isComplete == false)
		{
			//User Input - Main calculating variables
			std::cout << "\nInput Weight (Lbs) or grain density: ";
			wt = getDouble();
			std::cout << "Input Quantity: ";
			qty = getDouble();
			std::cout << "Input REF: ";
			ref = getDouble();

			//User Input - Accounting for grain explosive variation
			std::cout << "\nIs this a grain explosive? 'y' or 'n': ";
			isGrain = getYesNo();

			//Calculating and outputting NEW
			NEW = getNEW(wt, qty, ref, isGrain);
			std::cout << "\n\tNEW:\t" << NEW;

			//Adding current NEW to total NEW
			totalNEW = totalNEW + NEW;

			//User Input - Adding another charge element
			std::cout << "\n\nAdd another element? 'y' or 'n': ";
			response = getYesNo();

			//Ending of loop - display total NEW
			if (response == "n")
			{
				isComplete = true;
				printNEW(totalNEW);
			}
		}
		//Calculating Standoff using total NEW
		printStandoff(totalNEW);

		//Ending program
		std::cout << "End Program - to restart exit and reopen the program" << std::endl;
		return 0;
	}