#include "Compare.h"

bool CompData::compare(Person& f, Person& g) {
	switch (field)
	{
	case PersonField::BIRTHDATE:
		return f.getBirthdate() < g.getBirthdate();
	case PersonField::FULL_NAME:
		return f.getFullName()< g.getFullName();
	case PersonField::GENDER:
		return f.getGender()< g.getGender();
	case PersonField::INN:
		return f.getINN()< g.getINN();
	default:
		return false;
	}
}

void  CompData::setDirection(const std::string& dir) {
	if (dir == "") {
		this->direction = "increase";
	}
	if (dir == "rev") {
		this->direction = "decrease";
	}
}

CompData::CompData(const PersonField field, const bool & dir):field(field) {
	if (dir == false) {
		this->direction = "decrease";
	}
}