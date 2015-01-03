#include "Utils.h"
#include <string>
#include <sstream>
#include <Windows.h>


Utils::Utils(void)
{
}


Utils::~Utils(void)
{
}

std::string operator+(std::string a, int b) {
	return Utils::concat(a, b);
}

std::string operator+(int a, std::string b) {
	std::string temp = std::string("") + a + b;
	return temp;
}

std::string operator+(std::string a, double b) {
	return Utils::concat(a, b);
}
std::string operator+(double b, std::string a) {
	std::string temp = std::string("") + b + a;
	return temp;
}
void debug(double d) {
	OutputDebugString((std::string("\n") + d).c_str());
}
int round(double d) {
	if(d < 0) {
		return floor(d-0.5);
	}
	return floor(d+0.5);
}
int round(float f) {
	return round((double)f);
}

std::string Utils::concat(std::string base,int nbr) {
	std::stringstream number;
	number << nbr;
	std::string numberInString = number.str();

	std::string finalString = base + numberInString;
	return finalString;
}

std::string Utils::concat(std::string base,double nbr) {
	std::stringstream number;
	number << nbr;
	std::string numberInString = number.str();

	std::string finalString = base + numberInString;
	return finalString;
}

std::string Utils::getString(int nbr) {
	std::stringstream number;
	number << nbr;
	return number.str();
}