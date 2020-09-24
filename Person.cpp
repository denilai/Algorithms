#include "Person.h"

Person::Person(std::string name, std::string gender, std::string data, std::string inn) :
	fullName(name), INN(inn), birthdate(data) {
	if (gender == "Male")
		this->gender = Person::Gender::MALE;
	if (gender == "Female")
		this->gender = Person::Gender::FEMALE;
}


std::string Person::getINN() {return INN;}
std::string Person::getFullName() { return fullName; }
std::string Person::getGender() { 
	if (this->gender == Gender::MALE)
		return "Male";
	if (this->gender == Gender::FEMALE)
		return "Female";
}
std::string Person::getBirthdate() { return birthdate; }

std::string Person::getField(PersonField field)
{
	switch (field)
	{
	case PersonField::BIRTHDATE:
		return this->getBirthdate();
	case PersonField::FULL_NAME:
		return this->getFullName();
	case PersonField::GENDER:
		return this->getGender();
	case PersonField::INN:
		return this->getINN();
	default:
		return "This field is not exist\n";
	}
}


void Person::showPerson() {
	std::cout << std::endl;
	std::cout << "Name: " << getFullName() << std::endl;
	std::cout << "Gender: " << getGender() << std::endl;
	std::cout << "Birthdate: " << getBirthdate() << std::endl;
	std::cout << "INN: " << getINN() << std::endl;
	std::cout << std::endl;
}
