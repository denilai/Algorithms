#ifndef TH
#define TH
#include <conio.h>
#include <string>
#include <iostream>

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
};


struct Point {
	double x;
	double y;
};



template <typename T>
class CheckData {
public:
	static bool getYesNo() {
		char answer = 'd';
		answer = _getch();
		while (!(answer == 'y' || answer == 'n')) {
			std::cout << "Choose 'yes' or 'no'" << std::endl;
			answer = _getch();
		}
		return (answer == 'y');
	}

	static T getPosDigit() {
		T input;
		input = getDigit();
			while (input < 0) {
				std::cout << " Oops, that input is nagative. Please try again. \n";
				input = getDigit();
			}
			return input;
	}

	static T getDigit() {
		T input;
		std::cin >> input;
		while (std::cin.fail()) {
			std::cin.clear(); // то возвращаем cin в 'обычный' режим работы
			std::cin.ignore(32767, '\n'); // и удаляем значения предыдущего ввода из входного буфера
			std::cout << "Oops, that input is invalid.  Please try again.\n";
			std::cin >> input;
		}
		return input;
	}
};


class TaskSolver {
public:
	static bool task1(double, double, Point&);
};


#endif
