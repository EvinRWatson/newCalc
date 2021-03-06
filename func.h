#pragma once
#include <iostream>
#include <math.h>
#include <string>

double getNEW(double wt, double qty, double ref, std::string isGrain)
{
	double NEW = (wt * qty * ref);
	if (isGrain == "y")
		NEW = (NEW / 7000);
	return NEW;
}

double getDouble()
{
	bool isDouble = false;
	std::string input;
	double output = NULL;
	while (isDouble == false)
	{
		try
		{
			std::cin >> input;
			output = std::stod(input);
			isDouble = true;
		}
		catch (std::exception&)
		{
			std::cout << "Error: Invalid Input" << std::endl;
		}
	}
	return output;
}

std::string getYesNo()
{
	std::string response;
	std::cin >>  response;
	while (response != "y" && response != "n")
	{
		std::cout << "\tError: '" << response << "' is not a known input. Input 'y' or 'n': ";
		std::cin >> response;
	}
	return response;
}


void printNEW(double NEW)
{
	std::cout << "\n\nTotal NEW:\t\t" << NEW << std::endl;
}

void printStandoff(double NEW)
{
	double root = cbrt(NEW);
	std::cout << "Standoff:\t\tWith Cover: " << ((int)(root * 10) + 1) << " ft"
				<< "\n\t\t\tWithout Cover: " << ((int)(root * 15) + 1) << " ft"
				<< "\n\t\t\tOverpressure: " << ((int)(root * 20) + 1) << " ft"
				<< "\n\t\t\tLight Frag: " << ((int)(root * 300) + 1) << " ft"
				<< "\n\t\t\tHeavy Frag: " << ((int)(root * 500) + 1) << " ft" << "\n" << std::endl;
}