#include "SupportStuff.h"
#include "CheckData.h"
#include "TaskSolverFunc.h"


Author::Author(std::string work, std::string n, std::string gr, std::string var) : work(work), name(n), group(gr), variant(var) {}


std::string Author::introduce() {
	std::string intro = "Work: " + this->work + "\nName: " + name + "\nGroup: " + group + "\nVariant: " + variant + "\n\n";
	return intro;
}

std::function<void()> Author::choiseTask()
{
	int x = 0;
	std::cout << "Chose the task:" << std::endl;
	std::cout << " -- Task I - Problem with including a point in the area\n";
	std::cout << " -- Task II - Delete column with maximal element in 2D matrix\n";
	std::cout << "Print '1' or '2'> ";
	int first = 1, last = 2;
	x = CheckData<int>::getDigit();
	while (!(first <= x && x <= last)) {
		std::cout << "Chose variant in range [" << first << "," << last << "]!\n> ";
		x = CheckData<int>::getDigit();
	}
	switch (x) {
	case 1:
		return solveTask1;
	case 2:
		return solveTask2;
	default:
		std::cout << "Invalid input\n";
	}
	return std::function<void()>();
}

bool GeomMaster::areaChecker(double large, double small, Point& p) {
	bool pred1 = p.x * p.x + p.y * p.y <= large * large;
	bool pred2 = pow(p.x, 2) + pow(p.y - small, 2) > small * small;
	bool pred3 = pow(p.x, 2) + pow(p.y + small, 2) > small * small;
	if (pred1 && pred2 && pred3)
		return 1;
	else return 0;
}

