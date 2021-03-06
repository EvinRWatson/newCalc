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