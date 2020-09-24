#include "SupportStuff.h"
#include "MatrixMaster.h"
#include "TaskSolverFunc.h"
#include "CheckData.h"
#include "EmailMaster.h"
#include <windows.h>

using namespace std;

int main(){
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	bool answer = true;
	
	Author myself = Author( "Labrotary works", "Denisov Kirill", "IVBO-02-19", "12" );
	cout<< myself.introduce();
	/*
	Matrix matr = { {1,2,4},{5,7,2},{5,9,9},{12,5,9} };
	MatrixMaster::showArray(matr);
	MatrixMaster::deleteColumn(matr, 2);
	MatrixMaster::showArray(matr);
	*/
	do {
		std::function<bool()> execTask = myself.choiseTask();
		answer = execTask();
		
		//cout << "\nRepeat the program? (y/n) > ";
		//answer = CheckData<void>::getYesNo();
	} while (answer);


	return 0;
}