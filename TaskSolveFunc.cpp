#include "TaskSolverFunc.h"
#include "CheckData.h"
#include "EmailMaster.h"
#include "MyBase.h"


bool solveTask1() {
	double large = 0, small = 0, x = 0, y = 0;
	bool answer = false;
	do {
		std::cout << "\n\tTASK #1\n";

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
		std::cout << "Try again ? (y or n) > ";
		answer = CheckData<int>::getYesNo();
	} while (answer);
	return true;
}

bool solveTask2() {
	std::cout << "\n\tTASK #2\n";

	int n = 0, m = 0;
	std::cout << "Get count of rows in the matrix > ";
	n = CheckData<int>::getPosDigit();
	std::cout << "Get count of columns in the matrix > ";
	m = CheckData<int>::getPosDigit();

	MatrixMaster array(n, m);
	int maxElem = array.findMaxElem();
	std::cout << "\n--- Find maximum element = " << maxElem << " ---\n";
	std::pair<int, int> ans = array.findElem(maxElem);
	while (ans != std::make_pair(-1, -1)) {
		std::cout << "\n--- Delete " << ans.second << " column\n";
		array.deleteColumn(ans.second);
		array.showArray();
		ans = array.findElem(maxElem);
	}
	return true;
}


bool solveTask3() {
	std::string emailName;
	bool answer = false;
	do {
		std::cout << "\n\tTASK #3\n";
		std::cout << "\nGet your email adress > ";
		std::cout << " !! Domains in your email should not end with a dot !!\n";
		std::cin >> emailName;
		EmailAdress email(emailName);
		if (email.getStatus() == "Invalid")
			std::cout << "Your email is invalid.\n";
		else std::cout << "Your email is valid\n";
		std::cout << "Try again ? (y or n) > ";
		answer = CheckData<int>::getYesNo();
	} while (answer);
	return true;
}



bool solveTask4() {
	bool answer = false, task = true;
	do {
		std::cout << "\n\tTASK #4\n";
		// работа с файлами
		std::string fileName, key;
		int operation, findByField, sortByField;
		bool direction;
		std::vector<Person> found;
		//std::cout << "Get name of file with person data > ";
		//std::cin >> fileName;
		fileName = "Persons.txt";
	//	std::fstream file(fileName,std::ios::out);
		MyBase myBase(fileName);
		myBase.readFromFile();

		std::cout << "\n\t---Data copied from a file 'Person.txt'---\n";

		do{
			std::cout << "\n----------------------------------------------\n";
			std::cout << "What would you like to do?\n";
			std::cout << "1) Sort data base (selected field)\n";
			std::cout << "2) Show item report\n";
			std::cout << "3) Search for an item (selected key)\n";
			std::cout << "4) Writing data to a binary file\n";
			std::cout << "5) Reading a binary file\n";
			std::cout << "6) Quit to main";
			std::cout << "\n----------------------------------------------\n";
			std::cout << "> ";
			operation = CheckData<int>::getDigit(1, 6);
			switch (operation)
			{
			case 1:
				std::cout << "Select the field to sort by ->\n";
				std::cout << "|| 1) Full Name || 2) Gender || 3) Birthdate || 4) INN ||\n> ";
				sortByField = CheckData<int>::getDigit(1, 4);
				std::cout << "Increase sort? (y/n)>\n";
				direction = CheckData<int>::getYesNo();
				switch (sortByField)
				{
				case 1:
					myBase.sortBy(PersonField::FULL_NAME,direction);
					break;
				case 2:
					myBase.sortBy(PersonField::GENDER, direction);
					break;
				case 3:
					myBase.sortBy(PersonField::BIRTHDATE, direction);
					break;
				case 4:
					myBase.sortBy(PersonField::INN, direction);
					break;
				default:
					std::cout << "Not a case\n";
					break;
				}
				break;
			case 2:
				myBase.showData();
				break;
			case 3:
				std::cout << "Select the field to find by ->\n";
				std::cout << "|| 1) Full Name || 2) Gender || 3) Birthdate || 4) INN ||\n> ";
				findByField = CheckData<int>::getDigit(1, 4);
				std::cout << "Enter the key (search request)\n> ";
				std::cin >> key;
				std::cout << "Search has started...\n";
				switch (findByField)
				{
				case 1:
					found = myBase.findBy(PersonField::FULL_NAME, key);
					for (auto& pers : found) {
						pers.showPerson();
					}
					break;
				case 2:
					found = myBase.findBy(PersonField::GENDER, key);
					for (auto& pers : found) {
						pers.showPerson();
					}
					break;
				case 3:
					found = myBase.findBy(PersonField::BIRTHDATE, key);
					for (auto& pers : found) {
						pers.showPerson();
					}
					break;
				case 4:
					found = myBase.findBy(PersonField::INN, key);
					for (auto& pers : found) {
						pers.showPerson();
					}
					break;
				default:
					std::cout << "Not a case\n";
					break;
				}
				std::cout << "Search is over\n";
			case 4:
				myBase.writeToBinFile();
				break;
			case 5:
				myBase.readFromBinFile();
				break;
			case 6:
				task = false;
			default:
				break;
			}
		} while (task);
		std::cout << "Try again? (y or n) > ";
		answer = CheckData<int>::getYesNo();
	} while (answer);
	return true;
}

bool exitFunc() {
	std::cout << "\nExit program...\n";
	return false;
}