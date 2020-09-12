#include <iostream>
#include "TaskHelper.h"

using namespace std;

void task_1() {
	bool answer = true;
	do {
		double large = 0, small = 0, x = 0, y = 0;

		cout << "Get radius of cirsles" << endl;
		cout << "The larger circle> ";
		large = CheckData<double>::getPosDigit();
		cout << "The smaller circle> ";
		small = CheckData<double>::getPosDigit();
		cout << "Get x coordinate> ";
		x = CheckData<double>::getDigit();
		cout << "Get y coordinate> ";
		y = CheckData<double>::getDigit();
		Point point = { x,y };

		if (TaskSolver::task1(large, small, point))
			cout << "The point IS INCLUDED in the area" << endl;
		else
			cout << "The point IS NOT INCLUDED in the area" << endl;

		cout << "Repeat the program? (y/n) > ";
		answer = CheckData<void>::getYesNo();
	} while (answer);
}

int main(){
	Author myself = Author( "Labrotary work #1", "Denisov Kirill", "IVBO-02-19", "12" );
	cout<< myself.introduce();
	task_1();

	// task 12

	
	
	


	return 0;
}