#ifndef SUPPORT_STUFF
#define SUPPORT_STUFF

#include <string>
#include <iostream>
#include <functional>

struct Author {
private:
	std::string work;
	std::string name;
	std::string group;
	std::string variant;
public:
	Author(std::string work, std::string n, std::string gr, std::string var);
	// Представление
	std::string introduce();

	 std::function<bool()> choiseTask();
};

struct Point {
	double x;
	double y;
};

class GeomMaster {
public:
	static bool areaChecker(double, double, Point&);
};

#endif
