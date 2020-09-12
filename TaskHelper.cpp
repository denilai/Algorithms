#include "TaskHelper.h"

Author::Author(std::string work, std::string n, std::string gr, std::string var) : work(work), name(n), group(gr), variant(var) {}


std::string Author::introduce() {
	std::string intro = "Work: " + this->work + "\nName: " + name + "\nGroup: " + group + "\nVariant: " + variant + "\n\n";
	return intro;
}

bool TaskSolver::task1(double large, double small, Point& p) {
	bool pred1 = p.x * p.x + p.y * p.y <= large * large;
	bool pred2 = pow(p.x, 2) + pow(p.y - small, 2) > small * small;
	bool pred3 = pow(p.x, 2) + pow(p.y + small, 2) > small * small;
	if (pred1 && pred2 && pred3)
		return 1;
	else return 0;
}
