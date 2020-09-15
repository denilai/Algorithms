#include "TaskSolverFunc.h"
#include "CheckData.h"

void solveTask1() {
	double large = 0, small = 0, x = 0, y = 0;

	std::cout << "Get radius of cirsles" << std::endl;
	std::cout << "The larger circle> ";
	large = CheckData<double>::getPosDigit();
	std::cout << "The smaller circle> ";
	small = CheckData<double>::getPosDigit();
	std::cout << "Get x coordinate> ";
	x = CheckData<double>::getDigit();
	std::cout << "Get y coordinate> ";
	y = CheckData<double>::getDigit();
	Point point = { x,y };

	if (GeomMaster::areaChecker(large, small, point))
		std::cout << "The point IS INCLUDED in the area" << std::endl;
	else
		std::cout << "The point IS NOT INCLUDED in the area" << std::endl;
}

void solveTask2() {
	Matrix array = MatrixMaster::createMatrix();
	MatrixMaster::showArray(array);
	int maxElem = MatrixMaster::findMaxElem(array);
	std::pair<int, int> ans = MatrixMaster::findElem(array, maxElem);
	while (ans != std::make_pair(-1, -1)) {
		MatrixMaster::deleteColumn(array, ans.second);
		MatrixMaster::showArray(array);
		ans = MatrixMaster::findElem(array, maxElem);
	}
}


void solveTask3() {

}