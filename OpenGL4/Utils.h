#ifndef DEF_UTILS
#define DEF_UTILS
#include <string>
#include <sstream>


std::string operator+(std::string a, int b);

std::string operator+(int a, std::string b);

std::string operator+(std::string a, double b);
std::string operator+(double b, std::string a);
void debug(double);
int round(double);
int round(float);

class Utils
{
public:
	static std::string concat(std::string base, int nbr);
	static std::string concat(std::string base, double nbr);

	static std::string getString(int nbr);
	Utils(void);
	~Utils(void);
};

#endif