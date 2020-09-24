#include "SupportStuff.h"
#include "CheckData.h"
#include "TaskSolverFunc.h"
#include "MyBase.h"

Author::Author(std::string work, std::string n, std::string gr, std::string var) : work(work), name(n), group(gr), variant(var) {}


std::string Author::introduce() {
	std::string intro = "Work: " + this->work + "\nName: " + name + "\nGroup: " + group + "\nVariant: " + variant + "\n\n";
	return intro;
}

std::function<bool()> Author::choiseTask()
{
	int x = 0;
	std::cout << "\n\nChose the task:" << std::endl;
	std::cout << " -- Task I   - Problem with including a point in the area\n";
	std::cout << " -- Task II  - Delete column with maximal element in 2D matrix\n";
	std::cout << " -- Task III - Check email adress status\n";
	std::cout << " -- Task IV  - Operation with file (profile form)\n";
	std::cout << " -- Press '5' to EXIT THE PROGRAM\n";
	std::cout << "Print '1', '2', '3', '4' or '5'> ";
	x = CheckData<int>::getDigit(1, 5);
	switch (x) {
	case 1:
		return solveTask1;
	case 2:
		return solveTask2;
	case 3:
		return solveTask3;
	case 4:
		return solveTask4;
	case 5:
		return exitFunc;
	}
}

bool GeomMaster::areaChecker(double large, double small, Point& p) {
	bool pred1 = p.x * p.x + p.y * p.y <= large * large;
	bool pred2 = pow(p.x, 2) + pow(p.y - small, 2) > small * small;
	bool pred3 = pow(p.x, 2) + pow(p.y + small, 2) > small * small;
	if (pred1 && pred2 && pred3)
		return 1;
	else return 0;
}



