#include "SupportStuff.h"
#include "MatrixMaster.h"
#include "TaskSolverFunc.h"
#include "CheckData.h"

using namespace std;

int main(){
	bool answer = true;
	do{
		Author myself = Author( "Labrotary works", "Denisov Kirill", "IVBO-02-19", "12" );
		cout<< myself.introduce();
		/*
		Matrix matr = { {1,2,4},{5,7,2},{5,9,9},{12,5,9} };
		MatrixMaster::showArray(matr);
		MatrixMaster::deleteColumn(matr, 2);
		MatrixMaster::showArray(matr);
		*/

		std::function<void()> execTask = myself.choiseTask();
		execTask();
		

		// task 12

		cout << "Repeat the program? (y/n) > ";
		answer = CheckData<void>::getYesNo();
	} while (answer);


	return 0;
}