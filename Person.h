#ifndef PROFILE
#define PROFILE

#include <string>
#include <iostream>



struct Person
{
public:
	enum class Gender;
	enum class SortParametr;
	std::string fullName;
	Gender gender;
	std::string birthdate;
	std::string INN;

	enum class PersonField {
		FULL_NAME, GENDER, BIRTHDATE, INN
	};

	enum class Gender {
		MALE, FEMALE
	};
	Person(std::string, std::string, std::string, std::string);
	std::string getGender();
	std::string getField(PersonField);
	void showPerson();
};

#endif // !PROFILE
