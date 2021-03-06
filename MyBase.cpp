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

void MyBase::sortBy(Person::PersonField field, bool dir = true) {
	sort(persons.begin(), persons.end(), CompData(field, dir));
}


void MyBase::showData() {
	std::cout << "List of persons ->" << std::endl;
	for (auto person : persons) {
		person.showPerson();
	}
}

std::vector<Person>MyBase::findBy(Person::PersonField field, std::string arg)
{
	sortBy(field);
	std::vector <Person> found;
	for (auto & person : persons)
		if (person.getField(field) == arg)
			found.push_back(person);
	return found;
}

Person& MyBase::binarySearch(int left, int right , Person::PersonField field, std::string arg) {
	if (persons[left].getField(field) == arg)
		return persons[left];
	if (persons[right].getField(field) == arg)
		return persons[right];
	if (left <= right) {
		int mid = (right + left) / 2;
		if (persons[mid].getField(field) == arg) {
			return persons[mid];
		}
		else
			if (persons[mid].getField(field) > arg)
				return binarySearch(left, mid - 1, field, arg);
			else return binarySearch(mid + 1, right, field, arg);
	}
	throw std::string("ERROR. Search failed\n");
}

int MyBase::getCountOfPersons() {
	return this->persons.size();
}

void MyBase::readFromBinFile() {
	if (iBinFile.is_open()) {
		for (auto& person : persons) {
			iBinFile.read((char*)&person, sizeof(Person));
		}
		//std::cout << std::endl << sizeof(this) << std::endl;
		iBinFile.close();
	}
	else std::cout << "Error. Binary file is not open\n";
}

void MyBase::writeToBinFile() {
	if (oBinFile.is_open()) {
		for (auto & person : persons) {
			oBinFile.write((char*)&person, sizeof(Person));
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

