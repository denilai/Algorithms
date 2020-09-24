#include "MyBase.h"
#include <algorithm>
#include <functional>

MyBase::MyBase(const std::string fileName):
	fileName(fileName),
	iFile(std::ifstream(fileName, std::ios::in)),
	iBinFile(std::ifstream("DataBin.txt", std::ios::in | std::ios::binary)),
	oBinFile(std::ofstream("DataBin.txt", std::ios::out | std::ios::binary | std::ios::trunc)){
	if (!(iFile.good()&&iBinFile.good()&&oBinFile.good()))
		std::cout << "\nERROR. File not open\n";
	else std::cout << "\nOK. File open\n";
}

std::string MyBase::getFileName() {return fileName;}

void MyBase::addPerson(std::string fullName, std::string gender, std::string birthdate, std::string inn) {
	Person a(fullName, gender, birthdate, inn);
	persons.push_back(a);
}

void MyBase::sortBy(PersonField field, bool dir) {
	sort(persons.begin(), persons.end(), CompData(field, dir));
}


void MyBase::showData() {
	std::cout << "List of persons ->" << std::endl;
	for (auto person : persons) {
		person.showPerson();
	}
}

std::vector<Person>MyBase::findBy(PersonField field, std::string arg)
{
	std::vector <Person> found;
	for (auto & person : persons)
		if (person.getField(field) == arg)
			found.push_back(person);
	return found;
}


void MyBase::readFromBinFile() {
	if (iBinFile.is_open()) {
		for (auto person : persons) {
			iBinFile.read((char*)&person.fullName, sizeof(person.fullName));
			iBinFile.read((char*)&person.gender, sizeof(person.gender));
			iBinFile.read((char*)&person.birthdate, sizeof(person.birthdate));
			iBinFile.read((char*)&person.INN, sizeof(person.INN));
		}
		//std::cout << std::endl << sizeof(this) << std::endl;
		iBinFile.close();
	}
	else std::cout << "Error. Binary file is not open\n";
}

void MyBase::writeToBinFile() {
	if (oBinFile.is_open()) {
		for (auto person : persons) {
			oBinFile.write((char*)&person.getFullName(), sizeof(person.getFullName()));
			oBinFile.write((char*)&person.getGender(), sizeof(person.getGender()));
			oBinFile.write((char*)&person.getBirthdate(), sizeof(person.getBirthdate()));
			oBinFile.write((char*)&person.getINN(), sizeof(person.getINN()));
		}
		oBinFile.close();
	}
	else std::cout << "Error. Binary file is not open\n";
}

void MyBase::readFromFile() {
	if (iFile.good()) {
		while (!iFile.eof()) {
			std::string Name1, Name2, Name3, birthdate, inn, gender;
			iFile >> Name1;
			iFile >> Name2;
			iFile >> Name3;
			iFile >> gender;
			iFile >> birthdate;
			iFile >> inn;
			addPerson(Name1 + ' ' + Name2 + ' ' + Name3, gender, birthdate, inn);
		}
	}
}

