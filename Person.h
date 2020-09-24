#ifndef PROFILE
#define PROFILE

#include <string>
#include <iostream>

enum class PersonField {
	FULL_NAME, GENDER, BIRTHDATE, INN
};

struct Person
{
public:
	enum class Gender;
	enum class SortParametr;
	std::string fullName;
	Gender gender;
	std::string birthdate;
	std::string INN;

	enum class Gender {
		MALE, FEMALE
	};
public:
	Person(std::string, std::string, std::string, std::string);
	std::string getINN();
	std::string getFullName();
	std::string getGender();
	std::string getBirthdate();
	std::string getField(PersonField);
	void showPerson();
};

#endif // !PROFILE
