#include <iostream>
#include <math.h>
#include "functions.h"
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
			std::cin >> wt;
			std::cout << "Input Quantity (Feet for DetCord): ";
			std::cin >> qty;
			std::cout << "Input REF: ";
			std::cin >> ref;

			//User Input - Accounting for grain explosive variation
			std::cout << "\nIs this a grain explosive? 'y' or 'n': ";
			do
			{
				std::cin >> isGrain;
				if (isGrain != "y" && isGrain != "n")
					std::cout << "\tError: '" << isGrain << "' is not a known input. Input 'y' or 'n': ";
			} while (isGrain != "y" && isGrain != "n");

			//Calculating and outputting NEW
			NEW = getNEW(wt, qty, ref, isGrain);
			std::cout << "\n\tNEW:\t" << NEW;

			//Adding current NEW to total NEW
			totalNEW = totalNEW + NEW;

			//User Input - Adding another charge element
			std::cout << "\n\nAdd another element? 'y' or 'n': ";
			std::cin >> response;

			//Input Error Check
			while (response != "y" && response != "n")
			{
				std::cout << "\tError: '" << response << "' is not a known input. Input 'y' or 'n': ";
				std::cin >> response;
			}

			//Ending of loop - display total NEW
			if (response == "n")
			{
				isComplete = true;
				std::cout << "\n\nTotal NEW:\t\t" << totalNEW << std::endl;
			}
		}
		//Calculating Standoff using total NEW
		double root = cbrt(totalNEW);
		std::cout << "Standoff:\t\tWith Cover: " << ((int)(root * 10) + 1)
			<< "\n\t\t\tWithout Cover: " << ((int)(root * 15) + 1)
			<< "\n\t\t\tOverpressure: " << ((int)(root * 20) + 1)
			<< "\n\t\t\tLight Frag: " << ((int)(root * 300) + 1)
			<< "\n\t\t\tHeavy Frag: " << ((int)(root * 500) + 1) << "\n" << std::endl;

		//Ending program
		std::cout << "End Program - to restart exit and reopen the program" << std::endl;
		return 0;
	}