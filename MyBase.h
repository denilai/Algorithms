#ifndef MY_BASE
#define MY_BASE

#include "Person.h"
#include "Compare.h"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>




class MyBase {
private:
	
	std::string fileName;
	std::ifstream iFile;
	std::ofstream oBinFile;
	std::ifstream iBinFile;
	std::vector<Person> persons;
public:
	MyBase(const std::string fileName);
	void addPerson(std::string, std::string, std::string, std::string);
	std::string getFileName();
	void readFromFile();
	void sortBy(Person::PersonField, bool dir); // ���������� ������� �� ������ �� ����� ���������
	Person& binarySearch(int first, int last, Person::PersonField field, std::string arg);
	int getCountOfPersons();
	void showData(); // ����� ������ �� �������� �� �����
	std::vector<Person> findBy(Person::PersonField, std::string); // ����� ������� �� �������� ������ �� �����
	void writeToBinFile();
	void readFromBinFile();
};

#endif // !FILE_MASTER
