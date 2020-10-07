#include "Compare.h"

bool CompData::compare(Person& f, Person& g) {
	switch (field)
	{
	case PersonField::BIRTHDATE:
		return f.birthdate < g.birthdate;
	case PersonField::FULL_NAME:
		return f.fullName< g.fullName;
	case PersonField::GENDER:
		return f.gender< g.gender;
	case PersonField::INN:
		return f.INN< g.INN;
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