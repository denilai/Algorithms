#ifndef CHECK_DATA
#define CHECK_DATA

#include <conio.h>
#include <iostream>

template <typename T>
class CheckData {
public:
	static bool getYesNo() {
		char answer = 'd';
		answer = _getch();
		while (!(answer == 'y' || answer == 'n')) {
			std::cout << "Choose 'yes' or 'no'\n> ";
			answer = _getch();
		}
		return (answer == 'y');
	}


	static T getPosDigit() {
		T input;
		input = getDigit();
		while (input <= 0) {
			std::cout << " Oops, that input is nagative. Please try again. \n> ";
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
			std::cout << "Oops, that input is invalid.  Please try again.\n> ";
			std::cin >> input;
		}
		return input;
	}
};

#endif
